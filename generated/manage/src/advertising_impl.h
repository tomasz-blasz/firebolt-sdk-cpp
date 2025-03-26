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


    class AdvertisingImpl : public IAdvertising, public IModule {

    public:
        AdvertisingImpl() = default;
        AdvertisingImpl(const AdvertisingImpl&) = delete;
        AdvertisingImpl& operator=(const AdvertisingImpl&) = delete;

        ~AdvertisingImpl() override = default;

        // Methods & Events
        // signature callback params: 
        // method result properties : 
        void subscribe( IAdvertising::IOnSkipRestrictionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IAdvertising::IOnSkipRestrictionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         resetIdentifier
         Resets a user's identifier in the ad platform so that the advertising id that apps get will be a new value
         */
        void resetIdentifier( Firebolt::Error *err = nullptr ) override;

        /*
         * setSkipRestriction
         * Set the value for AdPolicy.skipRestriction
         */
        void setSkipRestriction( const SkipRestriction& value, Firebolt::Error *err = nullptr ) override;

        /*
         * Set the value for AdPolicy.skipRestriction
         * 
         */
        SkipRestriction skipRestriction( Firebolt::Error *err = nullptr ) const override;
    };

}//namespace Advertising
}
