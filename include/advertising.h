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
#include "common/advertising.h"


namespace Firebolt {
namespace Advertising {


// Enums
/* AdConfigurationOptionsEnvironment Whether the app is running in a production or test mode. */
enum class AdConfigurationOptionsEnvironment {
    PROD,
    TEST
};

/* AdvertisingIdOptionsScopeType The scope type, which will determine where to show advertisement */
enum class AdvertisingIdOptionsScopeType {
    BROWSE,
    CONTENT
};


// Types
struct AdvertisingIdOptionsScope {
    AdvertisingIdOptionsScopeType type;
    std::string id;
};

/* AdFrameworkConfig */
using AdFrameworkConfig = std::string;

struct AdvertisingId {
    std::string ifa;
    std::optional<std::string> ifa_type;
    std::optional<std::string> lmt;
};

/* DeviceAttributes */
using DeviceAttributes = std::string;

struct AdConfigurationOptions {
    std::optional<bool> coppa;
    std::optional<AdConfigurationOptionsEnvironment> environment;
    std::optional<std::string> authenticationEntity;
};

struct AdvertisingIdOptions {
    std::optional<AdvertisingIdOptionsScope> scope;
};

struct AdPolicy {
    std::optional<SkipRestriction> skipRestriction;
    std::optional<bool> limitAdTracking;
};


struct IAdvertising {

    virtual ~IAdvertising() = default;

    // Methods & Events
    /*
     advertisingId
     Get the advertising ID
     
     */
    virtual AdvertisingId advertisingId( const std::optional<AdvertisingIdOptions>& options, Firebolt::Error *err = nullptr ) = 0;
    /*
     appBundleId
     Get the App's Bundle ID
     
     */
    virtual std::string appBundleId( Firebolt::Error *err = nullptr ) const = 0;
    /*
     config
     Build configuration object for Ad Framework initialization
     
     */
    virtual AdFrameworkConfig config( const AdConfigurationOptions& options, Firebolt::Error *err = nullptr ) = 0;
    /*
     deviceAttributes
     Get the device advertising device attributes
     
     */
    virtual DeviceAttributes deviceAttributes( Firebolt::Error *err = nullptr ) const = 0;
    /* onPolicyChanged - Get the advertising privacy and playback policy */
    struct IOnPolicyChangedNotification {
        virtual void onPolicyChanged( const AdPolicy& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnPolicyChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnPolicyChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     * Get the advertising privacy and playback policy
     * 
     */
    virtual AdPolicy policy( Firebolt::Error *err = nullptr ) const = 0;

};

} //namespace Advertising
}
