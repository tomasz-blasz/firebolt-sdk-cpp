/*
 * Copyright 2023 Comcast Cable Communications Management, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "acknowledgechallenge_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace AcknowledgeChallenge {

    // Will add PROVIDER_CLASSES templates in another PR
    // Static for now
    static std::string AcknowledgeChallengeSessionInnerCallback(void* provider, void* jsonRequest) {
        WPEFramework::Core::ProxyType<JsonData_AcknowledgeChallengeProviderRequest>& proxyRequest = *(reinterpret_cast<WPEFramework::Core::ProxyType<JsonData_AcknowledgeChallengeProviderRequest>*>(jsonRequest));

        ASSERT(proxyRequest.IsValid() == true);

        if (!proxyRequest.IsValid()) {
            return R"({"error": { "code": )" + std::to_string(static_cast<int32_t>(Firebolt::Error::InvalidParams)) + R"(, "message": "Invalid Parameters"}, "result": ""})";
        }
        AcknowledgeChallengeParameters parameters;

        parameters.capability = (*proxyRequest).Parameters.Capability;
        parameters.requestor.id = (*proxyRequest).Parameters.Requestor.Id;
        parameters.requestor.name = (*proxyRequest).Parameters.Requestor.Name;

        proxyRequest.Release();

        IAcknowledgeChallengeProvider& acknowledgeChallengeProvider = *(reinterpret_cast<IAcknowledgeChallengeProvider*>(provider));
        GrantResult result = acknowledgeChallengeProvider.challenge(parameters);
        return R"({ "result": {"granted": ")" + std::string(result.granted ? "true" : "false") + R"("}})";
    }

    void AcknowledgeChallengeImpl::provide(IAcknowledgeChallengeProvider& provider) {
        string eventName;
        Firebolt::Error status = Firebolt::Error::None;
        JsonObject jsonParameters;

        eventName = _T("acknowledgeChallenge.onRequestChallenge");
        status = FireboltSDK::Gateway::Instance().RegisterProviderInterface<JsonData_AcknowledgeChallengeProviderRequest>(eventName, jsonParameters, AcknowledgeChallengeSessionInnerCallback, reinterpret_cast<void*>(&provider));
        if (status != Firebolt::Error::None) {
            FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in %s subscribe = %d", eventName.c_str(), status);
        }
    }

    // Events

}//namespace AcknowledgeChallenge
}


