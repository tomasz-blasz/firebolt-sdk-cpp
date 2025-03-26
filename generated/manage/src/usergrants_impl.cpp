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

#include "usergrants_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace UserGrants {

    // Methods
    /* app - Get all granted and denied user grants for the given app */
    std::vector<GrantInfo> UserGrantsImpl::app( const std::string& appId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::vector<GrantInfo> info;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant appIdVariant(appId);
            jsonParameters.Set(_T("appId"), appIdVariant);
        WPEFramework::Core::JSON::ArrayType<Firebolt::UserGrants::JsonData_GrantInfo> jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("usergrants.app", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "UserGrants.app is successfully invoked");
            auto index(jsonResult.Elements());
                while (index.Next() == true) {
                    GrantInfo infoResult1;
                    JsonData_GrantInfo jsonResult = index.Current();
                    if (jsonResult.App.IsSet()) {
                        infoResult1.app = std::make_optional<AppInfo>();
                      infoResult1.app.value().id = jsonResult.App.Id;
                      if (jsonResult.App.Title.IsSet()) {
                            infoResult1.app.value().title = jsonResult.App.Title;
                        }
                    }
                    infoResult1.state = jsonResult.State.Value();
                    infoResult1.capability = jsonResult.Capability.Value();
                    infoResult1.role = jsonResult.Role.Value();
                    infoResult1.lifespan = jsonResult.Lifespan.Value();
                    if (jsonResult.Expires.IsSet()) {
                        infoResult1.expires = jsonResult.Expires.Value();
                    }
                    info.push_back(infoResult1);
                }
        }

        if (err != nullptr) {
            *err = status;
        }

        return info;
    }

    /* capability - Get all granted and denied user grants for the given capability */
    std::vector<GrantInfo> UserGrantsImpl::capability( const std::string& capability, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::vector<GrantInfo> info;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
        WPEFramework::Core::JSON::ArrayType<Firebolt::UserGrants::JsonData_GrantInfo> jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("usergrants.capability", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "UserGrants.capability is successfully invoked");
            auto index(jsonResult.Elements());
                while (index.Next() == true) {
                    GrantInfo infoResult1;
                    JsonData_GrantInfo jsonResult = index.Current();
                    if (jsonResult.App.IsSet()) {
                        infoResult1.app = std::make_optional<AppInfo>();
                      infoResult1.app.value().id = jsonResult.App.Id;
                      if (jsonResult.App.Title.IsSet()) {
                            infoResult1.app.value().title = jsonResult.App.Title;
                        }
                    }
                    infoResult1.state = jsonResult.State.Value();
                    infoResult1.capability = jsonResult.Capability.Value();
                    infoResult1.role = jsonResult.Role.Value();
                    infoResult1.lifespan = jsonResult.Lifespan.Value();
                    if (jsonResult.Expires.IsSet()) {
                        infoResult1.expires = jsonResult.Expires.Value();
                    }
                    info.push_back(infoResult1);
                }
        }

        if (err != nullptr) {
            *err = status;
        }

        return info;
    }

    /* clear - Clears the grant for a given capability, to a specific app if appropriate. Calling this results in a persisted Denied Grant that lasts for the duration of the Grant Policy lifespan.  */
    void UserGrantsImpl::clear( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        Firebolt::Capabilities::JsonData_Role jsonRole = role;
            WPEFramework::Core::JSON::Variant roleVariant(jsonRole.Data());
            jsonParameters.Set(_T("role"), roleVariant);
            WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
            if (options.has_value()) {
                auto element = options.value();
                JsonData_GrantModificationOptions optionsContainer;
                if (element.appId.has_value()) {
                    optionsContainer.AppId = element.appId.value();
                }
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("usergrants.clear", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "UserGrants.clear is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* deny - Denies a given capability, to a specific app if appropriate. Calling this results in a persisted Denied Grant that lasts for the duration of the Grant Policy lifespan.  */
    void UserGrantsImpl::deny( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        Firebolt::Capabilities::JsonData_Role jsonRole = role;
            WPEFramework::Core::JSON::Variant roleVariant(jsonRole.Data());
            jsonParameters.Set(_T("role"), roleVariant);
            WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
            if (options.has_value()) {
                auto element = options.value();
                JsonData_GrantModificationOptions optionsContainer;
                if (element.appId.has_value()) {
                    optionsContainer.AppId = element.appId.value();
                }
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("usergrants.deny", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "UserGrants.deny is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* device - Get all granted and denied user grants for the device */
    std::vector<GrantInfo> UserGrantsImpl::device( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::vector<GrantInfo> info;

        JsonObject jsonParameters;

        WPEFramework::Core::JSON::ArrayType<Firebolt::UserGrants::JsonData_GrantInfo> jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("usergrants.device", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "UserGrants.device is successfully invoked");
            auto index(jsonResult.Elements());
                while (index.Next() == true) {
                    GrantInfo infoResult1;
                    JsonData_GrantInfo jsonResult = index.Current();
                    if (jsonResult.App.IsSet()) {
                        infoResult1.app = std::make_optional<AppInfo>();
                      infoResult1.app.value().id = jsonResult.App.Id;
                      if (jsonResult.App.Title.IsSet()) {
                            infoResult1.app.value().title = jsonResult.App.Title;
                        }
                    }
                    infoResult1.state = jsonResult.State.Value();
                    infoResult1.capability = jsonResult.Capability.Value();
                    infoResult1.role = jsonResult.Role.Value();
                    infoResult1.lifespan = jsonResult.Lifespan.Value();
                    if (jsonResult.Expires.IsSet()) {
                        infoResult1.expires = jsonResult.Expires.Value();
                    }
                    info.push_back(infoResult1);
                }
        }

        if (err != nullptr) {
            *err = status;
        }

        return info;
    }

    /* grant - Grants a given capability to a specific app, if appropriate. Calling this results in a persisted active grant that lasts for the duration of the grant policy lifespan.  */
    void UserGrantsImpl::grant( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        Firebolt::Capabilities::JsonData_Role jsonRole = role;
            WPEFramework::Core::JSON::Variant roleVariant(jsonRole.Data());
            jsonParameters.Set(_T("role"), roleVariant);
            WPEFramework::Core::JSON::Variant capabilityVariant(capability);
            jsonParameters.Set(_T("capability"), capabilityVariant);
            if (options.has_value()) {
                auto element = options.value();
                JsonData_GrantModificationOptions optionsContainer;
                if (element.appId.has_value()) {
                    optionsContainer.AppId = element.appId.value();
                }
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("usergrants.grant", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "UserGrants.grant is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* request - Requests Firebolt to carry out a set of user grants for a given application such that the user grant provider is notified or an existing user grant is reused. */
    std::vector<GrantInfo> UserGrantsImpl::request( const std::string& appId, const std::vector<Capabilities::Permission>& permissions, const std::optional<RequestOptions>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::vector<GrantInfo> info;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant appIdVariant(appId);
            jsonParameters.Set(_T("appId"), appIdVariant);
            WPEFramework::Core::JSON::ArrayType<WPEFramework::Core::JSON::Variant> permissionsArray;
            for (auto& element : permissions) {
                Firebolt::Capabilities::JsonData_Permission permissionsContainer;
                {
                        if (element.role.has_value()) {
                            permissionsContainer.Role = element.role.value();
                        }
                        permissionsContainer.Capability = element.capability;
                }
                string permissionsStr;
                permissionsContainer.ToString(permissionsStr);
                WPEFramework::Core::JSON::VariantContainer permissionsVariantContainer(permissionsStr);
                WPEFramework::Core::JSON::Variant permissionsVariant = permissionsVariantContainer;
                permissionsArray.Add() = permissionsVariant;
            }
            WPEFramework::Core::JSON::Variant permissionsVariant;
            permissionsVariant.Array(permissionsArray);
            jsonParameters.Set(_T("permissions"), permissionsVariant);
            if (options.has_value()) {
                auto element = options.value();
                JsonData_RequestOptions optionsContainer;
                if (element.force.has_value()) {
                    optionsContainer.Force = element.force.value();
                }
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        WPEFramework::Core::JSON::ArrayType<Firebolt::UserGrants::JsonData_GrantInfo> jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("usergrants.request", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "UserGrants.request is successfully invoked");
            auto index(jsonResult.Elements());
                while (index.Next() == true) {
                    GrantInfo infoResult1;
                    JsonData_GrantInfo jsonResult = index.Current();
                    if (jsonResult.App.IsSet()) {
                        infoResult1.app = std::make_optional<AppInfo>();
                      infoResult1.app.value().id = jsonResult.App.Id;
                      if (jsonResult.App.Title.IsSet()) {
                            infoResult1.app.value().title = jsonResult.App.Title;
                        }
                    }
                    infoResult1.state = jsonResult.State.Value();
                    infoResult1.capability = jsonResult.Capability.Value();
                    infoResult1.role = jsonResult.Role.Value();
                    infoResult1.lifespan = jsonResult.Lifespan.Value();
                    if (jsonResult.Expires.IsSet()) {
                        infoResult1.expires = jsonResult.Expires.Value();
                    }
                    info.push_back(infoResult1);
                }
        }

        if (err != nullptr) {
            *err = status;
        }

        return info;
    }


    // Events

}//namespace UserGrants
}


namespace WPEFramework {

    /* GrantState The state the grant is in */
    ENUM_CONVERSION_BEGIN(Firebolt::UserGrants::GrantState)
        { Firebolt::UserGrants::GrantState::GRANTED, _T("granted") },
        { Firebolt::UserGrants::GrantState::DENIED, _T("denied") },
    ENUM_CONVERSION_END(Firebolt::UserGrants::GrantState)

    /* GrantInfoLifespan  */
    ENUM_CONVERSION_BEGIN(Firebolt::UserGrants::GrantInfoLifespan)
        { Firebolt::UserGrants::GrantInfoLifespan::ONCE, _T("once") },
        { Firebolt::UserGrants::GrantInfoLifespan::FOREVER, _T("forever") },
        { Firebolt::UserGrants::GrantInfoLifespan::APP_ACTIVE, _T("appActive") },
        { Firebolt::UserGrants::GrantInfoLifespan::POWER_ACTIVE, _T("powerActive") },
        { Firebolt::UserGrants::GrantInfoLifespan::SECONDS, _T("seconds") },
    ENUM_CONVERSION_END(Firebolt::UserGrants::GrantInfoLifespan)

}
