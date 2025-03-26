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
#include "common/localization.h"


namespace Firebolt {
namespace Localization {


// Types
/* LatLon */
using LatLon = std::pair<float, float>;

using Info = std::unordered_map<std::string, std::string>;


struct ILocalization {

    virtual ~ILocalization() = default;

    // Methods & Events
    /*
     additionalInfo
     Get any platform-specific localization information, in an Map<string, string>
     
     */
    virtual Info additionalInfo( Firebolt::Error *err = nullptr ) const = 0;
    /*
     * Get the ISO 3166-1 alpha-2 code for the country device is located in
     * 
     */
    virtual std::string countryCode( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the ISO 639 1/2 code for the preferred language
     * 
     */
    virtual std::string language( Firebolt::Error *err = nullptr ) const = 0;

    /*
     latlon
     Get the approximate latitude and longitude coordinates of the device location
     
     */
    virtual LatLon latlon( Firebolt::Error *err = nullptr ) const = 0;
    /*
     * Get the *full* BCP 47 code, including script, region, variant, etc., for the preferred langauage/locale
     * 
     */
    virtual std::string locale( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the locality/city the device is located in
     * 
     */
    virtual std::string locality( Firebolt::Error *err = nullptr ) const = 0;

    /* onCountryCodeChanged - Get the ISO 3166-1 alpha-2 code for the country device is located in */
    struct IOnCountryCodeChangedNotification {
        virtual void onCountryCodeChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnCountryCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnCountryCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onLanguageChanged - Get the ISO 639 1/2 code for the preferred language */
    struct IOnLanguageChangedNotification {
        virtual void onLanguageChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnLanguageChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnLanguageChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onLocaleChanged - Get the *full* BCP 47 code, including script, region, variant, etc., for the preferred langauage/locale */
    struct IOnLocaleChangedNotification {
        virtual void onLocaleChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnLocaleChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnLocaleChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onLocalityChanged - Get the locality/city the device is located in */
    struct IOnLocalityChangedNotification {
        virtual void onLocalityChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnLocalityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnLocalityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onPostalCodeChanged - Get the postal code the device is located in */
    struct IOnPostalCodeChangedNotification {
        virtual void onPostalCodeChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnPostalCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnPostalCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onPreferredAudioLanguagesChanged - A prioritized list of ISO 639 1/2 codes for the preferred audio languages on this device. */
    struct IOnPreferredAudioLanguagesChangedNotification {
        virtual void onPreferredAudioLanguagesChanged( const std::vector<std::string>& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnPreferredAudioLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnPreferredAudioLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     * Get the postal code the device is located in
     * 
     */
    virtual std::string postalCode( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * A prioritized list of ISO 639 1/2 codes for the preferred audio languages on this device.
     * 
     */
    virtual std::vector<std::string> preferredAudioLanguages( Firebolt::Error *err = nullptr ) const = 0;

};

} //namespace Localization
}
