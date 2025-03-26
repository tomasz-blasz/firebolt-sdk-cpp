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


namespace Firebolt {
namespace VoiceGuidance {



struct IVoiceGuidance {

    virtual ~IVoiceGuidance() = default;

    // Methods & Events
    /*
     * Whether or not voice-guidance is enabled.
     * 
     */
    virtual bool enabled( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The user's preference for whether additional navigation hints should be synthesized.
     * 
     */
    virtual bool navigationHints( Firebolt::Error *err = nullptr ) const = 0;

    /* onEnabledChanged - Whether or not voice-guidance is enabled. */
    struct IOnEnabledChangedNotification {
        virtual void onEnabledChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onNavigationHintsChanged - The user's preference for whether additional navigation hints should be synthesized. */
    struct IOnNavigationHintsChangedNotification {
        virtual void onNavigationHintsChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnNavigationHintsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnNavigationHintsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onRateChanged - The rate at which voice guidance speech will be read back to the user. */
    struct IOnRateChangedNotification {
        virtual void onRateChanged( const float& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnRateChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnRateChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onSpeedChanged - The speed at which voice guidance speech will be read back to the user. */
    struct IOnSpeedChangedNotification {
        virtual void onSpeedChanged( const float& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnSpeedChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnSpeedChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     * The rate at which voice guidance speech will be read back to the user.
     * 
     */
    virtual float rate( Firebolt::Error *err = nullptr ) const = 0;

    /*
     setEnabled
     Whether or not voice-guidance is enabled.
     */
    virtual void setEnabled( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setNavigationHints
     The user's preference for whether additional navigation hints should be synthesized.
     */
    virtual void setNavigationHints( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setRate
     The rate at which voice guidance speech will be read back to the user.
     */
    virtual void setRate( const float& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setSpeed
     The speed at which voice guidance speech will be read back to the user.
     */
    virtual void setSpeed( const float& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     * The speed at which voice guidance speech will be read back to the user.
     * 
     */
    virtual float speed( Firebolt::Error *err = nullptr ) const = 0;

};

} //namespace VoiceGuidance
}
