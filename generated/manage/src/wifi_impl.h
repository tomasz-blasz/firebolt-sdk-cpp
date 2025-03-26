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
#include "jsondata_types.h"

#include "wifi.h"


namespace Firebolt {
namespace Wifi {


    using JsonData_WifiSecurityMode = WPEFramework::Core::JSON::EnumType<WifiSecurityMode>;

    using JsonData_WPSSecurityPin = WPEFramework::Core::JSON::EnumType<WPSSecurityPin>;


    // Types
    class JsonData_AccessPoint: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AccessPoint() override = default;
  
    public:
        JsonData_AccessPoint()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("ssid"), &Ssid);
            Add(_T("securityMode"), &SecurityMode);
            Add(_T("signalStrength"), &SignalStrength);
            Add(_T("frequency"), &Frequency);
        }

        JsonData_AccessPoint(const JsonData_AccessPoint& other)
        {
            Add(_T("ssid"), &Ssid);
            Ssid = other.Ssid;
            Add(_T("securityMode"), &SecurityMode);
            SecurityMode = other.SecurityMode;
            Add(_T("signalStrength"), &SignalStrength);
            SignalStrength = other.SignalStrength;
            Add(_T("frequency"), &Frequency);
            Frequency = other.Frequency;
        }

        JsonData_AccessPoint& operator=(const JsonData_AccessPoint& other)
        {
            Add(_T("ssid"), &Ssid);
            Ssid = other.Ssid;
            Add(_T("securityMode"), &SecurityMode);
            SecurityMode = other.SecurityMode;
            Add(_T("signalStrength"), &SignalStrength);
            SignalStrength = other.SignalStrength;
            Add(_T("frequency"), &Frequency);
            Frequency = other.Frequency;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Ssid;
        Firebolt::Wifi::JsonData_WifiSecurityMode SecurityMode;
        WPEFramework::Core::JSON::DecSInt32 SignalStrength;
        WPEFramework::Core::JSON::Float Frequency;
    };

    class JsonData_AccessPointList: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AccessPointList() override = default;
  
    public:
        JsonData_AccessPointList()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("list"), &List);
        }

        JsonData_AccessPointList(const JsonData_AccessPointList& other)
        {
            Add(_T("list"), &List);
            List = other.List;
        }

        JsonData_AccessPointList& operator=(const JsonData_AccessPointList& other)
        {
            Add(_T("list"), &List);
            List = other.List;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::ArrayType<Firebolt::Wifi::JsonData_AccessPoint> List;
    };

    class WifiImpl : public IWifi, public IModule {

    public:
        WifiImpl() = default;
        WifiImpl(const WifiImpl&) = delete;
        WifiImpl& operator=(const WifiImpl&) = delete;

        ~WifiImpl() override = default;

        // Methods & Events
        /*
         connect
         Connect the device to the specified SSID.
         */
        AccessPoint connect( const std::optional<std::string>& ssid, const std::optional<std::string>& passphrase, const std::optional<WifiSecurityMode>& security, Firebolt::Error *err = nullptr ) override;

        /*
         disconnect
         Disconnect the device if connected via WIFI.
         */
        void disconnect( Firebolt::Error *err = nullptr ) override;

        /*
         scan
         Scan available wifi networks in the location.
         */
        AccessPointList scan( const std::optional<int32_t>& timeout, Firebolt::Error *err = nullptr ) override;

        /*
         wps
         Connect to WPS
         */
        AccessPoint wps( const std::optional<WPSSecurityPin>& security, Firebolt::Error *err = nullptr ) override;

    };

}//namespace Wifi
}
