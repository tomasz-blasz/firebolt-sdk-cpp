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

#include "capabilities_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Capabilities {

    // Methods
    /* available - Returns whether a capability is available now. */
    bool CapabilitiesImpl::available( const std::string& capability, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool available = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("capabilities.available", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Capabilities.available is successfully invoked");
            available = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return available;
    }

    /* granted - Returns whether the current App has a user grant for passed capability and role. */
    bool CapabilitiesImpl::granted( const std::string& capability, const std::optional<CapabilityOption>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool granted = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
            if (options.has_value()) {
                auto element = options.value();
                JsonData_CapabilityOption optionsContainer;
                if (element.role.has_value()) {
                    optionsContainer.Role = element.role.value();
                }
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("capabilities.granted", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Capabilities.granted is successfully invoked");
            granted = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return granted;
    }

    /* info - Returns an array of CapabilityInfo objects for the passed in capabilities. */
    std::vector<CapabilityInfo> CapabilitiesImpl::info( const std::vector<std::string>& capabilities, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::vector<CapabilityInfo> info;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::ArrayType<WPEFramework::Core::JSON::Variant> capabilitiesArray;
            for (auto& element : capabilities) {
                 capabilitiesArray.Add() = element;
            }
            WPEFramework::Core::JSON::Variant capabilitiesVariant;
            capabilitiesVariant.Array(capabilitiesArray);
            jsonParameters.Set(_T("capabilities"), capabilitiesVariant);
        WPEFramework::Core::JSON::ArrayType<Firebolt::Capabilities::JsonData_CapabilityInfo> jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("capabilities.info", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Capabilities.info is successfully invoked");
            auto index(jsonResult.Elements());
                while (index.Next() == true) {
                    CapabilityInfo infoResult1;
                    JsonData_CapabilityInfo jsonResult = index.Current();
                    if (jsonResult.Capability.IsSet()) {
                        infoResult1.capability = jsonResult.Capability.Value();
                    }
                    infoResult1.supported = jsonResult.Supported.Value();
                    infoResult1.available = jsonResult.Available.Value();
                    {
                      if (jsonResult.Use.Permitted.IsSet()) {
                            infoResult1.use.permitted = jsonResult.Use.Permitted;
                        }
                      if (jsonResult.Use.Granted.IsSet()) {
                            infoResult1.use.granted = jsonResult.Use.Granted;
                        }
                    }
                    {
                      if (jsonResult.Manage.Permitted.IsSet()) {
                            infoResult1.manage.permitted = jsonResult.Manage.Permitted;
                        }
                      if (jsonResult.Manage.Granted.IsSet()) {
                            infoResult1.manage.granted = jsonResult.Manage.Granted;
                        }
                    }
                    {
                      if (jsonResult.Provide.Permitted.IsSet()) {
                            infoResult1.provide.permitted = jsonResult.Provide.Permitted;
                        }
                      if (jsonResult.Provide.Granted.IsSet()) {
                            infoResult1.provide.granted = jsonResult.Provide.Granted;
                        }
                    }
                    if (jsonResult.Details.IsSet()) {
                        infoResult1.details = std::make_optional<std::vector<DenyReason>>();
                        auto detailsIndex(jsonResult.Details.Elements());
                        while (detailsIndex.Next() == true) {
                            infoResult1.details.value().push_back(detailsIndex.Current().Value());
                        }
                    }
                    info.push_back(infoResult1);
                }
        }

        if (err != nullptr) {
            *err = status;
        }

        return info;
    }

    /* permitted - Returns whether the current App has permission to the passed capability and role. */
    bool CapabilitiesImpl::permitted( const std::string& capability, const std::optional<CapabilityOption>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool permitted = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
            if (options.has_value()) {
                auto element = options.value();
                JsonData_CapabilityOption optionsContainer;
                if (element.role.has_value()) {
                    optionsContainer.Role = element.role.value();
                }
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("capabilities.permitted", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Capabilities.permitted is successfully invoked");
            permitted = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return permitted;
    }

    /* request - Requests grants for all capability/role combinations in the roles array. */
    std::vector<CapabilityInfo> CapabilitiesImpl::request( const std::vector<Permission>& grants, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::vector<CapabilityInfo> request;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::ArrayType<WPEFramework::Core::JSON::Variant> grantsArray;
            for (auto& element : grants) {
                JsonData_Permission grantsContainer;
                {
                        if (element.role.has_value()) {
                            grantsContainer.Role = element.role.value();
                        }
                        grantsContainer.Capability = element.capability;
                }
                string grantsStr;
                grantsContainer.ToString(grantsStr);
                WPEFramework::Core::JSON::VariantContainer grantsVariantContainer(grantsStr);
                WPEFramework::Core::JSON::Variant grantsVariant = grantsVariantContainer;
                grantsArray.Add() = grantsVariant;
            }
            WPEFramework::Core::JSON::Variant grantsVariant;
            grantsVariant.Array(grantsArray);
            jsonParameters.Set(_T("grants"), grantsVariant);
        WPEFramework::Core::JSON::ArrayType<Firebolt::Capabilities::JsonData_CapabilityInfo> jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("capabilities.request", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Capabilities.request is successfully invoked");
            auto index(jsonResult.Elements());
                while (index.Next() == true) {
                    CapabilityInfo requestResult1;
                    JsonData_CapabilityInfo jsonResult = index.Current();
                    if (jsonResult.Capability.IsSet()) {
                        requestResult1.capability = jsonResult.Capability.Value();
                    }
                    requestResult1.supported = jsonResult.Supported.Value();
                    requestResult1.available = jsonResult.Available.Value();
                    {
                      if (jsonResult.Use.Permitted.IsSet()) {
                            requestResult1.use.permitted = jsonResult.Use.Permitted;
                        }
                      if (jsonResult.Use.Granted.IsSet()) {
                            requestResult1.use.granted = jsonResult.Use.Granted;
                        }
                    }
                    {
                      if (jsonResult.Manage.Permitted.IsSet()) {
                            requestResult1.manage.permitted = jsonResult.Manage.Permitted;
                        }
                      if (jsonResult.Manage.Granted.IsSet()) {
                            requestResult1.manage.granted = jsonResult.Manage.Granted;
                        }
                    }
                    {
                      if (jsonResult.Provide.Permitted.IsSet()) {
                            requestResult1.provide.permitted = jsonResult.Provide.Permitted;
                        }
                      if (jsonResult.Provide.Granted.IsSet()) {
                            requestResult1.provide.granted = jsonResult.Provide.Granted;
                        }
                    }
                    if (jsonResult.Details.IsSet()) {
                        requestResult1.details = std::make_optional<std::vector<DenyReason>>();
                        auto detailsIndex(jsonResult.Details.Elements());
                        while (detailsIndex.Next() == true) {
                            requestResult1.details.value().push_back(detailsIndex.Current().Value());
                        }
                    }
                    request.push_back(requestResult1);
                }
        }

        if (err != nullptr) {
            *err = status;
        }

        return request;
    }

    /* supported - Returns whether the platform supports the passed capability. */
    bool CapabilitiesImpl::supported( const std::string& capability, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool supported = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("capabilities.supported", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Capabilities.supported is successfully invoked");
            supported = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return supported;
    }


    // Events
    /* onAvailable - Listens for all App permitted capabilities to become available. */
    static void onAvailableInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            CapabilityInfo result;

            if (proxyResponse->Capability.IsSet()) {
                result.capability = proxyResponse->Capability;
            }
            result.supported = proxyResponse->Supported;
            result.available = proxyResponse->Available;
            {
                if ((*proxyResponse).Use.Permitted.IsSet()) {
                    result.use.permitted = (*proxyResponse).Use.Permitted;
                }

            }
            {
                if ((*proxyResponse).Manage.Permitted.IsSet()) {
                    result.manage.permitted = (*proxyResponse).Manage.Permitted;
                }

            }
            {
                if ((*proxyResponse).Provide.Permitted.IsSet()) {
                    result.provide.permitted = (*proxyResponse).Provide.Permitted;
                }

            }
            if ((*proxyResponse).Details.IsSet()) {
                result.details = std::make_optional<std::vector<DenyReason>>();
                auto index((*proxyResponse).Details.Elements());
                while (index.Next() == true) {
                    result.details.value().push_back(index.Current().Value());
                }
            }

            proxyResponse.Release();

            ICapabilities::IOnAvailableNotification& notifier = *(reinterpret_cast<ICapabilities::IOnAvailableNotification*>(notification));
            notifier.onAvailable(result);
        }
    }
    void CapabilitiesImpl::subscribe( const std::string& capability, ICapabilities::IOnAvailableNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("capabilities.onAvailable");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
        jsonParameters.Set(_T("capability"), capabilityVariant);
        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Capabilities::JsonData_CapabilityInfo>(eventName, jsonParameters, onAvailableInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void CapabilitiesImpl::unsubscribe( ICapabilities::IOnAvailableNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("capabilities.onAvailable"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onGranted - Listens for all App permitted capabilities to become granted. */
    static void onGrantedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            CapabilityInfo result;

            if (proxyResponse->Capability.IsSet()) {
                result.capability = proxyResponse->Capability;
            }
            result.supported = proxyResponse->Supported;
            result.available = proxyResponse->Available;
            {
                if ((*proxyResponse).Use.Permitted.IsSet()) {
                    result.use.permitted = (*proxyResponse).Use.Permitted;
                }

            }
            {
                if ((*proxyResponse).Manage.Permitted.IsSet()) {
                    result.manage.permitted = (*proxyResponse).Manage.Permitted;
                }

            }
            {
                if ((*proxyResponse).Provide.Permitted.IsSet()) {
                    result.provide.permitted = (*proxyResponse).Provide.Permitted;
                }

            }
            if ((*proxyResponse).Details.IsSet()) {
                result.details = std::make_optional<std::vector<DenyReason>>();
                auto index((*proxyResponse).Details.Elements());
                while (index.Next() == true) {
                    result.details.value().push_back(index.Current().Value());
                }
            }

            proxyResponse.Release();

            ICapabilities::IOnGrantedNotification& notifier = *(reinterpret_cast<ICapabilities::IOnGrantedNotification*>(notification));
            notifier.onGranted(result);
        }
    }
    void CapabilitiesImpl::subscribe( const Role& role, const std::string& capability, ICapabilities::IOnGrantedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("capabilities.onGranted");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;
        JsonData_Role jsonRole = role;
        WPEFramework::Core::JSON::Variant roleVariant(jsonRole.Data());
        jsonParameters.Set(_T("role"), roleVariant);
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
        jsonParameters.Set(_T("capability"), capabilityVariant);
        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Capabilities::JsonData_CapabilityInfo>(eventName, jsonParameters, onGrantedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void CapabilitiesImpl::unsubscribe( ICapabilities::IOnGrantedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("capabilities.onGranted"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onRevoked - Listens for all App permitted capabilities to become revoked. */
    static void onRevokedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            CapabilityInfo result;

            if (proxyResponse->Capability.IsSet()) {
                result.capability = proxyResponse->Capability;
            }
            result.supported = proxyResponse->Supported;
            result.available = proxyResponse->Available;
            {
                if ((*proxyResponse).Use.Permitted.IsSet()) {
                    result.use.permitted = (*proxyResponse).Use.Permitted;
                }

            }
            {
                if ((*proxyResponse).Manage.Permitted.IsSet()) {
                    result.manage.permitted = (*proxyResponse).Manage.Permitted;
                }

            }
            {
                if ((*proxyResponse).Provide.Permitted.IsSet()) {
                    result.provide.permitted = (*proxyResponse).Provide.Permitted;
                }

            }
            if ((*proxyResponse).Details.IsSet()) {
                result.details = std::make_optional<std::vector<DenyReason>>();
                auto index((*proxyResponse).Details.Elements());
                while (index.Next() == true) {
                    result.details.value().push_back(index.Current().Value());
                }
            }

            proxyResponse.Release();

            ICapabilities::IOnRevokedNotification& notifier = *(reinterpret_cast<ICapabilities::IOnRevokedNotification*>(notification));
            notifier.onRevoked(result);
        }
    }
    void CapabilitiesImpl::subscribe( const Role& role, const std::string& capability, ICapabilities::IOnRevokedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("capabilities.onRevoked");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;
        JsonData_Role jsonRole = role;
        WPEFramework::Core::JSON::Variant roleVariant(jsonRole.Data());
        jsonParameters.Set(_T("role"), roleVariant);
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
        jsonParameters.Set(_T("capability"), capabilityVariant);
        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Capabilities::JsonData_CapabilityInfo>(eventName, jsonParameters, onRevokedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void CapabilitiesImpl::unsubscribe( ICapabilities::IOnRevokedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("capabilities.onRevoked"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onUnavailable - Listens for all App permitted capabilities to become unavailable. */
    static void onUnavailableInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Capabilities::JsonData_CapabilityInfo>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            CapabilityInfo result;

            if (proxyResponse->Capability.IsSet()) {
                result.capability = proxyResponse->Capability;
            }
            result.supported = proxyResponse->Supported;
            result.available = proxyResponse->Available;
            {
                if ((*proxyResponse).Use.Permitted.IsSet()) {
                    result.use.permitted = (*proxyResponse).Use.Permitted;
                }

            }
            {
                if ((*proxyResponse).Manage.Permitted.IsSet()) {
                    result.manage.permitted = (*proxyResponse).Manage.Permitted;
                }

            }
            {
                if ((*proxyResponse).Provide.Permitted.IsSet()) {
                    result.provide.permitted = (*proxyResponse).Provide.Permitted;
                }

            }
            if ((*proxyResponse).Details.IsSet()) {
                result.details = std::make_optional<std::vector<DenyReason>>();
                auto index((*proxyResponse).Details.Elements());
                while (index.Next() == true) {
                    result.details.value().push_back(index.Current().Value());
                }
            }

            proxyResponse.Release();

            ICapabilities::IOnUnavailableNotification& notifier = *(reinterpret_cast<ICapabilities::IOnUnavailableNotification*>(notification));
            notifier.onUnavailable(result);
        }
    }
    void CapabilitiesImpl::subscribe( const std::string& capability, ICapabilities::IOnUnavailableNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("capabilities.onUnavailable");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
        jsonParameters.Set(_T("capability"), capabilityVariant);
        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Capabilities::JsonData_CapabilityInfo>(eventName, jsonParameters, onUnavailableInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void CapabilitiesImpl::unsubscribe( ICapabilities::IOnUnavailableNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("capabilities.onUnavailable"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Capabilities
}

