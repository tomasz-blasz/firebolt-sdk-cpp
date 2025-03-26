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
#include "common/types.h"


namespace Firebolt {
    namespace Device {
/* NetworkState The type of network that is currently active */
enum class NetworkState {
    CONNECTED,
    DISCONNECTED
};

/* NetworkType The type of network that is currently active */
enum class NetworkType {
    WIFI,
    ETHERNET,
    HYBRID
};

struct HDRFormatMap {
    bool hdr10;
    bool hdr10Plus;
    bool dolbyVision;
    bool hlg;
};

struct AudioProfiles {
    bool stereo;
    bool dolbyDigital5_1;
    bool dolbyDigital5_1_plus;
    bool dolbyAtmos;
};

/* Resolution */
using Resolution = std::pair<int32_t, int32_t>;

struct NetworkInfoResult {
    NetworkState state;
    NetworkType type;
};

struct DeviceVersion {
    std::optional<Types::SemanticVersion> sdk;
    Types::SemanticVersion api;
    Types::SemanticVersion firmware;
    Types::SemanticVersion os;
    std::optional<std::string> debug;
};

struct HDCPVersionMap {
    bool hdcp1_4;
    bool hdcp2_2;
};

        
        struct IDevice {
            // Methods & Events
    /*
     * Get the supported audio profiles for the connected devices. 

 It is not recommended to use this API for visual badging on content within your app since this does not reflect the settings of the user.
     * 
     */
    virtual AudioProfiles audio( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the name of the entity which is distributing the current device. There can be multiple distributors which distribute the same device model.
     * 
     */
    virtual std::string distributor( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the negotiated HDCP profiles for a connected device. 

 For devices that do not require additional connections (e.g. panels), `true` will be returned for all profiles.
     * 
     */
    virtual HDCPVersionMap hdcp( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the negotiated HDR formats for the connected display and device
     * 
     */
    virtual HDRFormatMap hdr( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the platform back-office device identifier
     * 
     */
    virtual std::string id( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the manufacturer of the device model
     * 
     */
    virtual std::string make( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the manufacturer designated model of the device
     * 
     */
    virtual std::string model( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The human readable name of the device
     * 
     */
    virtual std::string name( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the current network status and type
     * 
     */
    virtual NetworkInfoResult network( Firebolt::Error *err = nullptr ) const = 0;

    /* onAudioChanged - Get the supported audio profiles for the connected devices. 

 It is not recommended to use this API for visual badging on content within your app since this does not reflect the settings of the user. */
    struct IOnAudioChangedNotification {
        virtual void onAudioChanged( const AudioProfiles& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAudioChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAudioChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onDeviceNameChanged - Get the human readable name of the device */
    struct IOnDeviceNameChangedNotification {
        virtual void onDeviceNameChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onHdcpChanged - Get the negotiated HDCP profiles for a connected device. 

 For devices that do not require additional connections (e.g. panels), `true` will be returned for all profiles. */
    struct IOnHdcpChangedNotification {
        virtual void onHdcpChanged( const HDCPVersionMap& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnHdcpChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnHdcpChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onHdrChanged - Get the negotiated HDR formats for the connected display and device */
    struct IOnHdrChangedNotification {
        virtual void onHdrChanged( const HDRFormatMap& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnHdrChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnHdrChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onNameChanged - The human readable name of the device */
    struct IOnNameChangedNotification {
        virtual void onNameChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onNetworkChanged - Get the current network status and type */
    struct IOnNetworkChangedNotification {
        virtual void onNetworkChanged( const NetworkInfoResult& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnNetworkChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnNetworkChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onScreenResolutionChanged - Get the resolution for the graphical surface of the app. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160] 

**Deprecated:** Use non-Firebolt APIs specific to your platform, e.g. W3C APIs */
    struct IOnScreenResolutionChangedNotification {
        virtual void onScreenResolutionChanged( const Resolution& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnScreenResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnScreenResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onVideoResolutionChanged - Get the maximum supported video resolution of the currently connected device and display. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160] */
    struct IOnVideoResolutionChangedNotification {
        virtual void onVideoResolutionChanged( const Resolution& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnVideoResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnVideoResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     * Get a platform identifier for the device. This API should be used to correlate metrics on the device only and cannot be guaranteed to have consistent responses across platforms.
     * 
     */
    virtual std::string platform( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the resolution for the graphical surface of the app. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160] 

**Deprecated:** Use non-Firebolt APIs specific to your platform, e.g. W3C APIs
     * 
     */
    virtual Resolution screenResolution( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the device sku
     * 
     */
    virtual std::string sku( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the device type
     * 
     */
    virtual std::string type( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Gets a unique id for the current app & device
     * 
     */
    virtual std::string uid( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Get the maximum supported video resolution of the currently connected device and display. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160]
     * 
     */
    virtual Resolution videoResolution( Firebolt::Error *err = nullptr ) const = 0;

            virtual ~IDevice() = default;
            virtual std::string version( Firebolt::Error *err = nullptr ) const = 0;
        };
        
    } //namespace Device
}
