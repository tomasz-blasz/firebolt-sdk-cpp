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
#include "common/types.h"
#include "common/secondscreen.h"


namespace Firebolt {
namespace SecondScreen {



struct ISecondScreen {

    virtual ~ISecondScreen() = default;

    // Methods & Events
    /*
     device
     Get the broadcasted id for the device
     
     */
    virtual std::string device( const std::optional<std::string>& type, Firebolt::Error *err = nullptr ) = 0;
    /*
     * Get the broadcasted friendly name for the device
     * 
     */
    virtual std::string friendlyName( Firebolt::Error *err = nullptr ) const = 0;

    /* onCloseRequest - Listen to the closeRequest event */
    struct IOnCloseRequestNotification {
        virtual void onCloseRequest( const SecondScreenEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnCloseRequestNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnCloseRequestNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onFriendlyNameChanged - Get the broadcasted friendly name for the device */
    struct IOnFriendlyNameChangedNotification {
        virtual void onFriendlyNameChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnFriendlyNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnFriendlyNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onLaunchRequest - Listen to the launchRequest event */
    struct IOnLaunchRequestNotification {
        virtual void onLaunchRequest( const SecondScreenEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnLaunchRequestNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnLaunchRequestNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     protocols
     Get the supported second screen discovery protocols
     
     */
    virtual Types::BooleanMap protocols( Firebolt::Error *err = nullptr ) const = 0;
};

} //namespace SecondScreen
}
