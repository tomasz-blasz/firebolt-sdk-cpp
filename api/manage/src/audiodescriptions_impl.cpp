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

#include "audiodescriptions_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace AudioDescriptions {

    // Methods
    /* enabled - Whether or not audio-descriptions are enabled. */
    bool AudioDescriptionsImpl::enabled( Firebolt::Error *err ) const
    {
        const string method = _T("audiodescriptions.enabled");
        
        
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
    /* setEnabled - Whether or not audio-descriptions are enabled. */
    void AudioDescriptionsImpl::setEnabled( const bool value, Firebolt::Error *err )
    {
        const string method = _T("audiodescriptions.setEnabled");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }


    // Events
    /* onEnabledChanged - Whether or not audio-descriptions are enabled. */
    static void onEnabledChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IAudioDescriptions::IOnEnabledChangedNotification& notifier = *(reinterpret_cast<IAudioDescriptions::IOnEnabledChangedNotification*>(notification));
            notifier.onEnabledChanged(result);
        }
    }
    void AudioDescriptionsImpl::subscribe( IAudioDescriptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("audiodescriptions.onEnabledChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onEnabledChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void AudioDescriptionsImpl::unsubscribe( IAudioDescriptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("audiodescriptions.onEnabledChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace AudioDescriptions
}

