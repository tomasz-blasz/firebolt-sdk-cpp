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

#include "audiodescriptions.h"


namespace Firebolt {
namespace AudioDescriptions {


    class AudioDescriptionsImpl : public IAudioDescriptions, public IModule {

    public:
        AudioDescriptionsImpl() = default;
        AudioDescriptionsImpl(const AudioDescriptionsImpl&) = delete;
        AudioDescriptionsImpl& operator=(const AudioDescriptionsImpl&) = delete;

        ~AudioDescriptionsImpl() override = default;

        // Methods & Events
        /*
         * Whether or not audio-descriptions are enabled.
         * 
         */
        bool enabled( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IAudioDescriptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IAudioDescriptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         * setEnabled
         * Whether or not audio-descriptions are enabled.
         */
        void setEnabled( const bool value, Firebolt::Error *err = nullptr ) override;

    };

}//namespace AudioDescriptions
}
