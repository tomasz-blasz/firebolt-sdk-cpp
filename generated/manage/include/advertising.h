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



struct IAdvertising {

    virtual ~IAdvertising() = default;

    // Methods & Events
    /* onSkipRestrictionChanged - Set the value for AdPolicy.skipRestriction */
    struct IOnSkipRestrictionChangedNotification {
        virtual void onSkipRestrictionChanged( const SkipRestriction& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnSkipRestrictionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnSkipRestrictionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     resetIdentifier
     Resets a user's identifier in the ad platform so that the advertising id that apps get will be a new value
     
     */
    virtual void resetIdentifier( Firebolt::Error *err = nullptr ) = 0;
    /*
     setSkipRestriction
     Set the value for AdPolicy.skipRestriction
     */
    virtual void setSkipRestriction( const SkipRestriction& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     * Set the value for AdPolicy.skipRestriction
     * 
     */
    virtual SkipRestriction skipRestriction( Firebolt::Error *err = nullptr ) const = 0;

};

} //namespace Advertising
}
