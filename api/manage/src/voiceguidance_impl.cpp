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

#include "voiceguidance_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace VoiceGuidance {

    // Methods
    /* enabled - Whether or not voice-guidance is enabled. */
    bool VoiceGuidanceImpl::enabled( Firebolt::Error *err ) const
    {
        const string method = _T("voiceguidance.enabled");
        
        
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
    /* setEnabled - Whether or not voice-guidance is enabled. */
    void VoiceGuidanceImpl::setEnabled( const bool value, Firebolt::Error *err )
    {
        const string method = _T("voiceguidance.setEnabled");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* navigationHints - The user's preference for whether additional navigation hints should be synthesized. */
    bool VoiceGuidanceImpl::navigationHints( Firebolt::Error *err ) const
    {
        const string method = _T("voiceguidance.navigationHints");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool navigationHints = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            navigationHints = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return navigationHints;
    }
    /* setNavigationHints - The user's preference for whether additional navigation hints should be synthesized. */
    void VoiceGuidanceImpl::setNavigationHints( const bool value, Firebolt::Error *err )
    {
        const string method = _T("voiceguidance.setNavigationHints");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* rate - The rate at which voice guidance speech will be read back to the user. */
    float VoiceGuidanceImpl::rate( Firebolt::Error *err ) const
    {
        const string method = _T("voiceguidance.rate");
        
        
        WPEFramework::Core::JSON::Float jsonResult;
        float rate = 0;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            rate = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return rate;
    }
    /* setRate - The rate at which voice guidance speech will be read back to the user. */
    void VoiceGuidanceImpl::setRate( const float& value, Firebolt::Error *err )
    {
        const string method = _T("voiceguidance.setRate");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* speed - The speed at which voice guidance speech will be read back to the user. */
    float VoiceGuidanceImpl::speed( Firebolt::Error *err ) const
    {
        const string method = _T("voiceguidance.speed");
        
        
        WPEFramework::Core::JSON::Float jsonResult;
        float speed = 0;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            speed = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return speed;
    }
    /* setSpeed - The speed at which voice guidance speech will be read back to the user. */
    void VoiceGuidanceImpl::setSpeed( const float& value, Firebolt::Error *err )
    {
        const string method = _T("voiceguidance.setSpeed");

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
    /* onEnabledChanged - Whether or not voice-guidance is enabled. */
    static void onEnabledChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IVoiceGuidance::IOnEnabledChangedNotification& notifier = *(reinterpret_cast<IVoiceGuidance::IOnEnabledChangedNotification*>(notification));
            notifier.onEnabledChanged(result);
        }
    }
    void VoiceGuidanceImpl::subscribe( IVoiceGuidance::IOnEnabledChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("voiceguidance.onEnabledChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onEnabledChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void VoiceGuidanceImpl::unsubscribe( IVoiceGuidance::IOnEnabledChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("voiceguidance.onEnabledChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onNavigationHintsChanged - The user's preference for whether additional navigation hints should be synthesized. */
    static void onNavigationHintsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IVoiceGuidance::IOnNavigationHintsChangedNotification& notifier = *(reinterpret_cast<IVoiceGuidance::IOnNavigationHintsChangedNotification*>(notification));
            notifier.onNavigationHintsChanged(result);
        }
    }
    void VoiceGuidanceImpl::subscribe( IVoiceGuidance::IOnNavigationHintsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("voiceguidance.onNavigationHintsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onNavigationHintsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void VoiceGuidanceImpl::unsubscribe( IVoiceGuidance::IOnNavigationHintsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("voiceguidance.onNavigationHintsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onRateChanged - The rate at which voice guidance speech will be read back to the user. */
    static void onRateChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            float result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IVoiceGuidance::IOnRateChangedNotification& notifier = *(reinterpret_cast<IVoiceGuidance::IOnRateChangedNotification*>(notification));
            notifier.onRateChanged(result);
        }
    }
    void VoiceGuidanceImpl::subscribe( IVoiceGuidance::IOnRateChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("voiceguidance.onRateChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Float>(eventName, jsonParameters, onRateChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void VoiceGuidanceImpl::unsubscribe( IVoiceGuidance::IOnRateChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("voiceguidance.onRateChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onSpeedChanged - The speed at which voice guidance speech will be read back to the user. */
    static void onSpeedChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            float result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IVoiceGuidance::IOnSpeedChangedNotification& notifier = *(reinterpret_cast<IVoiceGuidance::IOnSpeedChangedNotification*>(notification));
            notifier.onSpeedChanged(result);
        }
    }
    void VoiceGuidanceImpl::subscribe( IVoiceGuidance::IOnSpeedChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("voiceguidance.onSpeedChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Float>(eventName, jsonParameters, onSpeedChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void VoiceGuidanceImpl::unsubscribe( IVoiceGuidance::IOnSpeedChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("voiceguidance.onSpeedChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace VoiceGuidance
}

