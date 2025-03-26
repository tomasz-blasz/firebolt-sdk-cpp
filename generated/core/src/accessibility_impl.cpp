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

#include "accessibility_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Accessibility {

    // Methods
    /* audioDescriptionSettings - Get the user's preferred audio description settings */
    AudioDescriptionSettings AccessibilityImpl::audioDescriptionSettings( Firebolt::Error *err ) const
    {
        const string method = _T("accessibility.audioDescriptionSettings");
        
        
        Firebolt::Accessibility::JsonData_AudioDescriptionSettings jsonResult;
        AudioDescriptionSettings settings;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            AudioDescriptionSettings settingsResult;
            settingsResult.enabled = jsonResult.Enabled.Value();
            settings = settingsResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return settings;
    }

    /* closedCaptions - Get the user's preferred closed-captions settings */
    ClosedCaptionsSettings AccessibilityImpl::closedCaptions( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        ClosedCaptionsSettings closedCaptionsSettings;

        JsonObject jsonParameters;

        Firebolt::Accessibility::JsonData_ClosedCaptionsSettings jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("accessibility.closedCaptions", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Accessibility.closedCaptions is successfully invoked");
            ClosedCaptionsSettings closedCaptionsSettingsResult;
                closedCaptionsSettingsResult.enabled = jsonResult.Enabled.Value();
                if (jsonResult.Styles.IsSet()) {
                    closedCaptionsSettingsResult.styles = std::make_optional<ClosedCaptionsStyles>();
                  if (jsonResult.Styles.FontFamily.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().fontFamily = jsonResult.Styles.FontFamily;
                    }
                  if (jsonResult.Styles.FontSize.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().fontSize = jsonResult.Styles.FontSize;
                    }
                  if (jsonResult.Styles.FontColor.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().fontColor = jsonResult.Styles.FontColor;
                    }
                  if (jsonResult.Styles.FontEdge.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().fontEdge = jsonResult.Styles.FontEdge;
                    }
                  if (jsonResult.Styles.FontEdgeColor.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().fontEdgeColor = jsonResult.Styles.FontEdgeColor;
                    }
                  if (jsonResult.Styles.FontOpacity.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().fontOpacity = jsonResult.Styles.FontOpacity;
                    }
                  if (jsonResult.Styles.BackgroundColor.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().backgroundColor = jsonResult.Styles.BackgroundColor;
                    }
                  if (jsonResult.Styles.BackgroundOpacity.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().backgroundOpacity = jsonResult.Styles.BackgroundOpacity;
                    }
                  if (jsonResult.Styles.TextAlign.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().textAlign = jsonResult.Styles.TextAlign;
                    }
                  if (jsonResult.Styles.TextAlignVertical.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().textAlignVertical = jsonResult.Styles.TextAlignVertical;
                    }
                  if (jsonResult.Styles.WindowColor.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().windowColor = jsonResult.Styles.WindowColor;
                    }
                  if (jsonResult.Styles.WindowOpacity.IsSet()) {
                        closedCaptionsSettingsResult.styles.value().windowOpacity = jsonResult.Styles.WindowOpacity;
                    }
                }
                if (jsonResult.PreferredLanguages.IsSet()) {
                    closedCaptionsSettingsResult.preferredLanguages = std::make_optional<std::vector<std::string>>();
                    auto preferredLanguagesIndex(jsonResult.PreferredLanguages.Elements());
                    while (preferredLanguagesIndex.Next() == true) {
                        closedCaptionsSettingsResult.preferredLanguages.value().push_back(preferredLanguagesIndex.Current().Value());
                    }
                }
                closedCaptionsSettings = closedCaptionsSettingsResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return closedCaptionsSettings;
    }

    /* closedCaptionsSettings - Get the user's preferred closed-captions settings */
    ClosedCaptionsSettings AccessibilityImpl::closedCaptionsSettings( Firebolt::Error *err ) const
    {
        const string method = _T("accessibility.closedCaptionsSettings");
        
        
        Firebolt::Accessibility::JsonData_ClosedCaptionsSettings jsonResult;
        ClosedCaptionsSettings closedCaptionsSettings;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            ClosedCaptionsSettings closedCaptionsSettingsResult;
            closedCaptionsSettingsResult.enabled = jsonResult.Enabled.Value();
            if (jsonResult.Styles.IsSet()) {
                closedCaptionsSettingsResult.styles = std::make_optional<ClosedCaptionsStyles>();
              if (jsonResult.Styles.FontFamily.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().fontFamily = jsonResult.Styles.FontFamily;
                }
              if (jsonResult.Styles.FontSize.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().fontSize = jsonResult.Styles.FontSize;
                }
              if (jsonResult.Styles.FontColor.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().fontColor = jsonResult.Styles.FontColor;
                }
              if (jsonResult.Styles.FontEdge.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().fontEdge = jsonResult.Styles.FontEdge;
                }
              if (jsonResult.Styles.FontEdgeColor.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().fontEdgeColor = jsonResult.Styles.FontEdgeColor;
                }
              if (jsonResult.Styles.FontOpacity.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().fontOpacity = jsonResult.Styles.FontOpacity;
                }
              if (jsonResult.Styles.BackgroundColor.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().backgroundColor = jsonResult.Styles.BackgroundColor;
                }
              if (jsonResult.Styles.BackgroundOpacity.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().backgroundOpacity = jsonResult.Styles.BackgroundOpacity;
                }
              if (jsonResult.Styles.TextAlign.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().textAlign = jsonResult.Styles.TextAlign;
                }
              if (jsonResult.Styles.TextAlignVertical.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().textAlignVertical = jsonResult.Styles.TextAlignVertical;
                }
              if (jsonResult.Styles.WindowColor.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().windowColor = jsonResult.Styles.WindowColor;
                }
              if (jsonResult.Styles.WindowOpacity.IsSet()) {
                    closedCaptionsSettingsResult.styles.value().windowOpacity = jsonResult.Styles.WindowOpacity;
                }
            }
            if (jsonResult.PreferredLanguages.IsSet()) {
                closedCaptionsSettingsResult.preferredLanguages = std::make_optional<std::vector<std::string>>();
                auto preferredLanguagesIndex(jsonResult.PreferredLanguages.Elements());
                while (preferredLanguagesIndex.Next() == true) {
                    closedCaptionsSettingsResult.preferredLanguages.value().push_back(preferredLanguagesIndex.Current().Value());
                }
            }
            closedCaptionsSettings = closedCaptionsSettingsResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return closedCaptionsSettings;
    }

    /* highContrastUI - The user's preference for a high-contrast UI */
    bool AccessibilityImpl::highContrastUI( Firebolt::Error *err ) const
    {
        const string method = _T("accessibility.highContrastUI");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool highContrastUI = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            highContrastUI = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return highContrastUI;
    }

    /* voiceGuidance - Get the user's preferred voice guidance settings */
    VoiceGuidanceSettings AccessibilityImpl::voiceGuidance( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        VoiceGuidanceSettings settings;

        JsonObject jsonParameters;

        Firebolt::Accessibility::JsonData_VoiceGuidanceSettings jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("accessibility.voiceGuidance", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Accessibility.voiceGuidance is successfully invoked");
            VoiceGuidanceSettings settingsResult;
                settingsResult.enabled = jsonResult.Enabled.Value();
                settingsResult.navigationHints = jsonResult.NavigationHints.Value();
                settingsResult.rate = jsonResult.Rate.Value();
                if (jsonResult.Speed.IsSet()) {
                    settingsResult.speed = jsonResult.Speed.Value();
                }
                settings = settingsResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return settings;
    }

    /* voiceGuidanceSettings - Get the user's preferred voice guidance settings */
    VoiceGuidanceSettings AccessibilityImpl::voiceGuidanceSettings( Firebolt::Error *err ) const
    {
        const string method = _T("accessibility.voiceGuidanceSettings");
        
        
        Firebolt::Accessibility::JsonData_VoiceGuidanceSettings jsonResult;
        VoiceGuidanceSettings settings;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            VoiceGuidanceSettings settingsResult;
            settingsResult.enabled = jsonResult.Enabled.Value();
            settingsResult.navigationHints = jsonResult.NavigationHints.Value();
            settingsResult.rate = jsonResult.Rate.Value();
            if (jsonResult.Speed.IsSet()) {
                settingsResult.speed = jsonResult.Speed.Value();
            }
            settings = settingsResult;
        }
        if (err != nullptr) {
            *err = status;
        }

        return settings;
    }


    // Events
    /* onAudioDescriptionSettingsChanged - Get the user's preferred audio description settings */
    static void onAudioDescriptionSettingsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_AudioDescriptionSettings>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_AudioDescriptionSettings>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            AudioDescriptionSettings result;

            result.enabled = proxyResponse->Enabled;

            proxyResponse.Release();

            IAccessibility::IOnAudioDescriptionSettingsChangedNotification& notifier = *(reinterpret_cast<IAccessibility::IOnAudioDescriptionSettingsChangedNotification*>(notification));
            notifier.onAudioDescriptionSettingsChanged(result);
        }
    }
    void AccessibilityImpl::subscribe( IAccessibility::IOnAudioDescriptionSettingsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("accessibility.onAudioDescriptionSettingsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Accessibility::JsonData_AudioDescriptionSettings>(eventName, jsonParameters, onAudioDescriptionSettingsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void AccessibilityImpl::unsubscribe( IAccessibility::IOnAudioDescriptionSettingsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("accessibility.onAudioDescriptionSettingsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onClosedCaptionsSettingsChanged - Get the user's preferred closed-captions settings */
    static void onClosedCaptionsSettingsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_ClosedCaptionsSettings>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_ClosedCaptionsSettings>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            ClosedCaptionsSettings result;

            result.enabled = proxyResponse->Enabled;
            if ((*proxyResponse).Styles.IsSet()) {
                result.styles = std::make_optional<ClosedCaptionsStyles>();
                if ((*proxyResponse).Styles.FontFamily.IsSet()) {
                    result.styles.value().fontFamily = (*proxyResponse).Styles.FontFamily;
                }
                if ((*proxyResponse).Styles.FontSize.IsSet()) {
                    result.styles.value().fontSize = (*proxyResponse).Styles.FontSize;
                }
                if ((*proxyResponse).Styles.FontColor.IsSet()) {
                    result.styles.value().fontColor = (*proxyResponse).Styles.FontColor;
                }
                if ((*proxyResponse).Styles.FontEdge.IsSet()) {
                    result.styles.value().fontEdge = (*proxyResponse).Styles.FontEdge;
                }
                if ((*proxyResponse).Styles.FontEdgeColor.IsSet()) {
                    result.styles.value().fontEdgeColor = (*proxyResponse).Styles.FontEdgeColor;
                }
                if ((*proxyResponse).Styles.FontOpacity.IsSet()) {
                    result.styles.value().fontOpacity = (*proxyResponse).Styles.FontOpacity;
                }
                if ((*proxyResponse).Styles.BackgroundColor.IsSet()) {
                    result.styles.value().backgroundColor = (*proxyResponse).Styles.BackgroundColor;
                }
                if ((*proxyResponse).Styles.BackgroundOpacity.IsSet()) {
                    result.styles.value().backgroundOpacity = (*proxyResponse).Styles.BackgroundOpacity;
                }
                if ((*proxyResponse).Styles.TextAlign.IsSet()) {
                    result.styles.value().textAlign = (*proxyResponse).Styles.TextAlign;
                }
                if ((*proxyResponse).Styles.TextAlignVertical.IsSet()) {
                    result.styles.value().textAlignVertical = (*proxyResponse).Styles.TextAlignVertical;
                }
                if ((*proxyResponse).Styles.WindowColor.IsSet()) {
                    result.styles.value().windowColor = (*proxyResponse).Styles.WindowColor;
                }
                if ((*proxyResponse).Styles.WindowOpacity.IsSet()) {
                    result.styles.value().windowOpacity = (*proxyResponse).Styles.WindowOpacity;
                }
            }
            if ((*proxyResponse).PreferredLanguages.IsSet()) {
                result.preferredLanguages = std::make_optional<std::vector<std::string>>();
                auto index((*proxyResponse).PreferredLanguages.Elements());
                while (index.Next() == true) {
                    result.preferredLanguages.value().push_back(index.Current().Value());
                }
            }

            proxyResponse.Release();

            IAccessibility::IOnClosedCaptionsSettingsChangedNotification& notifier = *(reinterpret_cast<IAccessibility::IOnClosedCaptionsSettingsChangedNotification*>(notification));
            notifier.onClosedCaptionsSettingsChanged(result);
        }
    }
    void AccessibilityImpl::subscribe( IAccessibility::IOnClosedCaptionsSettingsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("accessibility.onClosedCaptionsSettingsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Accessibility::JsonData_ClosedCaptionsSettings>(eventName, jsonParameters, onClosedCaptionsSettingsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void AccessibilityImpl::unsubscribe( IAccessibility::IOnClosedCaptionsSettingsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("accessibility.onClosedCaptionsSettingsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onHighContrastUIChanged - The user's preference for a high-contrast UI */
    static void onHighContrastUIChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IAccessibility::IOnHighContrastUIChangedNotification& notifier = *(reinterpret_cast<IAccessibility::IOnHighContrastUIChangedNotification*>(notification));
            notifier.onHighContrastUIChanged(result);
        }
    }
    void AccessibilityImpl::subscribe( IAccessibility::IOnHighContrastUIChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("accessibility.onHighContrastUIChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onHighContrastUIChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void AccessibilityImpl::unsubscribe( IAccessibility::IOnHighContrastUIChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("accessibility.onHighContrastUIChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onVoiceGuidanceSettingsChanged - Get the user's preferred voice guidance settings */
    static void onVoiceGuidanceSettingsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_VoiceGuidanceSettings>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_VoiceGuidanceSettings>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            VoiceGuidanceSettings result;

            result.enabled = proxyResponse->Enabled;
            result.navigationHints = proxyResponse->NavigationHints;
            result.rate = proxyResponse->Rate;
            if (proxyResponse->Speed.IsSet()) {
                result.speed = proxyResponse->Speed;
            }

            proxyResponse.Release();

            IAccessibility::IOnVoiceGuidanceSettingsChangedNotification& notifier = *(reinterpret_cast<IAccessibility::IOnVoiceGuidanceSettingsChangedNotification*>(notification));
            notifier.onVoiceGuidanceSettingsChanged(result);
        }
    }
    void AccessibilityImpl::subscribe( IAccessibility::IOnVoiceGuidanceSettingsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("accessibility.onVoiceGuidanceSettingsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Accessibility::JsonData_VoiceGuidanceSettings>(eventName, jsonParameters, onVoiceGuidanceSettingsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void AccessibilityImpl::unsubscribe( IAccessibility::IOnVoiceGuidanceSettingsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("accessibility.onVoiceGuidanceSettingsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Accessibility
}

