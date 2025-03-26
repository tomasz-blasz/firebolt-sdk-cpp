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

#pragma once

#include "FireboltSDK.h"
#include "IModule.h"

#include "metrics.h"


namespace Firebolt {
namespace Metrics {


    // Types
    /* anyOf schema shape is not supported right now */
    using JsonData_EventObject = WPEFramework::Core::JSON::VariantContainer;
    class MetricsImpl : public IMetrics, public IModule {

    public:
        MetricsImpl() = default;
        MetricsImpl(const MetricsImpl&) = delete;
        MetricsImpl& operator=(const MetricsImpl&) = delete;

        ~MetricsImpl() override = default;

        // Methods & Events
        /*
         event
         Inform the platform of 1st party distributor metrics.
         */
        void event( const std::string& schema, const EventObject& data, Firebolt::Error *err = nullptr ) override;

    };

}//namespace Metrics
}
