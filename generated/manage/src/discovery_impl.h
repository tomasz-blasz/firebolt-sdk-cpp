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

#include "discovery.h"


namespace Firebolt {
namespace Discovery {


    // Types
    class JsonData_Event: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_Event() override = default;
  
    public:
        JsonData_Event()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("appId"), &AppId);
        }

        JsonData_Event(const JsonData_Event& other)
        {
            Add(_T("appId"), &AppId);
            AppId = other.AppId;
        }

        JsonData_Event& operator=(const JsonData_Event& other)
        {
            Add(_T("appId"), &AppId);
            AppId = other.AppId;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String AppId;
    };

    class DiscoveryImpl : public IDiscovery, public IModule {

    public:
        DiscoveryImpl() = default;
        DiscoveryImpl(const DiscoveryImpl&) = delete;
        DiscoveryImpl& operator=(const DiscoveryImpl&) = delete;

        ~DiscoveryImpl() override = default;

        // Methods & Events
        // signature callback params: 
        // method result properties : 
        void subscribe( IDiscovery::IOnSignInNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDiscovery::IOnSignInNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IDiscovery::IOnSignOutNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IDiscovery::IOnSignOutNotification& notification, Firebolt::Error *err = nullptr ) override;

    };

}//namespace Discovery
}
