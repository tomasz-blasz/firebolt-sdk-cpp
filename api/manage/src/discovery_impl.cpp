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

#include "discovery_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Discovery {

    // Methods

    // Events
    /* onSignIn - Listen to events from all apps that call Discovery.signIn */
    static void onSignInInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Discovery::JsonData_Event>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Discovery::JsonData_Event>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            Event result;

            result.appId = proxyResponse->AppId;

            proxyResponse.Release();

            IDiscovery::IOnSignInNotification& notifier = *(reinterpret_cast<IDiscovery::IOnSignInNotification*>(notification));
            notifier.onSignIn(result);
        }
    }
    void DiscoveryImpl::subscribe( IDiscovery::IOnSignInNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("discovery.onSignIn");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Discovery::JsonData_Event>(eventName, jsonParameters, onSignInInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DiscoveryImpl::unsubscribe( IDiscovery::IOnSignInNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("discovery.onSignIn"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onSignOut - Listen to events from all apps that call Discovery.signOut */
    static void onSignOutInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Discovery::JsonData_Event>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Discovery::JsonData_Event>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            Event result;

            result.appId = proxyResponse->AppId;

            proxyResponse.Release();

            IDiscovery::IOnSignOutNotification& notifier = *(reinterpret_cast<IDiscovery::IOnSignOutNotification*>(notification));
            notifier.onSignOut(result);
        }
    }
    void DiscoveryImpl::subscribe( IDiscovery::IOnSignOutNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("discovery.onSignOut");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Discovery::JsonData_Event>(eventName, jsonParameters, onSignOutInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void DiscoveryImpl::unsubscribe( IDiscovery::IOnSignOutNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("discovery.onSignOut"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Discovery
}

