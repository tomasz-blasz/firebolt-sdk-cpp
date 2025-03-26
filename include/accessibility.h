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
#include "common/accessibility.h"
#include "common/localization.h"


namespace Firebolt {
namespace Accessibility {


// Types
struct AudioDescriptionSettings {
    bool enabled;
};


struct IAccessibility {

    virtual ~IAccessibility() = default;

    // Methods & Events
    /*
     * Get the user's preferred audio description settings
     * 
     */
    virtual AudioDescriptionSettings audioDescriptionSettings( Firebolt::Error *err = nullptr ) const = 0;

    /*
     closedCaptions
     Get the user's preferred closed-captions settings
      * @deprecated since version 0.6.0
     */
    virtual ClosedCaptionsSettings closedCaptions( Firebolt::Error *err = nullptr ) const = 0;
    /*
     * Get the user's preferred closed-captions settings
     * 
     */
    virtual ClosedCaptionsSettings closedCaptionsSettings( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The user's preference for a high-contrast UI
     * 
     */
    virtual bool highContrastUI( Firebolt::Error *err = nullptr ) const = 0;

    /* onAudioDescriptionSettingsChanged - Get the user's preferred audio description settings */
    struct IOnAudioDescriptionSettingsChangedNotification {
        virtual void onAudioDescriptionSettingsChanged( const AudioDescriptionSettings& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAudioDescriptionSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAudioDescriptionSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onClosedCaptionsSettingsChanged - Get the user's preferred closed-captions settings */
    struct IOnClosedCaptionsSettingsChangedNotification {
        virtual void onClosedCaptionsSettingsChanged( const ClosedCaptionsSettings& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnClosedCaptionsSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnClosedCaptionsSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onHighContrastUIChanged - The user's preference for a high-contrast UI */
    struct IOnHighContrastUIChangedNotification {
        virtual void onHighContrastUIChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnHighContrastUIChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnHighContrastUIChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onVoiceGuidanceSettingsChanged - Get the user's preferred voice guidance settings */
    struct IOnVoiceGuidanceSettingsChangedNotification {
        virtual void onVoiceGuidanceSettingsChanged( const VoiceGuidanceSettings& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnVoiceGuidanceSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnVoiceGuidanceSettingsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     voiceGuidance
     Get the user's preferred voice guidance settings
      * @deprecated since version 0.6.0
     */
    virtual VoiceGuidanceSettings voiceGuidance( Firebolt::Error *err = nullptr ) const = 0;
    /*
     * Get the user's preferred voice guidance settings
     * 
     */
    virtual VoiceGuidanceSettings voiceGuidanceSettings( Firebolt::Error *err = nullptr ) const = 0;

};

} //namespace Accessibility
}
