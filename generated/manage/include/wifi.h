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


namespace Firebolt {
namespace Wifi {


// Enums
/* WifiSecurityMode Security Mode supported for Wifi */
enum class WifiSecurityMode {
    NONE,
    WEP_64,
    WEP_128,
    WPA_PSK_TKIP,
    WPA_PSK_AES,
    WPA_2PSK_TKIP,
    WPA_2PSK_AES,
    WPA_ENTERPRISE_TKIP,
    WPA_ENTERPRISE_AES,
    WPA_2ENTERPRISE_TKIP,
    WPA_2ENTERPRISE_AES,
    WPA_2PSK,
    WPA_2ENTERPRISE,
    WPA_3PSK_AES,
    WPA_3SAE
};

/* WPSSecurityPin Security pin type for WPS(Wifi Protected Setup). */
enum class WPSSecurityPin {
    PUSH_BUTTON,
    PIN,
    MANUFACTURER_PIN
};


// Types
struct AccessPoint {
    std::optional<std::string> ssid;
    std::optional<WifiSecurityMode> securityMode;
    std::optional<int32_t> signalStrength;
    std::optional<float> frequency;
};

struct AccessPointList {
    std::optional<std::vector<AccessPoint>> list;
};


struct IWifi {

    virtual ~IWifi() = default;

    // Methods & Events
    /*
     connect
     Connect the device to the specified SSID.
     
     */
    virtual AccessPoint connect( const std::optional<std::string>& ssid, const std::optional<std::string>& passphrase, const std::optional<WifiSecurityMode>& security, Firebolt::Error *err = nullptr ) = 0;
    /*
     disconnect
     Disconnect the device if connected via WIFI.
     
     */
    virtual void disconnect( Firebolt::Error *err = nullptr ) = 0;
    /*
     scan
     Scan available wifi networks in the location.
     
     */
    virtual AccessPointList scan( const std::optional<int32_t>& timeout, Firebolt::Error *err = nullptr ) = 0;
    /*
     wps
     Connect to WPS
     
     */
    virtual AccessPoint wps( const std::optional<WPSSecurityPin>& security, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace Wifi
}
