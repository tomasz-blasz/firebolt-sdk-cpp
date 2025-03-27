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
#include "jsondata_capabilities.h"

#include "usergrants.h"


namespace Firebolt {
namespace UserGrants {


    using JsonData_GrantState = WPEFramework::Core::JSON::EnumType<GrantState>;

    using JsonData_GrantInfoLifespan = WPEFramework::Core::JSON::EnumType<GrantInfoLifespan>;


    // Types
    class JsonData_RequestOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_RequestOptions() override = default;
  
    public:
        JsonData_RequestOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("force"), &Force);
        }

        JsonData_RequestOptions(const JsonData_RequestOptions& other)
        {
            Add(_T("force"), &Force);
            Force = other.Force;
        }

        JsonData_RequestOptions& operator=(const JsonData_RequestOptions& other)
        {
            Add(_T("force"), &Force);
            Force = other.Force;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Force;
    };

    class JsonData_AppInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AppInfo() override = default;
  
    public:
        JsonData_AppInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("id"), &Id);
            Add(_T("title"), &Title);
        }

        JsonData_AppInfo(const JsonData_AppInfo& other)
        {
            Add(_T("id"), &Id);
            Id = other.Id;
            Add(_T("title"), &Title);
            Title = other.Title;
        }

        JsonData_AppInfo& operator=(const JsonData_AppInfo& other)
        {
            Add(_T("id"), &Id);
            Id = other.Id;
            Add(_T("title"), &Title);
            Title = other.Title;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Id;
        FireboltSDK::JSON::String Title;
    };

    class JsonData_GrantInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_GrantInfo() override = default;
  
    public:
        JsonData_GrantInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("app"), &App);
            Add(_T("state"), &State);
            Add(_T("capability"), &Capability);
            Add(_T("role"), &Role);
            Add(_T("lifespan"), &Lifespan);
            Add(_T("expires"), &Expires);
        }

        JsonData_GrantInfo(const JsonData_GrantInfo& other)
        {
            Add(_T("app"), &App);
            App = other.App;
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("capability"), &Capability);
            Capability = other.Capability;
            Add(_T("role"), &Role);
            Role = other.Role;
            Add(_T("lifespan"), &Lifespan);
            Lifespan = other.Lifespan;
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
        }

        JsonData_GrantInfo& operator=(const JsonData_GrantInfo& other)
        {
            Add(_T("app"), &App);
            App = other.App;
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("capability"), &Capability);
            Capability = other.Capability;
            Add(_T("role"), &Role);
            Role = other.Role;
            Add(_T("lifespan"), &Lifespan);
            Lifespan = other.Lifespan;
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            return (*this);
        }

    public:
        Firebolt::UserGrants::JsonData_AppInfo App;
        Firebolt::UserGrants::JsonData_GrantState State;
        FireboltSDK::JSON::String Capability;
        Firebolt::Capabilities::JsonData_Role Role;
        Firebolt::UserGrants::JsonData_GrantInfoLifespan Lifespan;
        FireboltSDK::JSON::String Expires;
    };

    class JsonData_GrantModificationOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_GrantModificationOptions() override = default;
  
    public:
        JsonData_GrantModificationOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("appId"), &AppId);
        }

        JsonData_GrantModificationOptions(const JsonData_GrantModificationOptions& other)
        {
            Add(_T("appId"), &AppId);
            AppId = other.AppId;
        }

        JsonData_GrantModificationOptions& operator=(const JsonData_GrantModificationOptions& other)
        {
            Add(_T("appId"), &AppId);
            AppId = other.AppId;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String AppId;
    };

    class UserGrantsImpl : public IUserGrants, public IModule {

    public:
        UserGrantsImpl() = default;
        UserGrantsImpl(const UserGrantsImpl&) = delete;
        UserGrantsImpl& operator=(const UserGrantsImpl&) = delete;

        ~UserGrantsImpl() override = default;

        // Methods & Events
        /*
         app
         Get all granted and denied user grants for the given app
         */
        std::vector<GrantInfo> app( const std::string& appId, Firebolt::Error *err = nullptr ) override;

        /*
         capability
         Get all granted and denied user grants for the given capability
         */
        std::vector<GrantInfo> capability( const std::string& capability, Firebolt::Error *err = nullptr ) override;

        /*
         clear
         Clears the grant for a given capability, to a specific app if appropriate. Calling this results in a persisted Denied Grant that lasts for the duration of the Grant Policy lifespan. 
         */
        void clear( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err = nullptr ) override;

        /*
         deny
         Denies a given capability, to a specific app if appropriate. Calling this results in a persisted Denied Grant that lasts for the duration of the Grant Policy lifespan. 
         */
        void deny( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err = nullptr ) override;

        /*
         device
         Get all granted and denied user grants for the device
         */
        std::vector<GrantInfo> device( Firebolt::Error *err = nullptr ) const override;

        /*
         grant
         Grants a given capability to a specific app, if appropriate. Calling this results in a persisted active grant that lasts for the duration of the grant policy lifespan. 
         */
        void grant( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err = nullptr ) override;

        /*
         request
         Requests Firebolt to carry out a set of user grants for a given application such that the user grant provider is notified or an existing user grant is reused.
         */
        std::vector<GrantInfo> request( const std::string& appId, const std::vector<Capabilities::Permission>& permissions, const std::optional<RequestOptions>& options, Firebolt::Error *err = nullptr ) override;

    };

}//namespace UserGrants
}
