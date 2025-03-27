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

#include "device_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Device {

    // Methods
    /* name - The human readable name of the device */
    std::string DeviceImpl::name( Firebolt::Error *err ) const
    {
        const string method = _T("device.name");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string value;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            value = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return value;
    }
    /* setName - The human readable name of the device */
    void DeviceImpl::setName( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("device.setName");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* provision - Used by a distributor to push provision info to firebolt. */
    void DeviceImpl::provision( const std::string& accountId, const std::string& deviceId, const std::optional<std::string>& distributorId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant accountIdVariant(accountId);
            jsonParameters.Set(_T("accountId"), accountIdVariant);
            WPEFramework::Core::JSON::Variant deviceIdVariant(deviceId);
            jsonParameters.Set(_T("deviceId"), deviceIdVariant);
            if (distributorId.has_value()) {
                WPEFramework::Core::JSON::Variant distributorIdVariant(distributorId.value());
                jsonParameters.Set(_T("distributorId"), distributorIdVariant);
            }
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("device.provision", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Device.provision is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }


    // Events
    /* onDeviceNameChanged - Get the human readable name of the device */
    static void onDeviceNameChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IDevice::IOnDeviceNameChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnDeviceNameChangedNotification*>(notification));
            notifier.onDeviceNameChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onDeviceNameChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onDeviceNameChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onDeviceNameChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onNameChanged - The human readable name of the device */
    static void onNameChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IDevice::IOnNameChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnNameChangedNotification*>(notification));
            notifier.onNameChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onNameChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onNameChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onNameChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Device
}

