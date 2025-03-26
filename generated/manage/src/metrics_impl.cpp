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

#include "metrics_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Metrics {

    // Methods
    /* event - Inform the platform of 1st party distributor metrics. */
    void MetricsImpl::event( const std::string& schema, const EventObject& data, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant schemaVariant(schema);
            jsonParameters.Set(_T("schema"), schemaVariant);
            EventObject map;
            map = data;
            WPEFramework::Core::JSON::Variant dataVariant;
            for (auto element: map) {
                WPEFramework::Core::JSON::Variant jsonElement = element.second;
                WPEFramework::Core::JSON::VariantContainer jsonContainer;
                jsonContainer.Set(element.first.c_str(), jsonElement);
                dataVariant = jsonContainer;
            }
            jsonParameters.Set(_T("data"), dataVariant);
    
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.event", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.event is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }


    // Events

}//namespace Metrics
}

