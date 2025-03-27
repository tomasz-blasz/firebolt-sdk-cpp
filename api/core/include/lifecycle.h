/* Copyright 2023 Comcast Cable Communications Management, LLC
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
#include <string>
#include "common/lifecycle.h"

namespace Firebolt {
namespace Lifecycle {


// Enums
/* LifecycleEventSource The source of the lifecycle change. */
enum class LifecycleEventSource {
    VOICE,
    REMOTE
};



// Types
struct LifecycleEvent {
    LifecycleState state;
    LifecycleState previous;
    std::optional<LifecycleEventSource> source;
};




struct ILifecycle {

    virtual ~ILifecycle() = default;
    virtual void ready(Firebolt::Error *err = nullptr) = 0;
    virtual void finished(Firebolt::Error *err = nullptr) = 0;
    virtual std::string state(Firebolt::Error *err = nullptr) = 0;

    // Methods & Events
    /*
     close
     Request that the platform move your app out of focus
     
     */
    virtual void close( const CloseReason& reason, Firebolt::Error *err = nullptr ) = 0;
    /* onBackground - Listen to the background event */
    struct IOnBackgroundNotification {
        virtual void onBackground( const LifecycleEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnBackgroundNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnBackgroundNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onForeground - Listen to the foreground event */
    struct IOnForegroundNotification {
        virtual void onForeground( const LifecycleEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnForegroundNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnForegroundNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onInactive - Listen to the inactive event */
    struct IOnInactiveNotification {
        virtual void onInactive( const LifecycleEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnInactiveNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnInactiveNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onSuspended - Listen to the suspended event */
    struct IOnSuspendedNotification {
        virtual void onSuspended( const LifecycleEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnSuspendedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnSuspendedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onUnloading - Listen to the unloading event */
    struct IOnUnloadingNotification {
        virtual void onUnloading( const LifecycleEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnUnloadingNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnUnloadingNotification& notification, Firebolt::Error *err = nullptr ) = 0;

};

// Template for mapping enums to strings
template<typename T>
using EnumMap = std::unordered_map<T, std::string>;

// Function to convert enum values to string representations
template <typename T>
inline const std::string& ConvertEnum(EnumMap<T> enumMap, T type)
{
    return enumMap[type];
}

} //namespace Lifecycle
}
