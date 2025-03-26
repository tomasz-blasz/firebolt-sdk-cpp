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
#include "jsondata_capabilities.h"

#include "capabilities.h"


namespace Firebolt {
namespace Capabilities {


    // Types
    class JsonData_CapabilityOption: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_CapabilityOption() override = default;
  
    public:
        JsonData_CapabilityOption()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("role"), &Role);
        }

        JsonData_CapabilityOption(const JsonData_CapabilityOption& other)
        {
            Add(_T("role"), &Role);
            Role = other.Role;
        }

        JsonData_CapabilityOption& operator=(const JsonData_CapabilityOption& other)
        {
            Add(_T("role"), &Role);
            Role = other.Role;
            return (*this);
        }

    public:
        Firebolt::Capabilities::JsonData_Role Role;
    };

    class CapabilitiesImpl : public ICapabilities, public IModule {

    public:
        CapabilitiesImpl() = default;
        CapabilitiesImpl(const CapabilitiesImpl&) = delete;
        CapabilitiesImpl& operator=(const CapabilitiesImpl&) = delete;

        ~CapabilitiesImpl() override = default;

        // Methods & Events
        /*
         available
         Returns whether a capability is available now.
         */
        bool available( const std::string& capability, Firebolt::Error *err = nullptr ) override;

        /*
         granted
         Returns whether the current App has a user grant for passed capability and role.
         */
        bool granted( const std::string& capability, const std::optional<CapabilityOption>& options, Firebolt::Error *err = nullptr ) override;

        /*
         info
         Returns an array of CapabilityInfo objects for the passed in capabilities.
         */
        std::vector<CapabilityInfo> info( const std::vector<std::string>& capabilities, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( const std::string& capability, ICapabilities::IOnAvailableNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ICapabilities::IOnAvailableNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( const Role& role, const std::string& capability, ICapabilities::IOnGrantedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ICapabilities::IOnGrantedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( const Role& role, const std::string& capability, ICapabilities::IOnRevokedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ICapabilities::IOnRevokedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( const std::string& capability, ICapabilities::IOnUnavailableNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ICapabilities::IOnUnavailableNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         permitted
         Returns whether the current App has permission to the passed capability and role.
         */
        bool permitted( const std::string& capability, const std::optional<CapabilityOption>& options, Firebolt::Error *err = nullptr ) override;

        /*
         request
         Requests grants for all capability/role combinations in the roles array.
         */
        std::vector<CapabilityInfo> request( const std::vector<Permission>& grants, Firebolt::Error *err = nullptr ) override;

        /*
         supported
         Returns whether the platform supports the passed capability.
         */
        bool supported( const std::string& capability, Firebolt::Error *err = nullptr ) override;

    };

}//namespace Capabilities
}
