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

    using JsonData_DenyReason = WPEFramework::Core::JSON::EnumType<DenyReason>;

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

    class JsonData_CapPermissionStatus: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_CapPermissionStatus() override = default;
  
    public:
        JsonData_CapPermissionStatus()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("permitted"), &Permitted);
            Add(_T("granted"), &Granted);
        }

        JsonData_CapPermissionStatus(const JsonData_CapPermissionStatus& other)
        {
            Add(_T("permitted"), &Permitted);
            Permitted = other.Permitted;
            Add(_T("granted"), &Granted);
            Granted = other.Granted;
        }

        JsonData_CapPermissionStatus& operator=(const JsonData_CapPermissionStatus& other)
        {
            Add(_T("permitted"), &Permitted);
            Permitted = other.Permitted;
            Add(_T("granted"), &Granted);
            Granted = other.Granted;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Permitted;
        WPEFramework::Core::JSON::Boolean Granted;
    };

    class JsonData_CapabilityInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_CapabilityInfo() override = default;
  
    public:
        JsonData_CapabilityInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("capability"), &Capability);
            Add(_T("supported"), &Supported);
            Add(_T("available"), &Available);
            Add(_T("use"), &Use);
            Add(_T("manage"), &Manage);
            Add(_T("provide"), &Provide);
            Add(_T("details"), &Details);
        }

        JsonData_CapabilityInfo(const JsonData_CapabilityInfo& other)
        {
            Add(_T("capability"), &Capability);
            Capability = other.Capability;
            Add(_T("supported"), &Supported);
            Supported = other.Supported;
            Add(_T("available"), &Available);
            Available = other.Available;
            Add(_T("use"), &Use);
            Use = other.Use;
            Add(_T("manage"), &Manage);
            Manage = other.Manage;
            Add(_T("provide"), &Provide);
            Provide = other.Provide;
            Add(_T("details"), &Details);
            Details = other.Details;
        }

        JsonData_CapabilityInfo& operator=(const JsonData_CapabilityInfo& other)
        {
            Add(_T("capability"), &Capability);
            Capability = other.Capability;
            Add(_T("supported"), &Supported);
            Supported = other.Supported;
            Add(_T("available"), &Available);
            Available = other.Available;
            Add(_T("use"), &Use);
            Use = other.Use;
            Add(_T("manage"), &Manage);
            Manage = other.Manage;
            Add(_T("provide"), &Provide);
            Provide = other.Provide;
            Add(_T("details"), &Details);
            Details = other.Details;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Capability;
        WPEFramework::Core::JSON::Boolean Supported;
        WPEFramework::Core::JSON::Boolean Available;
        Firebolt::Capabilities::JsonData_CapPermissionStatus Use;
        Firebolt::Capabilities::JsonData_CapPermissionStatus Manage;
        Firebolt::Capabilities::JsonData_CapPermissionStatus Provide;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Capabilities::JsonData_DenyReason> Details;
    };

}
}
