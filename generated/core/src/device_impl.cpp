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

#include "device_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Device {

    std::string DeviceImpl::version(Firebolt::Error *err) const
    {
        JsonObject jsonParameters;
        JsonData_DeviceVersion jsonResult;
        std::string version;

        Firebolt::Error status = Firebolt::Error::NotConnected;
        status = FireboltSDK::Gateway::Instance().Request("device.version", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            !jsonResult.IsSet() ? jsonResult.Clear() : (void)0;
            !jsonResult.Sdk.IsSet() ? jsonResult.Sdk.Clear() : (void)0;
            jsonResult.Sdk.Major = static_cast<int32_t>(0);
            jsonResult.Sdk.Minor = static_cast<int32_t>(0);
            jsonResult.Sdk.Patch = static_cast<int32_t>(0);
            jsonResult.Sdk.Readable = "Firebolt Core SDK 0.0.0-unknown.0";
            jsonResult.ToString(version);
        }

        if (err != nullptr) {
            *err = status;
        }

        return version;
    }
    // Methods
    /* audio - Get the supported audio profiles for the connected devices. 

 It is not recommended to use this API for visual badging on content within your app since this does not reflect the settings of the user. */
    AudioProfiles DeviceImpl::audio( Firebolt::Error *err ) const
    {
        const string method = _T("device.audio");
        
        
        Firebolt::Device::JsonData_AudioProfiles jsonResult;
        AudioProfiles supportedAudioProfiles;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            AudioProfiles supportedAudioProfilesResult;
            supportedAudioProfilesResult.stereo = jsonResult.Stereo.Value();
            supportedAudioProfilesResult.dolbyDigital5_1 = jsonResult.DolbyDigital5_1.Value();
            supportedAudioProfilesResult.dolbyDigital5_1_plus = jsonResult.DolbyDigital5_1_plus.Value();
            supportedAudioProfilesResult.dolbyAtmos = jsonResult.DolbyAtmos.Value();
            supportedAudioProfiles = supportedAudioProfilesResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return supportedAudioProfiles;
    }

    /* distributor - Get the name of the entity which is distributing the current device. There can be multiple distributors which distribute the same device model. */
    std::string DeviceImpl::distributor( Firebolt::Error *err ) const
    {
        const string method = _T("device.distributor");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string distributorId;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            distributorId = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return distributorId;
    }

    /* hdcp - Get the negotiated HDCP profiles for a connected device. 

 For devices that do not require additional connections (e.g. panels), `true` will be returned for all profiles. */
    HDCPVersionMap DeviceImpl::hdcp( Firebolt::Error *err ) const
    {
        const string method = _T("device.hdcp");
        
        
        Firebolt::Device::JsonData_HDCPVersionMap jsonResult;
        HDCPVersionMap negotiatedHdcpVersions;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            HDCPVersionMap negotiatedHdcpVersionsResult;
            negotiatedHdcpVersionsResult.hdcp1_4 = jsonResult.Hdcp1_4.Value();
            negotiatedHdcpVersionsResult.hdcp2_2 = jsonResult.Hdcp2_2.Value();
            negotiatedHdcpVersions = negotiatedHdcpVersionsResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return negotiatedHdcpVersions;
    }

    /* hdr - Get the negotiated HDR formats for the connected display and device */
    HDRFormatMap DeviceImpl::hdr( Firebolt::Error *err ) const
    {
        const string method = _T("device.hdr");
        
        
        Firebolt::Device::JsonData_HDRFormatMap jsonResult;
        HDRFormatMap negotiatedHdrFormats;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            HDRFormatMap negotiatedHdrFormatsResult;
            negotiatedHdrFormatsResult.hdr10 = jsonResult.Hdr10.Value();
            negotiatedHdrFormatsResult.hdr10Plus = jsonResult.Hdr10Plus.Value();
            negotiatedHdrFormatsResult.dolbyVision = jsonResult.DolbyVision.Value();
            negotiatedHdrFormatsResult.hlg = jsonResult.Hlg.Value();
            negotiatedHdrFormats = negotiatedHdrFormatsResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return negotiatedHdrFormats;
    }

    /* id - Get the platform back-office device identifier */
    std::string DeviceImpl::id( Firebolt::Error *err ) const
    {
        const string method = _T("device.id");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string id;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            id = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return id;
    }

    /* make - Get the manufacturer of the device model */
    std::string DeviceImpl::make( Firebolt::Error *err ) const
    {
        const string method = _T("device.make");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string make;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            make = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return make;
    }

    /* model - Get the manufacturer designated model of the device */
    std::string DeviceImpl::model( Firebolt::Error *err ) const
    {
        const string method = _T("device.model");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string model;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            model = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return model;
    }

    /* name - The human readable name of the device */
    std::string DeviceImpl::name( Firebolt::Error *err ) const
    {
        const string method = _T("device.name");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string value;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            value = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return value;
    }

    /* network - Get the current network status and type */
    NetworkInfoResult DeviceImpl::network( Firebolt::Error *err ) const
    {
        const string method = _T("device.network");
        
        
        Firebolt::Device::JsonData_NetworkInfoResult jsonResult;
        NetworkInfoResult networkInfo;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            NetworkInfoResult networkInfoResult;
            networkInfoResult.state = jsonResult.State.Value();
            networkInfoResult.type = jsonResult.Type.Value();
            networkInfo = networkInfoResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return networkInfo;
    }

    /* platform - Get a platform identifier for the device. This API should be used to correlate metrics on the device only and cannot be guaranteed to have consistent responses across platforms. */
    std::string DeviceImpl::platform( Firebolt::Error *err ) const
    {
        const string method = _T("device.platform");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string platformId;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            platformId = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return platformId;
    }

    /* screenResolution - Get the resolution for the graphical surface of the app. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160] 

**Deprecated:** Use non-Firebolt APIs specific to your platform, e.g. W3C APIs */
    Resolution DeviceImpl::screenResolution( Firebolt::Error *err ) const
    {
        const string method = _T("device.screenResolution");
        
        
        Firebolt::Device::JsonData_Resolution jsonResult;
        Resolution screenResolution;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            ASSERT((jsonResult.Length() == 0) || (jsonResult.Length() == 2));
            if (jsonResult.Length() == 2) {
                screenResolution.first = jsonResult.Get(0);
                screenResolution.second = jsonResult.Get(1);
	    }

        }
        if (err != nullptr) {
            *err = status;
        }

        return screenResolution;
    }

    /* sku - Get the device sku */
    std::string DeviceImpl::sku( Firebolt::Error *err ) const
    {
        const string method = _T("device.sku");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string sku;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            sku = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return sku;
    }

    /* type - Get the device type */
    std::string DeviceImpl::type( Firebolt::Error *err ) const
    {
        const string method = _T("device.type");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string deviceType;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            deviceType = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return deviceType;
    }

    /* uid - Gets a unique id for the current app & device */
    std::string DeviceImpl::uid( Firebolt::Error *err ) const
    {
        const string method = _T("device.uid");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string uniqueId;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            uniqueId = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return uniqueId;
    }

    /* videoResolution - Get the maximum supported video resolution of the currently connected device and display. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160] */
    Resolution DeviceImpl::videoResolution( Firebolt::Error *err ) const
    {
        const string method = _T("device.videoResolution");
        
        
        Firebolt::Device::JsonData_Resolution jsonResult;
        Resolution videoResolution;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            ASSERT((jsonResult.Length() == 0) || (jsonResult.Length() == 2));
            if (jsonResult.Length() == 2) {
                videoResolution.first = jsonResult.Get(0);
                videoResolution.second = jsonResult.Get(1);
	    }

        }
        if (err != nullptr) {
            *err = status;
        }

        return videoResolution;
    }


    // Events
    /* onAudioChanged - Get the supported audio profiles for the connected devices. 

 It is not recommended to use this API for visual badging on content within your app since this does not reflect the settings of the user. */
    static void onAudioChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_AudioProfiles>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_AudioProfiles>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            AudioProfiles result;

            result.stereo = proxyResponse->Stereo;
            result.dolbyDigital5_1 = proxyResponse->DolbyDigital5_1;
            result.dolbyDigital5_1_plus = proxyResponse->DolbyDigital5_1_plus;
            result.dolbyAtmos = proxyResponse->DolbyAtmos;

            proxyResponse.Release();

            IDevice::IOnAudioChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnAudioChangedNotification*>(notification));
            notifier.onAudioChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnAudioChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onAudioChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Device::JsonData_AudioProfiles>(eventName, jsonParameters, onAudioChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnAudioChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onAudioChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onDeviceNameChanged - Get the human readable name of the device */
    static void onDeviceNameChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IDevice::IOnDeviceNameChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnDeviceNameChangedNotification*>(notification));
            notifier.onDeviceNameChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onDeviceNameChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onDeviceNameChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnDeviceNameChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onDeviceNameChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onHdcpChanged - Get the negotiated HDCP profiles for a connected device. 

 For devices that do not require additional connections (e.g. panels), `true` will be returned for all profiles. */
    static void onHdcpChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_HDCPVersionMap>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_HDCPVersionMap>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            HDCPVersionMap result;

            result.hdcp1_4 = proxyResponse->Hdcp1_4;
            result.hdcp2_2 = proxyResponse->Hdcp2_2;

            proxyResponse.Release();

            IDevice::IOnHdcpChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnHdcpChangedNotification*>(notification));
            notifier.onHdcpChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnHdcpChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onHdcpChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Device::JsonData_HDCPVersionMap>(eventName, jsonParameters, onHdcpChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnHdcpChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onHdcpChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onHdrChanged - Get the negotiated HDR formats for the connected display and device */
    static void onHdrChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_HDRFormatMap>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_HDRFormatMap>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            HDRFormatMap result;

            result.hdr10 = proxyResponse->Hdr10;
            result.hdr10Plus = proxyResponse->Hdr10Plus;
            result.dolbyVision = proxyResponse->DolbyVision;
            result.hlg = proxyResponse->Hlg;

            proxyResponse.Release();

            IDevice::IOnHdrChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnHdrChangedNotification*>(notification));
            notifier.onHdrChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnHdrChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onHdrChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Device::JsonData_HDRFormatMap>(eventName, jsonParameters, onHdrChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnHdrChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onHdrChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onNameChanged - The human readable name of the device */
    static void onNameChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IDevice::IOnNameChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnNameChangedNotification*>(notification));
            notifier.onNameChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onNameChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onNameChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnNameChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onNameChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onNetworkChanged - Get the current network status and type */
    static void onNetworkChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_NetworkInfoResult>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_NetworkInfoResult>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            NetworkInfoResult result;

            result.state = proxyResponse->State;
            result.type = proxyResponse->Type;

            proxyResponse.Release();

            IDevice::IOnNetworkChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnNetworkChangedNotification*>(notification));
            notifier.onNetworkChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnNetworkChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onNetworkChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Device::JsonData_NetworkInfoResult>(eventName, jsonParameters, onNetworkChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnNetworkChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onNetworkChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onScreenResolutionChanged - Get the resolution for the graphical surface of the app. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160] 

**Deprecated:** Use non-Firebolt APIs specific to your platform, e.g. W3C APIs */
    static void onScreenResolutionChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_Resolution>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_Resolution>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
Resolution result;

            result.first = proxyResponse->Get(0);
            result.second = proxyResponse->Get(1);
            proxyResponse.Release();

            IDevice::IOnScreenResolutionChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnScreenResolutionChangedNotification*>(notification));
            notifier.onScreenResolutionChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnScreenResolutionChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onScreenResolutionChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Device::JsonData_Resolution>(eventName, jsonParameters, onScreenResolutionChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnScreenResolutionChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onScreenResolutionChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onVideoResolutionChanged - Get the maximum supported video resolution of the currently connected device and display. 

The pairs returned will be of a [width, height] format and will correspond to the following values: 

NTSC Standard Definition (SD): [720, 480] 

PAL Standard Definition (SD): [720, 576] 

High Definition (HD): [1280, 720] 

Full HD (FHD): [1920, 1080]

4K Ultra High Definition (UHD): [3840, 2160] */
    static void onVideoResolutionChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_Resolution>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Device::JsonData_Resolution>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
Resolution result;

            result.first = proxyResponse->Get(0);
            result.second = proxyResponse->Get(1);
            proxyResponse.Release();

            IDevice::IOnVideoResolutionChangedNotification& notifier = *(reinterpret_cast<IDevice::IOnVideoResolutionChangedNotification*>(notification));
            notifier.onVideoResolutionChanged(result);
        }
    }
    void DeviceImpl::subscribe( IDevice::IOnVideoResolutionChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("device.onVideoResolutionChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Device::JsonData_Resolution>(eventName, jsonParameters, onVideoResolutionChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DeviceImpl::unsubscribe( IDevice::IOnVideoResolutionChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("device.onVideoResolutionChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Device
}


namespace WPEFramework {

    /* NetworkState The type of network that is currently active */
    ENUM_CONVERSION_BEGIN(Firebolt::Device::NetworkState)
        { Firebolt::Device::NetworkState::CONNECTED, _T("connected") },
        { Firebolt::Device::NetworkState::DISCONNECTED, _T("disconnected") },
    ENUM_CONVERSION_END(Firebolt::Device::NetworkState)

    /* NetworkType The type of network that is currently active */
    ENUM_CONVERSION_BEGIN(Firebolt::Device::NetworkType)
        { Firebolt::Device::NetworkType::WIFI, _T("wifi") },
        { Firebolt::Device::NetworkType::ETHERNET, _T("ethernet") },
        { Firebolt::Device::NetworkType::HYBRID, _T("hybrid") },
    ENUM_CONVERSION_END(Firebolt::Device::NetworkType)

}