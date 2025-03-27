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

#include "error.h"


namespace Firebolt {
namespace Metrics {


// Types
/* anyOf schema shape is not supported right now */

using EventObject = std::unordered_map<std::string, std::string>;


struct IMetrics {

    virtual ~IMetrics() = default;

    // Methods & Events
    /*
     event
     Inform the platform of 1st party distributor metrics.
     
     */
    virtual void event( const std::string& schema, const EventObject& data, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace Metrics
}
