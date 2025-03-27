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

#include "device.h"


namespace Firebolt {
namespace Device {


    class DeviceImpl : public IDevice, public IModule {

    public:
        DeviceImpl() = default;
        DeviceImpl(const DeviceImpl&) = delete;
        DeviceImpl& operator=(const DeviceImpl&) = delete;

        ~DeviceImpl() override = default;

        // Methods & Events
        /*
         * The human readable name of the device
         * 
         */
        std::string name( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         provision
         Used by a distributor to push provision info to firebolt.
         */
        void provision( const std::string& accountId, const std::string& deviceId, const std::optional<std::string>& distributorId, Firebolt::Error *err = nullptr ) override;

        /*
         * setName
         * The human readable name of the device
         */
        void setName( const std::string& value, Firebolt::Error *err = nullptr ) override;

    };

}//namespace Device
}
