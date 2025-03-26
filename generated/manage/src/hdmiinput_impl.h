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

#include "hdmiinput.h"


namespace Firebolt {
namespace HDMIInput {


    using JsonData_EDIDVersion = WPEFramework::Core::JSON::EnumType<EDIDVersion>;

    using JsonData_HDMISignalStatus = WPEFramework::Core::JSON::EnumType<HDMISignalStatus>;


    // Types
    class JsonData_HDMIInputPort: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_HDMIInputPort() override = default;
  
    public:
        JsonData_HDMIInputPort()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("port"), &Port);
            Add(_T("connected"), &Connected);
            Add(_T("signal"), &Signal);
            Add(_T("arcCapable"), &ArcCapable);
            Add(_T("arcConnected"), &ArcConnected);
            Add(_T("edidVersion"), &EdidVersion);
            Add(_T("autoLowLatencyModeCapable"), &AutoLowLatencyModeCapable);
            Add(_T("autoLowLatencyModeSignalled"), &AutoLowLatencyModeSignalled);
        }

        JsonData_HDMIInputPort(const JsonData_HDMIInputPort& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("connected"), &Connected);
            Connected = other.Connected;
            Add(_T("signal"), &Signal);
            Signal = other.Signal;
            Add(_T("arcCapable"), &ArcCapable);
            ArcCapable = other.ArcCapable;
            Add(_T("arcConnected"), &ArcConnected);
            ArcConnected = other.ArcConnected;
            Add(_T("edidVersion"), &EdidVersion);
            EdidVersion = other.EdidVersion;
            Add(_T("autoLowLatencyModeCapable"), &AutoLowLatencyModeCapable);
            AutoLowLatencyModeCapable = other.AutoLowLatencyModeCapable;
            Add(_T("autoLowLatencyModeSignalled"), &AutoLowLatencyModeSignalled);
            AutoLowLatencyModeSignalled = other.AutoLowLatencyModeSignalled;
        }

        JsonData_HDMIInputPort& operator=(const JsonData_HDMIInputPort& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("connected"), &Connected);
            Connected = other.Connected;
            Add(_T("signal"), &Signal);
            Signal = other.Signal;
            Add(_T("arcCapable"), &ArcCapable);
            ArcCapable = other.ArcCapable;
            Add(_T("arcConnected"), &ArcConnected);
            ArcConnected = other.ArcConnected;
            Add(_T("edidVersion"), &EdidVersion);
            EdidVersion = other.EdidVersion;
            Add(_T("autoLowLatencyModeCapable"), &AutoLowLatencyModeCapable);
            AutoLowLatencyModeCapable = other.AutoLowLatencyModeCapable;
            Add(_T("autoLowLatencyModeSignalled"), &AutoLowLatencyModeSignalled);
            AutoLowLatencyModeSignalled = other.AutoLowLatencyModeSignalled;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Port;
        WPEFramework::Core::JSON::Boolean Connected;
        Firebolt::HDMIInput::JsonData_HDMISignalStatus Signal;
        WPEFramework::Core::JSON::Boolean ArcCapable;
        WPEFramework::Core::JSON::Boolean ArcConnected;
        Firebolt::HDMIInput::JsonData_EDIDVersion EdidVersion;
        WPEFramework::Core::JSON::Boolean AutoLowLatencyModeCapable;
        WPEFramework::Core::JSON::Boolean AutoLowLatencyModeSignalled;
    };

    class JsonData_AutoLowLatencyModeCapableChangedInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AutoLowLatencyModeCapableChangedInfo() override = default;
  
    public:
        JsonData_AutoLowLatencyModeCapableChangedInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("port"), &Port);
            Add(_T("enabled"), &Enabled);
        }

        JsonData_AutoLowLatencyModeCapableChangedInfo(const JsonData_AutoLowLatencyModeCapableChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
        }

        JsonData_AutoLowLatencyModeCapableChangedInfo& operator=(const JsonData_AutoLowLatencyModeCapableChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Port;
        WPEFramework::Core::JSON::Boolean Enabled;
    };

    class JsonData_ConnectionChangedInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_ConnectionChangedInfo() override = default;
  
    public:
        JsonData_ConnectionChangedInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("port"), &Port);
            Add(_T("connected"), &Connected);
        }

        JsonData_ConnectionChangedInfo(const JsonData_ConnectionChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("connected"), &Connected);
            Connected = other.Connected;
        }

        JsonData_ConnectionChangedInfo& operator=(const JsonData_ConnectionChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("connected"), &Connected);
            Connected = other.Connected;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Port;
        WPEFramework::Core::JSON::Boolean Connected;
    };

    class JsonData_SignalChangedInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_SignalChangedInfo() override = default;
  
    public:
        JsonData_SignalChangedInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("port"), &Port);
            Add(_T("signal"), &Signal);
        }

        JsonData_SignalChangedInfo(const JsonData_SignalChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("signal"), &Signal);
            Signal = other.Signal;
        }

        JsonData_SignalChangedInfo& operator=(const JsonData_SignalChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("signal"), &Signal);
            Signal = other.Signal;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Port;
        Firebolt::HDMIInput::JsonData_HDMISignalStatus Signal;
    };

    class JsonData_AutoLowLatencyModeSignalChangedInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AutoLowLatencyModeSignalChangedInfo() override = default;
  
    public:
        JsonData_AutoLowLatencyModeSignalChangedInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("port"), &Port);
            Add(_T("autoLowLatencyModeSignalled"), &AutoLowLatencyModeSignalled);
        }

        JsonData_AutoLowLatencyModeSignalChangedInfo(const JsonData_AutoLowLatencyModeSignalChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("autoLowLatencyModeSignalled"), &AutoLowLatencyModeSignalled);
            AutoLowLatencyModeSignalled = other.AutoLowLatencyModeSignalled;
        }

        JsonData_AutoLowLatencyModeSignalChangedInfo& operator=(const JsonData_AutoLowLatencyModeSignalChangedInfo& other)
        {
            Add(_T("port"), &Port);
            Port = other.Port;
            Add(_T("autoLowLatencyModeSignalled"), &AutoLowLatencyModeSignalled);
            AutoLowLatencyModeSignalled = other.AutoLowLatencyModeSignalled;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Port;
        WPEFramework::Core::JSON::Boolean AutoLowLatencyModeSignalled;
    };

    class HDMIInputImpl : public IHDMIInput, public IModule {

    public:
        HDMIInputImpl() = default;
        HDMIInputImpl(const HDMIInputImpl&) = delete;
        HDMIInputImpl& operator=(const HDMIInputImpl&) = delete;

        ~HDMIInputImpl() override = default;

        // Methods & Events
        /*
         * Property for each port auto low latency mode setting.
         * const std::string port
         */
        bool autoLowLatencyModeCapable( const std::string& port, Firebolt::Error *err = nullptr ) const override;
        /*
         close
         Closes the given HDMI Port if it is the current active source for HDMI Input. If there was no active source, then there would no action taken on the device.
         */
        void close( Firebolt::Error *err = nullptr ) override;

        /*
         * Property for each port's active EDID version.
         * const std::string port
         */
        EDIDVersion edidVersion( const std::string& port, Firebolt::Error *err = nullptr ) const override;
        /*
         * Property for the low latency mode setting.
         * 
         */
        bool lowLatencyMode( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        void globalSubscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void globalUnsubscribe( IHDMIInput::IOnAutoLowLatencyModeCapableChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IHDMIInput::IOnAutoLowLatencyModeSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IHDMIInput::IOnAutoLowLatencyModeSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IHDMIInput::IOnConnectionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IHDMIInput::IOnConnectionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( const std::string& port, IHDMIInput::IOnEdidVersionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IHDMIInput::IOnEdidVersionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IHDMIInput::IOnLowLatencyModeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IHDMIInput::IOnLowLatencyModeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IHDMIInput::IOnSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IHDMIInput::IOnSignalChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         open
         Opens the HDMI Port allowing it to be the active source device. Incase there is a different HDMI portId already set as the active source, this call would stop the older portId before opening the given portId.
         */
        void open( const std::string& portId, Firebolt::Error *err = nullptr ) override;

        /*
         port
         Retrieve a specific HDMI input port.
         */
        HDMIInputPort port( const std::string& portId, Firebolt::Error *err = nullptr ) override;

        /*
         ports
         Retrieve a list of HDMI input ports.
         */
        std::vector<HDMIInputPort> ports( Firebolt::Error *err = nullptr ) const override;

        /*
         * setAutoLowLatencyModeCapable
         * Property for each port auto low latency mode setting.
         */
        void setAutoLowLatencyModeCapable( const std::string& port, const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setEdidVersion
         * Property for each port's active EDID version.
         */
        void setEdidVersion( const std::string& port, const EDIDVersion& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setLowLatencyMode
         * Property for the low latency mode setting.
         */
        void setLowLatencyMode( const bool value, Firebolt::Error *err = nullptr ) override;

    };

}//namespace HDMIInput
}
