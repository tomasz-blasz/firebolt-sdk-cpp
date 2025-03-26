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
#include "common/capabilities.h"


namespace Firebolt {
namespace Capabilities {


// Types
struct CapabilityOption {
    std::optional<Role> role;
};


struct ICapabilities {

    virtual ~ICapabilities() = default;

    // Methods & Events
    /*
     available
     Returns whether a capability is available now.
     
     */
    virtual bool available( const std::string& capability, Firebolt::Error *err = nullptr ) = 0;
    /*
     granted
     Returns whether the current App has a user grant for passed capability and role.
     
     */
    virtual bool granted( const std::string& capability, const std::optional<CapabilityOption>& options, Firebolt::Error *err = nullptr ) = 0;
    /*
     info
     Returns an array of CapabilityInfo objects for the passed in capabilities.
     
     */
    virtual std::vector<CapabilityInfo> info( const std::vector<std::string>& capabilities, Firebolt::Error *err = nullptr ) = 0;
    /* onAvailable - Listens for all App permitted capabilities to become available. */
    struct IOnAvailableNotification {
        virtual void onAvailable( const CapabilityInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( const std::string& capability, IOnAvailableNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAvailableNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onGranted - Listens for all App permitted capabilities to become granted. */
    struct IOnGrantedNotification {
        virtual void onGranted( const CapabilityInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( const Role& role, const std::string& capability, IOnGrantedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnGrantedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onRevoked - Listens for all App permitted capabilities to become revoked. */
    struct IOnRevokedNotification {
        virtual void onRevoked( const CapabilityInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( const Role& role, const std::string& capability, IOnRevokedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnRevokedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onUnavailable - Listens for all App permitted capabilities to become unavailable. */
    struct IOnUnavailableNotification {
        virtual void onUnavailable( const CapabilityInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( const std::string& capability, IOnUnavailableNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnUnavailableNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     permitted
     Returns whether the current App has permission to the passed capability and role.
     
     */
    virtual bool permitted( const std::string& capability, const std::optional<CapabilityOption>& options, Firebolt::Error *err = nullptr ) = 0;
    /*
     request
     Requests grants for all capability/role combinations in the roles array.
     
     */
    virtual std::vector<CapabilityInfo> request( const std::vector<Permission>& grants, Firebolt::Error *err = nullptr ) = 0;
    /*
     supported
     Returns whether the platform supports the passed capability.
     
     */
    virtual bool supported( const std::string& capability, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace Capabilities
}
