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
#include <string>


#include "jsondata_types.h"
#include "device.h"


namespace Firebolt {
namespace Device {


    using JsonData_NetworkState = WPEFramework::Core::JSON::EnumType<NetworkState>;

    using JsonData_NetworkType = WPEFramework::Core::JSON::EnumType<NetworkType>;


    // Types
    class JsonData_HDRFormatMap: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_HDRFormatMap() override = default;
  
    public:
        JsonData_HDRFormatMap()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("hdr10"), &Hdr10);
            Add(_T("hdr10Plus"), &Hdr10Plus);
            Add(_T("dolbyVision"), &DolbyVision);
            Add(_T("hlg"), &Hlg);
        }

        JsonData_HDRFormatMap(const JsonData_HDRFormatMap& other)
        {
            Add(_T("hdr10"), &Hdr10);
            Hdr10 = other.Hdr10;
            Add(_T("hdr10Plus"), &Hdr10Plus);
            Hdr10Plus = other.Hdr10Plus;
            Add(_T("dolbyVision"), &DolbyVision);
            DolbyVision = other.DolbyVision;
            Add(_T("hlg"), &Hlg);
            Hlg = other.Hlg;
        }

        JsonData_HDRFormatMap& operator=(const JsonData_HDRFormatMap& other)
        {
            Add(_T("hdr10"), &Hdr10);
            Hdr10 = other.Hdr10;
            Add(_T("hdr10Plus"), &Hdr10Plus);
            Hdr10Plus = other.Hdr10Plus;
            Add(_T("dolbyVision"), &DolbyVision);
            DolbyVision = other.DolbyVision;
            Add(_T("hlg"), &Hlg);
            Hlg = other.Hlg;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Hdr10;
        WPEFramework::Core::JSON::Boolean Hdr10Plus;
        WPEFramework::Core::JSON::Boolean DolbyVision;
        WPEFramework::Core::JSON::Boolean Hlg;
    };

    class JsonData_AudioProfiles: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AudioProfiles() override = default;
  
    public:
        JsonData_AudioProfiles()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("stereo"), &Stereo);
            Add(_T("dolbyDigital5.1"), &DolbyDigital5_1);
            Add(_T("dolbyDigital5.1+"), &DolbyDigital5_1_plus);
            Add(_T("dolbyAtmos"), &DolbyAtmos);
        }

        JsonData_AudioProfiles(const JsonData_AudioProfiles& other)
        {
            Add(_T("stereo"), &Stereo);
            Stereo = other.Stereo;
            Add(_T("dolbyDigital5.1"), &DolbyDigital5_1);
            DolbyDigital5_1 = other.DolbyDigital5_1;
            Add(_T("dolbyDigital5.1+"), &DolbyDigital5_1_plus);
            DolbyDigital5_1_plus = other.DolbyDigital5_1_plus;
            Add(_T("dolbyAtmos"), &DolbyAtmos);
            DolbyAtmos = other.DolbyAtmos;
        }

        JsonData_AudioProfiles& operator=(const JsonData_AudioProfiles& other)
        {
            Add(_T("stereo"), &Stereo);
            Stereo = other.Stereo;
            Add(_T("dolbyDigital5.1"), &DolbyDigital5_1);
            DolbyDigital5_1 = other.DolbyDigital5_1;
            Add(_T("dolbyDigital5.1+"), &DolbyDigital5_1_plus);
            DolbyDigital5_1_plus = other.DolbyDigital5_1_plus;
            Add(_T("dolbyAtmos"), &DolbyAtmos);
            DolbyAtmos = other.DolbyAtmos;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Stereo;
        WPEFramework::Core::JSON::Boolean DolbyDigital5_1;
        WPEFramework::Core::JSON::Boolean DolbyDigital5_1_plus;
        WPEFramework::Core::JSON::Boolean DolbyAtmos;
    };

        using JsonData_Resolution = WPEFramework::Core::JSON::ArrayType<WPEFramework::Core::JSON::DecSInt32>;
    class JsonData_NetworkInfoResult: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_NetworkInfoResult() override = default;
  
    public:
        JsonData_NetworkInfoResult()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("state"), &State);
            Add(_T("type"), &Type);
        }

        JsonData_NetworkInfoResult(const JsonData_NetworkInfoResult& other)
        {
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("type"), &Type);
            Type = other.Type;
        }

        JsonData_NetworkInfoResult& operator=(const JsonData_NetworkInfoResult& other)
        {
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("type"), &Type);
            Type = other.Type;
            return (*this);
        }

    public:
        Firebolt::Device::JsonData_NetworkState State;
        Firebolt::Device::JsonData_NetworkType Type;
    };

    class JsonData_DeviceVersion: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_DeviceVersion() override = default;
  
    public:
        JsonData_DeviceVersion()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("sdk"), &Sdk);
            Add(_T("api"), &Api);
            Add(_T("firmware"), &Firmware);
            Add(_T("os"), &Os);
            Add(_T("debug"), &Debug);
        }

        JsonData_DeviceVersion(const JsonData_DeviceVersion& other)
        {
            Add(_T("sdk"), &Sdk);
            Sdk = other.Sdk;
            Add(_T("api"), &Api);
            Api = other.Api;
            Add(_T("firmware"), &Firmware);
            Firmware = other.Firmware;
            Add(_T("os"), &Os);
            Os = other.Os;
            Add(_T("debug"), &Debug);
            Debug = other.Debug;
        }

        JsonData_DeviceVersion& operator=(const JsonData_DeviceVersion& other)
        {
            Add(_T("sdk"), &Sdk);
            Sdk = other.Sdk;
            Add(_T("api"), &Api);
            Api = other.Api;
            Add(_T("firmware"), &Firmware);
            Firmware = other.Firmware;
            Add(_T("os"), &Os);
            Os = other.Os;
            Add(_T("debug"), &Debug);
            Debug = other.Debug;
            return (*this);
        }

    public:
        Firebolt::Types::JsonData_SemanticVersion Sdk;
        Firebolt::Types::JsonData_SemanticVersion Api;
        Firebolt::Types::JsonData_SemanticVersion Firmware;
        Firebolt::Types::JsonData_SemanticVersion Os;
        FireboltSDK::JSON::String Debug;
    };

    class JsonData_HDCPVersionMap: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_HDCPVersionMap() override = default;
  
    public:
        JsonData_HDCPVersionMap()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("hdcp1.4"), &Hdcp1_4);
            Add(_T("hdcp2.2"), &Hdcp2_2);
        }

        JsonData_HDCPVersionMap(const JsonData_HDCPVersionMap& other)
        {
            Add(_T("hdcp1.4"), &Hdcp1_4);
            Hdcp1_4 = other.Hdcp1_4;
            Add(_T("hdcp2.2"), &Hdcp2_2);
            Hdcp2_2 = other.Hdcp2_2;
        }

        JsonData_HDCPVersionMap& operator=(const JsonData_HDCPVersionMap& other)
        {
            Add(_T("hdcp1.4"), &Hdcp1_4);
            Hdcp1_4 = other.Hdcp1_4;
            Add(_T("hdcp2.2"), &Hdcp2_2);
            Hdcp2_2 = other.Hdcp2_2;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Hdcp1_4;
        WPEFramework::Core::JSON::Boolean Hdcp2_2;
    };

    class DeviceImpl : public IDevice, public IModule {

    public:
        DeviceImpl() = default;
        DeviceImpl(const DeviceImpl&) = delete;
        DeviceImpl& operator=(const DeviceImpl&) = delete;

        ~DeviceImpl() override = default;

        std::string version(Firebolt::Error *err = nullptr) const override;

        // Methods & Events
        /*
         * Get the supported audio profiles for the connected devices. 

 It is not recommended to use this API for visual badging on content within your app since this does not reflect the settings of the user.
         * 
         */
        AudioProfiles audio( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the name of the entity which is distributing the current device. There can be multiple distributors which distribute the same device model.
         * 
         */
        std::string distributor( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the negotiated HDCP profiles for a connected device. 

 For devices that do not require additional connections (e.g. panels), `true` will be returned for all profiles.
         * 
         */
        HDCPVersionMap hdcp( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the negotiated HDR formats for the connected display and device
         * 
         */
        HDRFormatMap hdr( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the platform back-office device identifier
         * 
         */
        std::string id( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the manufacturer of the device model
         * 
         */
        std::string make( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the manufacturer designated model of the device
         * 
         */
        std::string model( Firebolt::Error *err = nullptr ) const override;
        /*
         * The human readable name of the device
         * 
         */
        std::string name( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the current network status and type
         * 
         */
        NetworkInfoResult network( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnAudioChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnAudioChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnHdcpChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnHdcpChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnHdrChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnHdrChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnNetworkChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnNetworkChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnScreenResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnScreenResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDevice::IOnVideoResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDevice::IOnVideoResolutionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         * Get a platform identifier for the device. This API should be used to correlate metrics on the device only and cannot be guaranteed to have consistent responses across platforms.
         * 
         */
        std::string platform( Firebolt::Error *err = nullptr ) const override;
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
        Resolution screenResolution( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the device sku
         * 
         */
        std::string sku( Firebolt::Error *err = nullptr ) const override;
        /*
         * Get the device type
         * 
         */
        std::string type( Firebolt::Error *err = nullptr ) const override;
        /*
         * Gets a unique id for the current app & device
         * 
         */
        std::string uid( Firebolt::Error *err = nullptr ) const override;
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
        Resolution videoResolution( Firebolt::Error *err = nullptr ) const override;
    };

}//namespace Device
}