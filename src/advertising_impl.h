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
#include "jsondata_advertising.h"

#include "advertising.h"


namespace Firebolt {
namespace Advertising {


    using JsonData_AdConfigurationOptionsEnvironment = WPEFramework::Core::JSON::EnumType<AdConfigurationOptionsEnvironment>;

    using JsonData_AdvertisingIdOptionsScopeType = WPEFramework::Core::JSON::EnumType<AdvertisingIdOptionsScopeType>;


    // Types
    class JsonData_AdvertisingIdOptionsScope: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AdvertisingIdOptionsScope() override = default;
  
    public:
        JsonData_AdvertisingIdOptionsScope()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("type"), &Type);
            Add(_T("id"), &Id);
        }

        JsonData_AdvertisingIdOptionsScope(const JsonData_AdvertisingIdOptionsScope& other)
        {
            Add(_T("type"), &Type);
            Type = other.Type;
            Add(_T("id"), &Id);
            Id = other.Id;
        }

        JsonData_AdvertisingIdOptionsScope& operator=(const JsonData_AdvertisingIdOptionsScope& other)
        {
            Add(_T("type"), &Type);
            Type = other.Type;
            Add(_T("id"), &Id);
            Id = other.Id;
            return (*this);
        }

    public:
        Firebolt::Advertising::JsonData_AdvertisingIdOptionsScopeType Type;
        FireboltSDK::JSON::String Id;
    };

    using JsonData_AdFrameworkConfig = WPEFramework::Core::JSON::VariantContainer;

    class JsonData_AdvertisingId: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AdvertisingId() override = default;
  
    public:
        JsonData_AdvertisingId()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("ifa"), &Ifa);
            Add(_T("ifa_type"), &Ifa_type);
            Add(_T("lmt"), &Lmt);
        }

        JsonData_AdvertisingId(const JsonData_AdvertisingId& other)
        {
            Add(_T("ifa"), &Ifa);
            Ifa = other.Ifa;
            Add(_T("ifa_type"), &Ifa_type);
            Ifa_type = other.Ifa_type;
            Add(_T("lmt"), &Lmt);
            Lmt = other.Lmt;
        }

        JsonData_AdvertisingId& operator=(const JsonData_AdvertisingId& other)
        {
            Add(_T("ifa"), &Ifa);
            Ifa = other.Ifa;
            Add(_T("ifa_type"), &Ifa_type);
            Ifa_type = other.Ifa_type;
            Add(_T("lmt"), &Lmt);
            Lmt = other.Lmt;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Ifa;
        FireboltSDK::JSON::String Ifa_type;
        FireboltSDK::JSON::String Lmt;
    };

    using JsonData_DeviceAttributes = WPEFramework::Core::JSON::VariantContainer;

    class JsonData_AdConfigurationOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AdConfigurationOptions() override = default;
  
    public:
        JsonData_AdConfigurationOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("coppa"), &Coppa);
            Add(_T("environment"), &Environment);
            Add(_T("authenticationEntity"), &AuthenticationEntity);
        }

        JsonData_AdConfigurationOptions(const JsonData_AdConfigurationOptions& other)
        {
            Add(_T("coppa"), &Coppa);
            Coppa = other.Coppa;
            Add(_T("environment"), &Environment);
            Environment = other.Environment;
            Add(_T("authenticationEntity"), &AuthenticationEntity);
            AuthenticationEntity = other.AuthenticationEntity;
        }

        JsonData_AdConfigurationOptions& operator=(const JsonData_AdConfigurationOptions& other)
        {
            Add(_T("coppa"), &Coppa);
            Coppa = other.Coppa;
            Add(_T("environment"), &Environment);
            Environment = other.Environment;
            Add(_T("authenticationEntity"), &AuthenticationEntity);
            AuthenticationEntity = other.AuthenticationEntity;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Coppa;
        Firebolt::Advertising::JsonData_AdConfigurationOptionsEnvironment Environment;
        FireboltSDK::JSON::String AuthenticationEntity;
    };

    class JsonData_AdvertisingIdOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AdvertisingIdOptions() override = default;
  
    public:
        JsonData_AdvertisingIdOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("scope"), &Scope);
        }

        JsonData_AdvertisingIdOptions(const JsonData_AdvertisingIdOptions& other)
        {
            Add(_T("scope"), &Scope);
            Scope = other.Scope;
        }

        JsonData_AdvertisingIdOptions& operator=(const JsonData_AdvertisingIdOptions& other)
        {
            Add(_T("scope"), &Scope);
            Scope = other.Scope;
            return (*this);
        }

    public:
        Firebolt::Advertising::JsonData_AdvertisingIdOptionsScope Scope;
    };

    class JsonData_AdPolicy: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AdPolicy() override = default;
  
    public:
        JsonData_AdPolicy()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("skipRestriction"), &SkipRestriction);
            Add(_T("limitAdTracking"), &LimitAdTracking);
        }

        JsonData_AdPolicy(const JsonData_AdPolicy& other)
        {
            Add(_T("skipRestriction"), &SkipRestriction);
            SkipRestriction = other.SkipRestriction;
            Add(_T("limitAdTracking"), &LimitAdTracking);
            LimitAdTracking = other.LimitAdTracking;
        }

        JsonData_AdPolicy& operator=(const JsonData_AdPolicy& other)
        {
            Add(_T("skipRestriction"), &SkipRestriction);
            SkipRestriction = other.SkipRestriction;
            Add(_T("limitAdTracking"), &LimitAdTracking);
            LimitAdTracking = other.LimitAdTracking;
            return (*this);
        }

    public:
        Firebolt::Advertising::JsonData_SkipRestriction SkipRestriction;
        WPEFramework::Core::JSON::Boolean LimitAdTracking;
    };

    class AdvertisingImpl : public IAdvertising, public IModule {

    public:
        AdvertisingImpl() = default;
        AdvertisingImpl(const AdvertisingImpl&) = delete;
        AdvertisingImpl& operator=(const AdvertisingImpl&) = delete;

        ~AdvertisingImpl() override = default;

        // Methods & Events
        /*
         advertisingId
         Get the advertising ID
         */
        AdvertisingId advertisingId( const std::optional<AdvertisingIdOptions>& options, Firebolt::Error *err = nullptr ) override;

        /*
         appBundleId
         Get the App's Bundle ID
         */
        std::string appBundleId( Firebolt::Error *err = nullptr ) const override;

        /*
         config
         Build configuration object for Ad Framework initialization
         */
        AdFrameworkConfig config( const AdConfigurationOptions& options, Firebolt::Error *err = nullptr ) override;

        /*
         deviceAttributes
         Get the device advertising device attributes
         */
        DeviceAttributes deviceAttributes( Firebolt::Error *err = nullptr ) const override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IAdvertising::IOnPolicyChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IAdvertising::IOnPolicyChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         * Get the advertising privacy and playback policy
         * 
         */
        AdPolicy policy( Firebolt::Error *err = nullptr ) const override;
    };

}//namespace Advertising
}
