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

#include "account_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Account {

    // Methods
    /* session - Used by a distributor to push Session token to firebolt. */
    void AccountImpl::session( const std::string& token, const int32_t expiresIn, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant tokenVariant(token);
            jsonParameters.Set(_T("token"), tokenVariant);
            WPEFramework::Core::JSON::Variant expiresInVariant(expiresIn);
            jsonParameters.Set(_T("expiresIn"), expiresInVariant);
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("account.session", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Account.session is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }


    // Events

}//namespace Account
}

