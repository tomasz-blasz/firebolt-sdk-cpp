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
#include "jsondata_accessibility.h"
#include "jsondata_localization.h"

#include "accessibility.h"


namespace Firebolt {
namespace Accessibility {


    // Types
    class JsonData_AudioDescriptionSettings: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AudioDescriptionSettings() override = default;
  
    public:
        JsonData_AudioDescriptionSettings()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("enabled"), &Enabled);
        }

        JsonData_AudioDescriptionSettings(const JsonData_AudioDescriptionSettings& other)
        {
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
        }

        JsonData_AudioDescriptionSettings& operator=(const JsonData_AudioDescriptionSettings& other)
        {
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Enabled;
    };

    class AccessibilityImpl : public IAccessibility, public IModule {

    public:
        AccessibilityImpl() = default;
        AccessibilityImpl(const AccessibilityImpl&) = delete;
        AccessibilityImpl& operator=(const AccessibilityImpl&) = delete;

        ~AccessibilityImpl() override = default;

        // Methods & Events
        /*
         * Get the user's preferred audio description settings
         * 
         */
        AudioDescriptionSettings audioDescriptionSettings( Firebolt::Error *err = nullptr ) const override;
        /*
         closedCaptions
         Get the user's preferred closed-captions settings
         */
        ClosedCaptionsSettings closedCaptions( Firebolt::Error *err = nullptr ) const override;

        /*
         * Get the user's preferred closed-captions settings
         * 
         */
        ClosedCaptionsSettings closedCaptionsSettings( Firebolt::Error *err = nullptr ) const override;
        /*
         * The user's preference for a high-contrast UI
         * 
         */
        bool highContrastUI( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IAccessibility::IOnAudioDescriptionSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IAccessibility::IOnAudioDescriptionSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IAccessibility::IOnClosedCaptionsSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IAccessibility::IOnClosedCaptionsSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IAccessibility::IOnHighContrastUIChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IAccessibility::IOnHighContrastUIChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IAccessibility::IOnVoiceGuidanceSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IAccessibility::IOnVoiceGuidanceSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         voiceGuidance
         Get the user's preferred voice guidance settings
         */
        VoiceGuidanceSettings voiceGuidance( Firebolt::Error *err = nullptr ) const override;

        /*
         * Get the user's preferred voice guidance settings
         * 
         */
        VoiceGuidanceSettings voiceGuidanceSettings( Firebolt::Error *err = nullptr ) const override;
    };

}//namespace Accessibility
}
