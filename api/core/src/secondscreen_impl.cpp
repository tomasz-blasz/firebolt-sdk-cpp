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

#include "secondscreen_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace SecondScreen {

    // Methods
    /* device - Get the broadcasted id for the device */
    std::string SecondScreenImpl::device( const std::optional<std::string>& type, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::string deviceId;

        JsonObject jsonParameters;
        if (type.has_value()) {
                WPEFramework::Core::JSON::Variant typeVariant(type.value());
                jsonParameters.Set(_T("type"), typeVariant);
            }
        FireboltSDK::JSON::String jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("secondscreen.device", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "SecondScreen.device is successfully invoked");
            deviceId = jsonResult.Value().c_str();
        }

        if (err != nullptr) {
            *err = status;
        }

        return deviceId;
    }

    /* friendlyName - Get the broadcasted friendly name for the device */
    std::string SecondScreenImpl::friendlyName( Firebolt::Error *err ) const
    {
        const string method = _T("secondscreen.friendlyName");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string friendlyName;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            friendlyName = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return friendlyName;
    }

    /* protocols - Get the supported second screen discovery protocols */
    Types::BooleanMap SecondScreenImpl::protocols( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        Types::BooleanMap protocols;

        JsonObject jsonParameters;

        Firebolt::Types::JsonData_BooleanMap jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("secondscreen.protocols", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "SecondScreen.protocols is successfully invoked");
            WPEFramework::Core::JSON::VariantContainer::Iterator variants = jsonResult.Variants(); 
                while (variants.Next()) {
                    std::string key = variants.Label();
                    protocols.emplace(std::piecewise_construct,
                        std::forward_as_tuple(key),
                        std::forward_as_tuple(variants.Current().Boolean()));
                }
    
        }

        if (err != nullptr) {
            *err = status;
        }

        return protocols;
    }


    // Events
    /* onCloseRequest - Listen to the closeRequest event */
    static void onCloseRequestInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::SecondScreen::JsonData_SecondScreenEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::SecondScreen::JsonData_SecondScreenEvent>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            SecondScreenEvent result;

            result.type = proxyResponse->Type;
            if (proxyResponse->Version.IsSet()) {
                result.version = proxyResponse->Version;
            }
            if (proxyResponse->Data.IsSet()) {
                result.data = proxyResponse->Data;
            }

            proxyResponse.Release();

            ISecondScreen::IOnCloseRequestNotification& notifier = *(reinterpret_cast<ISecondScreen::IOnCloseRequestNotification*>(notification));
            notifier.onCloseRequest(result);
        }
    }
    void SecondScreenImpl::subscribe( ISecondScreen::IOnCloseRequestNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("secondscreen.onCloseRequest");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::SecondScreen::JsonData_SecondScreenEvent>(eventName, jsonParameters, onCloseRequestInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void SecondScreenImpl::unsubscribe( ISecondScreen::IOnCloseRequestNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("secondscreen.onCloseRequest"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onFriendlyNameChanged - Get the broadcasted friendly name for the device */
    static void onFriendlyNameChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            ISecondScreen::IOnFriendlyNameChangedNotification& notifier = *(reinterpret_cast<ISecondScreen::IOnFriendlyNameChangedNotification*>(notification));
            notifier.onFriendlyNameChanged(result);
        }
    }
    void SecondScreenImpl::subscribe( ISecondScreen::IOnFriendlyNameChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("secondscreen.onFriendlyNameChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onFriendlyNameChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void SecondScreenImpl::unsubscribe( ISecondScreen::IOnFriendlyNameChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("secondscreen.onFriendlyNameChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onLaunchRequest - Listen to the launchRequest event */
    static void onLaunchRequestInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::SecondScreen::JsonData_SecondScreenEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::SecondScreen::JsonData_SecondScreenEvent>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            SecondScreenEvent result;

            result.type = proxyResponse->Type;
            if (proxyResponse->Version.IsSet()) {
                result.version = proxyResponse->Version;
            }
            if (proxyResponse->Data.IsSet()) {
                result.data = proxyResponse->Data;
            }

            proxyResponse.Release();

            ISecondScreen::IOnLaunchRequestNotification& notifier = *(reinterpret_cast<ISecondScreen::IOnLaunchRequestNotification*>(notification));
            notifier.onLaunchRequest(result);
        }
    }
    void SecondScreenImpl::subscribe( ISecondScreen::IOnLaunchRequestNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("secondscreen.onLaunchRequest");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::SecondScreen::JsonData_SecondScreenEvent>(eventName, jsonParameters, onLaunchRequestInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void SecondScreenImpl::unsubscribe( ISecondScreen::IOnLaunchRequestNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("secondscreen.onLaunchRequest"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace SecondScreen
}

