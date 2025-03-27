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

#include "closedcaptions_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace ClosedCaptions {

    // Methods
    /* backgroundColor - The preferred background color for displaying closed-captions, . */
    std::string ClosedCaptionsImpl::backgroundColor( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.backgroundColor");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string color;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            color = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return color;
    }
    /* setBackgroundColor - The preferred background color for displaying closed-captions, . */
    void ClosedCaptionsImpl::setBackgroundColor( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setBackgroundColor");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* backgroundOpacity - The preferred opacity for displaying closed-captions backgrounds. */
    float ClosedCaptionsImpl::backgroundOpacity( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.backgroundOpacity");
        
        
        WPEFramework::Core::JSON::Float jsonResult;
        float opacity = 0;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            opacity = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return opacity;
    }
    /* setBackgroundOpacity - The preferred opacity for displaying closed-captions backgrounds. */
    void ClosedCaptionsImpl::setBackgroundOpacity( const float& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setBackgroundOpacity");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* enabled - Whether or not closed-captions are enabled. */
    bool ClosedCaptionsImpl::enabled( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.enabled");
        
        
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
    /* setEnabled - Whether or not closed-captions are enabled. */
    void ClosedCaptionsImpl::setEnabled( const bool value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setEnabled");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* fontColor - The preferred font color for displaying closed-captions. */
    std::string ClosedCaptionsImpl::fontColor( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.fontColor");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string color;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            color = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return color;
    }
    /* setFontColor - The preferred font color for displaying closed-captions. */
    void ClosedCaptionsImpl::setFontColor( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setFontColor");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* fontEdge - The preferred font edge style for displaying closed-captions. */
    Accessibility::FontEdge ClosedCaptionsImpl::fontEdge( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.fontEdge");
        
        
        Firebolt::Accessibility::JsonData_FontEdge jsonResult;
        Accessibility::FontEdge edge;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            edge = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return edge;
    }
    /* setFontEdge - The preferred font edge style for displaying closed-captions. */
    void ClosedCaptionsImpl::setFontEdge( const Accessibility::FontEdge& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setFontEdge");

        JsonObject jsonParameters;
        Firebolt::Accessibility::JsonData_FontEdge jsonValue = value;
        WPEFramework::Core::JSON::Variant valueVariant(jsonValue.Data());
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* fontEdgeColor - The preferred font edge color for displaying closed-captions. */
    std::string ClosedCaptionsImpl::fontEdgeColor( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.fontEdgeColor");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string color;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            color = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return color;
    }
    /* setFontEdgeColor - The preferred font edge color for displaying closed-captions. */
    void ClosedCaptionsImpl::setFontEdgeColor( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setFontEdgeColor");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* fontFamily - The preferred font family for displaying closed-captions. */
    Accessibility::FontFamily ClosedCaptionsImpl::fontFamily( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.fontFamily");
        
        
        Firebolt::Accessibility::JsonData_FontFamily jsonResult;
        Accessibility::FontFamily family;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            family = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return family;
    }
    /* setFontFamily - The preferred font family for displaying closed-captions. */
    void ClosedCaptionsImpl::setFontFamily( const Accessibility::FontFamily& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setFontFamily");

        JsonObject jsonParameters;
        Firebolt::Accessibility::JsonData_FontFamily jsonValue = value;
        WPEFramework::Core::JSON::Variant valueVariant(jsonValue.Data());
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* fontOpacity - The preferred opacity for displaying closed-captions characters. */
    float ClosedCaptionsImpl::fontOpacity( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.fontOpacity");
        
        
        WPEFramework::Core::JSON::Float jsonResult;
        float opacity = 0;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            opacity = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return opacity;
    }
    /* setFontOpacity - The preferred opacity for displaying closed-captions characters. */
    void ClosedCaptionsImpl::setFontOpacity( const float& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setFontOpacity");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* fontSize - The preferred font size for displaying closed-captions. */
    float ClosedCaptionsImpl::fontSize( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.fontSize");
        
        
        WPEFramework::Core::JSON::Float jsonResult;
        float size = 0;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            size = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return size;
    }
    /* setFontSize - The preferred font size for displaying closed-captions. */
    void ClosedCaptionsImpl::setFontSize( const float& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setFontSize");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* preferredLanguages - A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device. */
    std::vector<std::string> ClosedCaptionsImpl::preferredLanguages( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.preferredLanguages");
        
        
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> jsonResult;
        std::vector<std::string> languages;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            auto index(jsonResult.Elements());
            while (index.Next() == true) {
                languages.push_back(index.Current().Value());
            }
        }
        if (err != nullptr) {
            *err = status;
        }

        return languages;
    }
    /* setPreferredLanguages - A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device. */
    void ClosedCaptionsImpl::setPreferredLanguages( const std::vector<std::string>& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setPreferredLanguages");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::ArrayType<WPEFramework::Core::JSON::Variant> valueArray;
        for (auto& element : value) {
             valueArray.Add() = element;
        }
        WPEFramework::Core::JSON::Variant valueVariant;
        valueVariant.Array(valueArray);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* textAlign - The preferred horizontal alignment for displaying closed-captions characters. */
    std::string ClosedCaptionsImpl::textAlign( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.textAlign");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string alignment;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            alignment = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return alignment;
    }
    /* setTextAlign - The preferred horizontal alignment for displaying closed-captions characters. */
    void ClosedCaptionsImpl::setTextAlign( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setTextAlign");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* textAlignVertical - The preferred horizontal alignment for displaying closed-captions characters. */
    std::string ClosedCaptionsImpl::textAlignVertical( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.textAlignVertical");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string alignment;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            alignment = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return alignment;
    }
    /* setTextAlignVertical - The preferred horizontal alignment for displaying closed-captions characters. */
    void ClosedCaptionsImpl::setTextAlignVertical( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setTextAlignVertical");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* windowColor - The preferred window color for displaying closed-captions, . */
    std::string ClosedCaptionsImpl::windowColor( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.windowColor");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string color;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            color = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return color;
    }
    /* setWindowColor - The preferred window color for displaying closed-captions, . */
    void ClosedCaptionsImpl::setWindowColor( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setWindowColor");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* windowOpacity - The preferred window opacity for displaying closed-captions backgrounds. */
    float ClosedCaptionsImpl::windowOpacity( Firebolt::Error *err ) const
    {
        const string method = _T("closedcaptions.windowOpacity");
        
        
        WPEFramework::Core::JSON::Float jsonResult;
        float opacity = 0;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            opacity = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return opacity;
    }
    /* setWindowOpacity - The preferred window opacity for displaying closed-captions backgrounds. */
    void ClosedCaptionsImpl::setWindowOpacity( const float& value, Firebolt::Error *err )
    {
        const string method = _T("closedcaptions.setWindowOpacity");

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
    /* onBackgroundColorChanged - The preferred background color for displaying closed-captions, . */
    static void onBackgroundColorChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnBackgroundColorChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnBackgroundColorChangedNotification*>(notification));
            notifier.onBackgroundColorChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnBackgroundColorChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onBackgroundColorChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onBackgroundColorChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnBackgroundColorChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onBackgroundColorChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onBackgroundOpacityChanged - The preferred opacity for displaying closed-captions backgrounds. */
    static void onBackgroundOpacityChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            float result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnBackgroundOpacityChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnBackgroundOpacityChangedNotification*>(notification));
            notifier.onBackgroundOpacityChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnBackgroundOpacityChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onBackgroundOpacityChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Float>(eventName, jsonParameters, onBackgroundOpacityChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnBackgroundOpacityChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onBackgroundOpacityChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onEnabledChanged - Whether or not closed-captions are enabled. */
    static void onEnabledChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnEnabledChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnEnabledChangedNotification*>(notification));
            notifier.onEnabledChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onEnabledChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onEnabledChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onEnabledChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onFontColorChanged - The preferred font color for displaying closed-captions. */
    static void onFontColorChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnFontColorChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnFontColorChangedNotification*>(notification));
            notifier.onFontColorChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnFontColorChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onFontColorChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onFontColorChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnFontColorChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onFontColorChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onFontEdgeChanged - The preferred font edge style for displaying closed-captions. */
    static void onFontEdgeChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_FontEdge>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_FontEdge>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            Accessibility::FontEdge result;

            result = proxyResponse->Value();
            proxyResponse.Release();

            IClosedCaptions::IOnFontEdgeChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnFontEdgeChangedNotification*>(notification));
            notifier.onFontEdgeChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnFontEdgeChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onFontEdgeChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Accessibility::JsonData_FontEdge>(eventName, jsonParameters, onFontEdgeChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnFontEdgeChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onFontEdgeChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onFontEdgeColorChanged - The preferred font edge color for displaying closed-captions. */
    static void onFontEdgeColorChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnFontEdgeColorChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnFontEdgeColorChangedNotification*>(notification));
            notifier.onFontEdgeColorChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnFontEdgeColorChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onFontEdgeColorChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onFontEdgeColorChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnFontEdgeColorChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onFontEdgeColorChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onFontFamilyChanged - The preferred font family for displaying closed-captions. */
    static void onFontFamilyChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_FontFamily>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Accessibility::JsonData_FontFamily>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            Accessibility::FontFamily result;

            result = proxyResponse->Value();
            proxyResponse.Release();

            IClosedCaptions::IOnFontFamilyChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnFontFamilyChangedNotification*>(notification));
            notifier.onFontFamilyChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnFontFamilyChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onFontFamilyChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Accessibility::JsonData_FontFamily>(eventName, jsonParameters, onFontFamilyChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnFontFamilyChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onFontFamilyChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onFontOpacityChanged - The preferred opacity for displaying closed-captions characters. */
    static void onFontOpacityChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            float result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnFontOpacityChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnFontOpacityChangedNotification*>(notification));
            notifier.onFontOpacityChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnFontOpacityChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onFontOpacityChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Float>(eventName, jsonParameters, onFontOpacityChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnFontOpacityChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onFontOpacityChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onFontSizeChanged - The preferred font size for displaying closed-captions. */
    static void onFontSizeChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            float result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnFontSizeChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnFontSizeChangedNotification*>(notification));
            notifier.onFontSizeChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnFontSizeChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onFontSizeChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Float>(eventName, jsonParameters, onFontSizeChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnFontSizeChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onFontSizeChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onPreferredLanguagesChanged - A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device. */
    static void onPreferredLanguagesChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String>>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String>>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::vector<std::string> result;


            auto index(proxyResponse->Elements());
            while (index.Next() == true) {
                result.push_back(index.Current().Value());
            }
            proxyResponse.Release();

            IClosedCaptions::IOnPreferredLanguagesChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnPreferredLanguagesChangedNotification*>(notification));
            notifier.onPreferredLanguagesChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnPreferredLanguagesChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onPreferredLanguagesChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String>>(eventName, jsonParameters, onPreferredLanguagesChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnPreferredLanguagesChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onPreferredLanguagesChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onTextAlignChanged - The preferred horizontal alignment for displaying closed-captions characters. */
    static void onTextAlignChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnTextAlignChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnTextAlignChangedNotification*>(notification));
            notifier.onTextAlignChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnTextAlignChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onTextAlignChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onTextAlignChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnTextAlignChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onTextAlignChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onTextAlignVerticalChanged - The preferred horizontal alignment for displaying closed-captions characters. */
    static void onTextAlignVerticalChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnTextAlignVerticalChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnTextAlignVerticalChangedNotification*>(notification));
            notifier.onTextAlignVerticalChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnTextAlignVerticalChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onTextAlignVerticalChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onTextAlignVerticalChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnTextAlignVerticalChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onTextAlignVerticalChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onWindowColorChanged - The preferred window color for displaying closed-captions, . */
    static void onWindowColorChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnWindowColorChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnWindowColorChangedNotification*>(notification));
            notifier.onWindowColorChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnWindowColorChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onWindowColorChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onWindowColorChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnWindowColorChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onWindowColorChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onWindowOpacityChanged - The preferred window opacity for displaying closed-captions backgrounds. */
    static void onWindowOpacityChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Float>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            float result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IClosedCaptions::IOnWindowOpacityChangedNotification& notifier = *(reinterpret_cast<IClosedCaptions::IOnWindowOpacityChangedNotification*>(notification));
            notifier.onWindowOpacityChanged(result);
        }
    }
    void ClosedCaptionsImpl::subscribe( IClosedCaptions::IOnWindowOpacityChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("closedcaptions.onWindowOpacityChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Float>(eventName, jsonParameters, onWindowOpacityChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void ClosedCaptionsImpl::unsubscribe( IClosedCaptions::IOnWindowOpacityChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("closedcaptions.onWindowOpacityChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace ClosedCaptions
}

