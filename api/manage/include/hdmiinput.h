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


namespace Firebolt {
namespace HDMIInput {


// Enums
/* EDIDVersion  */
enum class EDIDVersion {
    V1_4,
    V2_0,
    UNKNOWN
};

/* HDMISignalStatus  */
enum class HDMISignalStatus {
    NONE,
    STABLE,
    UNSTABLE,
    UNSUPPORTED,
    UNKNOWN
};


// Types
struct HDMIInputPort {
    std::string port;
    bool connected;
    HDMISignalStatus signal;
    bool arcCapable;
    bool arcConnected;
    EDIDVersion edidVersion;
    bool autoLowLatencyModeCapable;
    bool autoLowLatencyModeSignalled;
};

struct AutoLowLatencyModeCapableChangedInfo {
    std::string port;
    bool enabled;
};

struct ConnectionChangedInfo {
    std::optional<std::string> port;
    std::optional<bool> connected;
};

struct SignalChangedInfo {
    std::string port;
    HDMISignalStatus signal;
};

struct AutoLowLatencyModeSignalChangedInfo {
    std::optional<std::string> port;
    std::optional<bool> autoLowLatencyModeSignalled;
};


struct IHDMIInput {

    virtual ~IHDMIInput() = default;

    // Methods & Events
    /*
     * Property for each port auto low latency mode setting.
     * const std::string port
     */
    virtual bool autoLowLatencyModeCapable( const std::string& port, Firebolt::Error *err = nullptr ) const = 0;

    /*
     close
     Closes the given HDMI Port if it is the current active source for HDMI Input. If there was no active source, then there would no action taken on the device.
     
     */
    virtual void close( Firebolt::Error *err = nullptr ) = 0;
    /*
     * Property for each port's active EDID version.
     * const std::string port
     */
    virtual EDIDVersion edidVersion( const std::string& port, Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Property for the low latency mode setting.
     * 
     */
    virtual bool lowLatencyMode( Firebolt::Error *err = nullptr ) const = 0;

    /* onAutoLowLatencyModeCapableChanged - Property for each port auto low latency mode setting. */
    struct IOnAutoLowLatencyModeCapableChangedNotification {
        virtual void onAutoLowLatencyModeCapableChanged( const AutoLowLatencyModeCapableChangedInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    virtual void globalSubscribe( IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void globalUnsubscribe( IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAutoLowLatencyModeSignalChanged - Notification for changes to ALLM status of any input device. */
    struct IOnAutoLowLatencyModeSignalChangedNotification {
        virtual void onAutoLowLatencyModeSignalChanged( const AutoLowLatencyModeSignalChangedInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAutoLowLatencyModeSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAutoLowLatencyModeSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onConnectionChanged - Notification for when any HDMI port has a connection physically engaged or disengaged. */
    struct IOnConnectionChangedNotification {
        virtual void onConnectionChanged( const ConnectionChangedInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnConnectionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnConnectionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onEdidVersionChanged - Property for each port's active EDID version. */
    struct IOnEdidVersionChangedNotification {
        virtual void onEdidVersionChanged( const EDIDVersion& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( const std::string& port, IOnEdidVersionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnEdidVersionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onLowLatencyModeChanged - Property for the low latency mode setting. */
    struct IOnLowLatencyModeChangedNotification {
        virtual void onLowLatencyModeChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnLowLatencyModeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnLowLatencyModeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onSignalChanged - Notification for when any HDMI port has it's signal status changed. */
    struct IOnSignalChangedNotification {
        virtual void onSignalChanged( const SignalChangedInfo& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     open
     Opens the HDMI Port allowing it to be the active source device. Incase there is a different HDMI portId already set as the active source, this call would stop the older portId before opening the given portId.
     
     */
    virtual void open( const std::string& portId, Firebolt::Error *err = nullptr ) = 0;
    /*
     port
     Retrieve a specific HDMI input port.
     
     */
    virtual HDMIInputPort port( const std::string& portId, Firebolt::Error *err = nullptr ) = 0;
    /*
     ports
     Retrieve a list of HDMI input ports.
     
     */
    virtual std::vector<HDMIInputPort> ports( Firebolt::Error *err = nullptr ) const = 0;
    /*
     setAutoLowLatencyModeCapable
     Property for each port auto low latency mode setting.
     */
    virtual void setAutoLowLatencyModeCapable( const std::string& port, const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setEdidVersion
     Property for each port's active EDID version.
     */
    virtual void setEdidVersion( const std::string& port, const EDIDVersion& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setLowLatencyMode
     Property for the low latency mode setting.
     */
    virtual void setLowLatencyMode( const bool value, Firebolt::Error *err = nullptr ) = 0;

};

} //namespace HDMIInput
}
