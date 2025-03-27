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
#include "jsondata_localization.h"

#include "localization.h"


namespace Firebolt {
namespace Localization {


    // Types
        using JsonData_LatLon = WPEFramework::Core::JSON::ArrayType<WPEFramework::Core::JSON::Float>;
    using JsonData_Info = WPEFramework::Core::JSON::VariantContainer;
    class LocalizationImpl : public ILocalization, public IModule {

    public:
        LocalizationImpl() = default;
        LocalizationImpl(const LocalizationImpl&) = delete;
        LocalizationImpl& operator=(const LocalizationImpl&) = delete;

        ~LocalizationImpl() override = default;

        // Methods & Events
        /*
         additionalInfo
         Get any platform-specific localization information, in an Map<string, string>
         */
        Info additionalInfo( Firebolt::Error *err = nullptr ) const override;

        /*
         * Get the ISO 3166-1 alpha-2 code for the country device is located in
         * 
         */
        std::string countryCode( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the ISO 639 1/2 code for the preferred language
         * 
         */
        std::string language( Firebolt::Error *err = nullptr ) const override;
        /*
         latlon
         Get the approximate latitude and longitude coordinates of the device location
         */
        LatLon latlon( Firebolt::Error *err = nullptr ) const override;

        /*
         * Get the *full* BCP 47 code, including script, region, variant, etc., for the preferred langauage/locale
         * 
         */
        std::string locale( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the locality/city the device is located in
         * 
         */
        std::string locality( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( ILocalization::IOnCountryCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILocalization::IOnCountryCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILocalization::IOnLanguageChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILocalization::IOnLanguageChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILocalization::IOnLocaleChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILocalization::IOnLocaleChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILocalization::IOnLocalityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILocalization::IOnLocalityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILocalization::IOnPostalCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILocalization::IOnPostalCodeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILocalization::IOnPreferredAudioLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILocalization::IOnPreferredAudioLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         * Get the postal code the device is located in
         * 
         */
        std::string postalCode( Firebolt::Error *err = nullptr ) const override;
        /*
         * A prioritized list of ISO 639 1/2 codes for the preferred audio languages on this device.
         * 
         */
        std::vector<std::string> preferredAudioLanguages( Firebolt::Error *err = nullptr ) const override;
    };

}//namespace Localization
}
