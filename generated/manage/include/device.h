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
namespace Device {



struct IDevice {

    virtual ~IDevice() = default;

    // Methods & Events
    /*
     * The human readable name of the device
     * 
     */
    virtual std::string name( Firebolt::Error *err = nullptr ) const = 0;

    /* onDeviceNameChanged - Get the human readable name of the device */
    struct IOnDeviceNameChangedNotification {
        virtual void onDeviceNameChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onNameChanged - The human readable name of the device */
    struct IOnNameChangedNotification {
        virtual void onNameChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     provision
     Used by a distributor to push provision info to firebolt.
     
     */
    virtual void provision( const std::string& accountId, const std::string& deviceId, const std::optional<std::string>& distributorId, Firebolt::Error *err = nullptr ) = 0;
    /*
     setName
     The human readable name of the device
     */
    virtual void setName( const std::string& value, Firebolt::Error *err = nullptr ) = 0;

};

} //namespace Device
}
