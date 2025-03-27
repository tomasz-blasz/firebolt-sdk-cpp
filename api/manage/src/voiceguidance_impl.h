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

#include "voiceguidance.h"


namespace Firebolt {
namespace VoiceGuidance {


    class VoiceGuidanceImpl : public IVoiceGuidance, public IModule {

    public:
        VoiceGuidanceImpl() = default;
        VoiceGuidanceImpl(const VoiceGuidanceImpl&) = delete;
        VoiceGuidanceImpl& operator=(const VoiceGuidanceImpl&) = delete;

        ~VoiceGuidanceImpl() override = default;

        // Methods & Events
        /*
         * Whether or not voice-guidance is enabled.
         * 
         */
        bool enabled( Firebolt::Error *err = nullptr ) const override;
        /*
         * The user's preference for whether additional navigation hints should be synthesized.
         * 
         */
        bool navigationHints( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IVoiceGuidance::IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IVoiceGuidance::IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IVoiceGuidance::IOnNavigationHintsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IVoiceGuidance::IOnNavigationHintsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IVoiceGuidance::IOnRateChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IVoiceGuidance::IOnRateChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IVoiceGuidance::IOnSpeedChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IVoiceGuidance::IOnSpeedChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         * The rate at which voice guidance speech will be read back to the user.
         * 
         */
        float rate( Firebolt::Error *err = nullptr ) const override;
        /*
         * setEnabled
         * Whether or not voice-guidance is enabled.
         */
        void setEnabled( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setNavigationHints
         * The user's preference for whether additional navigation hints should be synthesized.
         */
        void setNavigationHints( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setRate
         * The rate at which voice guidance speech will be read back to the user.
         */
        void setRate( const float& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setSpeed
         * The speed at which voice guidance speech will be read back to the user.
         */
        void setSpeed( const float& value, Firebolt::Error *err = nullptr ) override;

        /*
         * The speed at which voice guidance speech will be read back to the user.
         * 
         */
        float speed( Firebolt::Error *err = nullptr ) const override;
    };

}//namespace VoiceGuidance
}
