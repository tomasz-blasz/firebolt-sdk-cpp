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

#include "wifi_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Wifi {

    // Methods
    /* connect - Connect the device to the specified SSID. */
    AccessPoint WifiImpl::connect( const std::optional<std::string>& ssid, const std::optional<std::string>& passphrase, const std::optional<WifiSecurityMode>& security, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        AccessPoint connectedWifi;

        JsonObject jsonParameters;
        if (ssid.has_value()) {
                WPEFramework::Core::JSON::Variant ssidVariant(ssid.value());
                jsonParameters.Set(_T("ssid"), ssidVariant);
            }
            if (passphrase.has_value()) {
                WPEFramework::Core::JSON::Variant passphraseVariant(passphrase.value());
                jsonParameters.Set(_T("passphrase"), passphraseVariant);
            }
            if (security.has_value()) {
                JsonData_WifiSecurityMode jsonSecurity = security.value();
                WPEFramework::Core::JSON::Variant securityVariant(jsonSecurity.Data());
                jsonParameters.Set(_T("security"), securityVariant);
            }
        Firebolt::Wifi::JsonData_AccessPoint jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("wifi.connect", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Wifi.connect is successfully invoked");
            AccessPoint connectedWifiResult;
                if (jsonResult.Ssid.IsSet()) {
                    connectedWifiResult.ssid = jsonResult.Ssid.Value();
                }
                if (jsonResult.SecurityMode.IsSet()) {
                    connectedWifiResult.securityMode = jsonResult.SecurityMode.Value();
                }
                if (jsonResult.SignalStrength.IsSet()) {
                    connectedWifiResult.signalStrength = jsonResult.SignalStrength.Value();
                }
                if (jsonResult.Frequency.IsSet()) {
                    connectedWifiResult.frequency = jsonResult.Frequency.Value();
                }
                connectedWifi = connectedWifiResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return connectedWifi;
    }

    /* disconnect - Disconnect the device if connected via WIFI. */
    void WifiImpl::disconnect( Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;

        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("wifi.disconnect", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Wifi.disconnect is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* scan - Scan available wifi networks in the location. */
    AccessPointList WifiImpl::scan( const std::optional<int32_t>& timeout, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        AccessPointList list;

        JsonObject jsonParameters;
        if (timeout.has_value()) {
                WPEFramework::Core::JSON::Variant timeoutVariant(timeout.value());
                jsonParameters.Set(_T("timeout"), timeoutVariant);
            }
        Firebolt::Wifi::JsonData_AccessPointList jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("wifi.scan", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Wifi.scan is successfully invoked");
            AccessPointList listResult;
                if (jsonResult.List.IsSet()) {
                    listResult.list = std::make_optional<std::vector<AccessPoint>>();
                    auto listIndex(jsonResult.List.Elements());
                    while (listIndex.Next() == true) {
                        AccessPoint listResult1;
                        Firebolt::Wifi::JsonData_AccessPoint jsonResult = listIndex.Current();
                        {
                          if (jsonResult.Ssid.IsSet()) {
                                listResult1.ssid = jsonResult.Ssid;
                            }
                          if (jsonResult.SecurityMode.IsSet()) {
                                listResult1.securityMode = jsonResult.SecurityMode;
                            }
                          if (jsonResult.SignalStrength.IsSet()) {
                                listResult1.signalStrength = jsonResult.SignalStrength;
                            }
                          if (jsonResult.Frequency.IsSet()) {
                                listResult1.frequency = jsonResult.Frequency;
                            }
                        }
                        listResult.list.value().push_back(listResult1);
                    }
                }
                list = listResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return list;
    }

    /* wps - Connect to WPS */
    AccessPoint WifiImpl::wps( const std::optional<WPSSecurityPin>& security, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        AccessPoint connectedWifi;

        JsonObject jsonParameters;
        if (security.has_value()) {
                JsonData_WPSSecurityPin jsonSecurity = security.value();
                WPEFramework::Core::JSON::Variant securityVariant(jsonSecurity.Data());
                jsonParameters.Set(_T("security"), securityVariant);
            }
        Firebolt::Wifi::JsonData_AccessPoint jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("wifi.wps", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Wifi.wps is successfully invoked");
            AccessPoint connectedWifiResult;
                if (jsonResult.Ssid.IsSet()) {
                    connectedWifiResult.ssid = jsonResult.Ssid.Value();
                }
                if (jsonResult.SecurityMode.IsSet()) {
                    connectedWifiResult.securityMode = jsonResult.SecurityMode.Value();
                }
                if (jsonResult.SignalStrength.IsSet()) {
                    connectedWifiResult.signalStrength = jsonResult.SignalStrength.Value();
                }
                if (jsonResult.Frequency.IsSet()) {
                    connectedWifiResult.frequency = jsonResult.Frequency.Value();
                }
                connectedWifi = connectedWifiResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return connectedWifi;
    }


    // Events

}//namespace Wifi
}


namespace WPEFramework {

    /* WifiSecurityMode Security Mode supported for Wifi */
    ENUM_CONVERSION_BEGIN(Firebolt::Wifi::WifiSecurityMode)
        { Firebolt::Wifi::WifiSecurityMode::NONE, _T("none") },
        { Firebolt::Wifi::WifiSecurityMode::WEP_64, _T("wep64") },
        { Firebolt::Wifi::WifiSecurityMode::WEP_128, _T("wep128") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_PSK_TKIP, _T("wpaPskTkip") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_PSK_AES, _T("wpaPskAes") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_2PSK_TKIP, _T("wpa2PskTkip") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_2PSK_AES, _T("wpa2PskAes") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_ENTERPRISE_TKIP, _T("wpaEnterpriseTkip") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_ENTERPRISE_AES, _T("wpaEnterpriseAes") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_2ENTERPRISE_TKIP, _T("wpa2EnterpriseTkip") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_2ENTERPRISE_AES, _T("wpa2EnterpriseAes") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_2PSK, _T("wpa2Psk") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_2ENTERPRISE, _T("wpa2Enterprise") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_3PSK_AES, _T("wpa3PskAes") },
        { Firebolt::Wifi::WifiSecurityMode::WPA_3SAE, _T("wpa3Sae") },
    ENUM_CONVERSION_END(Firebolt::Wifi::WifiSecurityMode)

    /* WPSSecurityPin Security pin type for WPS(Wifi Protected Setup). */
    ENUM_CONVERSION_BEGIN(Firebolt::Wifi::WPSSecurityPin)
        { Firebolt::Wifi::WPSSecurityPin::PUSH_BUTTON, _T("pushButton") },
        { Firebolt::Wifi::WPSSecurityPin::PIN, _T("pin") },
        { Firebolt::Wifi::WPSSecurityPin::MANUFACTURER_PIN, _T("manufacturerPin") },
    ENUM_CONVERSION_END(Firebolt::Wifi::WPSSecurityPin)

}
