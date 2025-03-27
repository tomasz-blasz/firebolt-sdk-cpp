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

#include "hdmiinput_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace HDMIInput {

    // Methods
    /* autoLowLatencyModeCapable - Property for each port auto low latency mode setting. */
    bool HDMIInputImpl::autoLowLatencyModeCapable( const std::string& port, Firebolt::Error *err ) const
    {
        const string method = _T("hdmiinput.autoLowLatencyModeCapable");
        JsonObject jsonParameters;
                WPEFramework::Core::JSON::Variant portVariant(port);
        jsonParameters.Set(_T("port"), portVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool enabled = false;
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonParameters, jsonResult);
        
        if (status == Firebolt::Error::None) {
            enabled = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return enabled;
    }
    /* setAutoLowLatencyModeCapable - Property for each port auto low latency mode setting. */
    void HDMIInputImpl::setAutoLowLatencyModeCapable( const std::string& port, const bool value, Firebolt::Error *err )
    {
        const string method = _T("hdmiinput.setAutoLowLatencyModeCapable");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant portVariant(port);
        jsonParameters.Set(_T("port"), portVariant);
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* close - Closes the given HDMI Port if it is the current active source for HDMI Input. If there was no active source, then there would no action taken on the device. */
    void HDMIInputImpl::close( Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;

        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("hdmiinput.close", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "HDMIInput.close is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* edidVersion - Property for each port's active EDID version. */
    EDIDVersion HDMIInputImpl::edidVersion( const std::string& port, Firebolt::Error *err ) const
    {
        const string method = _T("hdmiinput.edidVersion");
        JsonObject jsonParameters;
                WPEFramework::Core::JSON::Variant portVariant(port);
        jsonParameters.Set(_T("port"), portVariant);
        Firebolt::HDMIInput::JsonData_EDIDVersion jsonResult;
        EDIDVersion edidVersion;
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonParameters, jsonResult);
        
        if (status == Firebolt::Error::None) {
            edidVersion = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return edidVersion;
    }
    /* setEdidVersion - Property for each port's active EDID version. */
    void HDMIInputImpl::setEdidVersion( const std::string& port, const EDIDVersion& value, Firebolt::Error *err )
    {
        const string method = _T("hdmiinput.setEdidVersion");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant portVariant(port);
        jsonParameters.Set(_T("port"), portVariant);
        JsonData_EDIDVersion jsonValue = value;
        WPEFramework::Core::JSON::Variant valueVariant(jsonValue.Data());
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* lowLatencyMode - Property for the low latency mode setting. */
    bool HDMIInputImpl::lowLatencyMode( Firebolt::Error *err ) const
    {
        const string method = _T("hdmiinput.lowLatencyMode");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool enabled = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            enabled = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return enabled;
    }
    /* setLowLatencyMode - Property for the low latency mode setting. */
    void HDMIInputImpl::setLowLatencyMode( const bool value, Firebolt::Error *err )
    {
        const string method = _T("hdmiinput.setLowLatencyMode");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* open - Opens the HDMI Port allowing it to be the active source device. Incase there is a different HDMI portId already set as the active source, this call would stop the older portId before opening the given portId. */
    void HDMIInputImpl::open( const std::string& portId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant portIdVariant(portId);
            jsonParameters.Set(_T("portId"), portIdVariant);
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("hdmiinput.open", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "HDMIInput.open is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* port - Retrieve a specific HDMI input port. */
    HDMIInputPort HDMIInputImpl::port( const std::string& portId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        HDMIInputPort port;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant portIdVariant(portId);
            jsonParameters.Set(_T("portId"), portIdVariant);
        Firebolt::HDMIInput::JsonData_HDMIInputPort jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("hdmiinput.port", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "HDMIInput.port is successfully invoked");
            HDMIInputPort portResult;
                portResult.port = jsonResult.Port.Value();
                portResult.connected = jsonResult.Connected.Value();
                portResult.signal = jsonResult.Signal.Value();
                portResult.arcCapable = jsonResult.ArcCapable.Value();
                portResult.arcConnected = jsonResult.ArcConnected.Value();
                portResult.edidVersion = jsonResult.EdidVersion.Value();
                portResult.autoLowLatencyModeCapable = jsonResult.AutoLowLatencyModeCapable.Value();
                portResult.autoLowLatencyModeSignalled = jsonResult.AutoLowLatencyModeSignalled.Value();
                port = portResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return port;
    }

    /* ports - Retrieve a list of HDMI input ports. */
    std::vector<HDMIInputPort> HDMIInputImpl::ports( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::vector<HDMIInputPort> ports;

        JsonObject jsonParameters;

        WPEFramework::Core::JSON::ArrayType<Firebolt::HDMIInput::JsonData_HDMIInputPort> jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("hdmiinput.ports", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "HDMIInput.ports is successfully invoked");
            auto index(jsonResult.Elements());
                while (index.Next() == true) {
                    HDMIInputPort portsResult1;
                    JsonData_HDMIInputPort jsonResult = index.Current();
                    portsResult1.port = jsonResult.Port.Value();
                    portsResult1.connected = jsonResult.Connected.Value();
                    portsResult1.signal = jsonResult.Signal.Value();
                    portsResult1.arcCapable = jsonResult.ArcCapable.Value();
                    portsResult1.arcConnected = jsonResult.ArcConnected.Value();
                    portsResult1.edidVersion = jsonResult.EdidVersion.Value();
                    portsResult1.autoLowLatencyModeCapable = jsonResult.AutoLowLatencyModeCapable.Value();
                    portsResult1.autoLowLatencyModeSignalled = jsonResult.AutoLowLatencyModeSignalled.Value();
                    ports.push_back(portsResult1);
                }
        }

        if (err != nullptr) {
            *err = status;
        }

        return ports;
    }


    // Events
    /* onAutoLowLatencyModeCapableChanged - Property for each port auto low latency mode setting. */
    static void onAutoLowLatencyModeCapableChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeCapableChangedInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeCapableChangedInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            AutoLowLatencyModeCapableChangedInfo result;

            result.port = proxyResponse->Port;
            result.enabled = proxyResponse->Enabled;

            proxyResponse.Release();

            IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notifier = *(reinterpret_cast<IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification*>(notification));
            notifier.onAutoLowLatencyModeCapableChanged(result);
        }
    }
    void HDMIInputImpl::subscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("hdmiinput.onAutoLowLatencyModeCapableChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeCapableChangedInfo>(eventName, jsonParameters, onAutoLowLatencyModeCapableChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void HDMIInputImpl::unsubscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("hdmiinput.onAutoLowLatencyModeCapableChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }

 
    static void onAutoLowLatencyModeCapableChangedGlobalCallback( void* notification, const void* userData, void* jsonResponse)
    {
        WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeCapableChangedInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeCapableChangedInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            AutoLowLatencyModeCapableChangedInfo result;

            result.port = proxyResponse->Port;
            result.enabled = proxyResponse->Enabled;

            proxyResponse.Release();

            IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notifier = *(reinterpret_cast<IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification*>(notification));
            notifier.onAutoLowLatencyModeCapableChanged(result);    
        }
    }
    void HDMIInputImpl::globalSubscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("HDMIInput.onAutoLowLatencyModeCapableChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;
        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeCapableChangedInfo>(eventName, jsonParameters, onAutoLowLatencyModeCapableChangedGlobalCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void HDMIInputImpl::globalUnsubscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("HDMIInput.onAutoLowLatencyModeCapableChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }


    /* onAutoLowLatencyModeSignalChanged - Notification for changes to ALLM status of any input device. */
    static void onAutoLowLatencyModeSignalChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeSignalChangedInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeSignalChangedInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            AutoLowLatencyModeSignalChangedInfo result;

            if (proxyResponse->Port.IsSet()) {
                result.port = proxyResponse->Port;
            }
            if (proxyResponse->AutoLowLatencyModeSignalled.IsSet()) {
                result.autoLowLatencyModeSignalled = proxyResponse->AutoLowLatencyModeSignalled;
            }

            proxyResponse.Release();

            IHDMIInput::IOnAutoLowLatencyModeSignalChangedNotification& notifier = *(reinterpret_cast<IHDMIInput::IOnAutoLowLatencyModeSignalChangedNotification*>(notification));
            notifier.onAutoLowLatencyModeSignalChanged(result);
        }
    }
    void HDMIInputImpl::subscribe( IHDMIInput::IOnAutoLowLatencyModeSignalChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("hdmiinput.onAutoLowLatencyModeSignalChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::HDMIInput::JsonData_AutoLowLatencyModeSignalChangedInfo>(eventName, jsonParameters, onAutoLowLatencyModeSignalChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void HDMIInputImpl::unsubscribe( IHDMIInput::IOnAutoLowLatencyModeSignalChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("hdmiinput.onAutoLowLatencyModeSignalChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onConnectionChanged - Notification for when any HDMI port has a connection physically engaged or disengaged. */
    static void onConnectionChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_ConnectionChangedInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_ConnectionChangedInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            ConnectionChangedInfo result;

            if (proxyResponse->Port.IsSet()) {
                result.port = proxyResponse->Port;
            }
            if (proxyResponse->Connected.IsSet()) {
                result.connected = proxyResponse->Connected;
            }

            proxyResponse.Release();

            IHDMIInput::IOnConnectionChangedNotification& notifier = *(reinterpret_cast<IHDMIInput::IOnConnectionChangedNotification*>(notification));
            notifier.onConnectionChanged(result);
        }
    }
    void HDMIInputImpl::subscribe( IHDMIInput::IOnConnectionChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("hdmiinput.onConnectionChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::HDMIInput::JsonData_ConnectionChangedInfo>(eventName, jsonParameters, onConnectionChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void HDMIInputImpl::unsubscribe( IHDMIInput::IOnConnectionChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("hdmiinput.onConnectionChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onEdidVersionChanged - Property for each port's active EDID version. */
    static void onEdidVersionChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_EDIDVersion>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_EDIDVersion>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            EDIDVersion result;

            result = proxyResponse->Value();
            proxyResponse.Release();

            IHDMIInput::IOnEdidVersionChangedNotification& notifier = *(reinterpret_cast<IHDMIInput::IOnEdidVersionChangedNotification*>(notification));
            notifier.onEdidVersionChanged(result);
        }
    }
    void HDMIInputImpl::subscribe( const std::string& port, IHDMIInput::IOnEdidVersionChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("hdmiinput.onEdidVersionChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant portVariant(port);
        jsonParameters.Set(_T("port"), portVariant);
        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::HDMIInput::JsonData_EDIDVersion>(eventName, jsonParameters, onEdidVersionChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void HDMIInputImpl::unsubscribe( IHDMIInput::IOnEdidVersionChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("hdmiinput.onEdidVersionChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onLowLatencyModeChanged - Property for the low latency mode setting. */
    static void onLowLatencyModeChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IHDMIInput::IOnLowLatencyModeChangedNotification& notifier = *(reinterpret_cast<IHDMIInput::IOnLowLatencyModeChangedNotification*>(notification));
            notifier.onLowLatencyModeChanged(result);
        }
    }
    void HDMIInputImpl::subscribe( IHDMIInput::IOnLowLatencyModeChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("hdmiinput.onLowLatencyModeChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onLowLatencyModeChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void HDMIInputImpl::unsubscribe( IHDMIInput::IOnLowLatencyModeChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("hdmiinput.onLowLatencyModeChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onSignalChanged - Notification for when any HDMI port has it's signal status changed. */
    static void onSignalChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_SignalChangedInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::HDMIInput::JsonData_SignalChangedInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            SignalChangedInfo result;

            result.port = proxyResponse->Port;
            result.signal = proxyResponse->Signal;

            proxyResponse.Release();

            IHDMIInput::IOnSignalChangedNotification& notifier = *(reinterpret_cast<IHDMIInput::IOnSignalChangedNotification*>(notification));
            notifier.onSignalChanged(result);
        }
    }
    void HDMIInputImpl::subscribe( IHDMIInput::IOnSignalChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("hdmiinput.onSignalChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::HDMIInput::JsonData_SignalChangedInfo>(eventName, jsonParameters, onSignalChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void HDMIInputImpl::unsubscribe( IHDMIInput::IOnSignalChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("hdmiinput.onSignalChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace HDMIInput
}


namespace WPEFramework {

    /* EDIDVersion  */
    ENUM_CONVERSION_BEGIN(Firebolt::HDMIInput::EDIDVersion)
        { Firebolt::HDMIInput::EDIDVersion::V1_4, _T("1.4") },
        { Firebolt::HDMIInput::EDIDVersion::V2_0, _T("2.0") },
        { Firebolt::HDMIInput::EDIDVersion::UNKNOWN, _T("unknown") },
    ENUM_CONVERSION_END(Firebolt::HDMIInput::EDIDVersion)

    /* HDMISignalStatus  */
    ENUM_CONVERSION_BEGIN(Firebolt::HDMIInput::HDMISignalStatus)
        { Firebolt::HDMIInput::HDMISignalStatus::NONE, _T("none") },
        { Firebolt::HDMIInput::HDMISignalStatus::STABLE, _T("stable") },
        { Firebolt::HDMIInput::HDMISignalStatus::UNSTABLE, _T("unstable") },
        { Firebolt::HDMIInput::HDMISignalStatus::UNSUPPORTED, _T("unsupported") },
        { Firebolt::HDMIInput::HDMISignalStatus::UNKNOWN, _T("unknown") },
    ENUM_CONVERSION_END(Firebolt::HDMIInput::HDMISignalStatus)

}
