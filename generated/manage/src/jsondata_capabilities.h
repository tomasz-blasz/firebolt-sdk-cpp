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
#include "common/capabilities.h"

namespace Firebolt {
namespace Capabilities {

    // Types
    using JsonData_Role = WPEFramework::Core::JSON::EnumType<Role>;

    class JsonData_Permission: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_Permission() override = default;
  
    public:
        JsonData_Permission()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("role"), &Role);
            Add(_T("capability"), &Capability);
        }

        JsonData_Permission(const JsonData_Permission& other)
        {
            Add(_T("role"), &Role);
            Role = other.Role;
            Add(_T("capability"), &Capability);
            Capability = other.Capability;
        }

        JsonData_Permission& operator=(const JsonData_Permission& other)
        {
            Add(_T("role"), &Role);
            Role = other.Role;
            Add(_T("capability"), &Capability);
            Capability = other.Capability;
            return (*this);
        }

    public:
        Firebolt::Capabilities::JsonData_Role Role;
        FireboltSDK::JSON::String Capability;
    };

}
}
