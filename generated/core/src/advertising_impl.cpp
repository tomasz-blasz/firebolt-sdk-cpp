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

#include "advertising_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Advertising {

    // Methods
    /* advertisingId - Get the advertising ID */
    AdvertisingId AdvertisingImpl::advertisingId( const std::optional<AdvertisingIdOptions>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        AdvertisingId advertisingId;

        JsonObject jsonParameters;
        if (options.has_value()) {
                auto element = options.value();
                JsonData_AdvertisingIdOptions optionsContainer;
                {
                    optionsContainer.Scope.Type = element.scope.value().type;
                    optionsContainer.Scope.Id = element.scope.value().id;
                }
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        Firebolt::Advertising::JsonData_AdvertisingId jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("advertising.advertisingId", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Advertising.advertisingId is successfully invoked");
            AdvertisingId advertisingIdResult;
                advertisingIdResult.ifa = jsonResult.Ifa.Value();
                if (jsonResult.Ifa_type.IsSet()) {
                    advertisingIdResult.ifa_type = jsonResult.Ifa_type.Value();
                }
                if (jsonResult.Lmt.IsSet()) {
                    advertisingIdResult.lmt = jsonResult.Lmt.Value();
                }
                advertisingId = advertisingIdResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return advertisingId;
    }

    /* appBundleId - Get the App's Bundle ID */
    std::string AdvertisingImpl::appBundleId( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::string appBundleId;

        JsonObject jsonParameters;

        FireboltSDK::JSON::String jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("advertising.appBundleId", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Advertising.appBundleId is successfully invoked");
            appBundleId = jsonResult.Value().c_str();
        }

        if (err != nullptr) {
            *err = status;
        }

        return appBundleId;
    }

    /* config - Build configuration object for Ad Framework initialization */
    AdFrameworkConfig AdvertisingImpl::config( const AdConfigurationOptions& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        AdFrameworkConfig adFrameworkConfig;

        JsonObject jsonParameters;
        auto element = options;
            JsonData_AdConfigurationOptions optionsContainer;
            {
                if (element.coppa.has_value()) {
                    optionsContainer.Coppa = element.coppa.value();
                }
                if (element.environment.has_value()) {
                    optionsContainer.Environment = element.environment.value();
                }
                if (element.authenticationEntity.has_value()) {
                    optionsContainer.AuthenticationEntity = element.authenticationEntity.value();
                }
            }
            string optionsStr;
            optionsContainer.ToString(optionsStr);
            WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
            WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
            jsonParameters.Set(_T("options"), optionsVariant);
        Firebolt::Advertising::JsonData_AdFrameworkConfig jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("advertising.config", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Advertising.config is successfully invoked");
            std::string resultStr;
                jsonResult.ToString(resultStr);
                adFrameworkConfig = resultStr;
        }

        if (err != nullptr) {
            *err = status;
        }

        return adFrameworkConfig;
    }

    /* deviceAttributes - Get the device advertising device attributes */
    DeviceAttributes AdvertisingImpl::deviceAttributes( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        DeviceAttributes deviceAttributes;

        JsonObject jsonParameters;

        Firebolt::Advertising::JsonData_DeviceAttributes jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("advertising.deviceAttributes", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Advertising.deviceAttributes is successfully invoked");
            std::string resultStr;
                jsonResult.ToString(resultStr);
                deviceAttributes = resultStr;
        }

        if (err != nullptr) {
            *err = status;
        }

        return deviceAttributes;
    }

    /* policy - Get the advertising privacy and playback policy */
    AdPolicy AdvertisingImpl::policy( Firebolt::Error *err ) const
    {
        const string method = _T("advertising.policy");
        
        
        Firebolt::Advertising::JsonData_AdPolicy jsonResult;
        AdPolicy adPolicy;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            AdPolicy adPolicyResult;
            if (jsonResult.SkipRestriction.IsSet()) {
                adPolicyResult.skipRestriction = jsonResult.SkipRestriction.Value();
            }
            if (jsonResult.LimitAdTracking.IsSet()) {
                adPolicyResult.limitAdTracking = jsonResult.LimitAdTracking.Value();
            }
            adPolicy = adPolicyResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return adPolicy;
    }


    // Events
    /* onPolicyChanged - Get the advertising privacy and playback policy */
    static void onPolicyChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Advertising::JsonData_AdPolicy>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Advertising::JsonData_AdPolicy>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            AdPolicy result;

            if (proxyResponse->SkipRestriction.IsSet()) {
                result.skipRestriction = proxyResponse->SkipRestriction;
            }
            if (proxyResponse->LimitAdTracking.IsSet()) {
                result.limitAdTracking = proxyResponse->LimitAdTracking;
            }

            proxyResponse.Release();

            IAdvertising::IOnPolicyChangedNotification& notifier = *(reinterpret_cast<IAdvertising::IOnPolicyChangedNotification*>(notification));
            notifier.onPolicyChanged(result);
        }
    }
    void AdvertisingImpl::subscribe( IAdvertising::IOnPolicyChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("advertising.onPolicyChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Advertising::JsonData_AdPolicy>(eventName, jsonParameters, onPolicyChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void AdvertisingImpl::unsubscribe( IAdvertising::IOnPolicyChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("advertising.onPolicyChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Advertising
}


namespace WPEFramework {

    /* AdConfigurationOptionsEnvironment Whether the app is running in a production or test mode. */
    ENUM_CONVERSION_BEGIN(Firebolt::Advertising::AdConfigurationOptionsEnvironment)
        { Firebolt::Advertising::AdConfigurationOptionsEnvironment::PROD, _T("prod") },
        { Firebolt::Advertising::AdConfigurationOptionsEnvironment::TEST, _T("test") },
    ENUM_CONVERSION_END(Firebolt::Advertising::AdConfigurationOptionsEnvironment)

    /* AdvertisingIdOptionsScopeType The scope type, which will determine where to show advertisement */
    ENUM_CONVERSION_BEGIN(Firebolt::Advertising::AdvertisingIdOptionsScopeType)
        { Firebolt::Advertising::AdvertisingIdOptionsScopeType::BROWSE, _T("browse") },
        { Firebolt::Advertising::AdvertisingIdOptionsScopeType::CONTENT, _T("content") },
    ENUM_CONVERSION_END(Firebolt::Advertising::AdvertisingIdOptionsScopeType)

}
