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
#include "jsondata_localization.h"
#include "common/accessibility.h"

namespace Firebolt {
namespace Accessibility {

    // Types
    using JsonData_FontFamily = WPEFramework::Core::JSON::EnumType<FontFamily>;

    using JsonData_FontEdge = WPEFramework::Core::JSON::EnumType<FontEdge>;

    class JsonData_ClosedCaptionsStyles: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_ClosedCaptionsStyles() override = default;
  
    public:
        JsonData_ClosedCaptionsStyles()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("fontFamily"), &FontFamily);
            Add(_T("fontSize"), &FontSize);
            Add(_T("fontColor"), &FontColor);
            Add(_T("fontEdge"), &FontEdge);
            Add(_T("fontEdgeColor"), &FontEdgeColor);
            Add(_T("fontOpacity"), &FontOpacity);
            Add(_T("backgroundColor"), &BackgroundColor);
            Add(_T("backgroundOpacity"), &BackgroundOpacity);
            Add(_T("textAlign"), &TextAlign);
            Add(_T("textAlignVertical"), &TextAlignVertical);
            Add(_T("windowColor"), &WindowColor);
            Add(_T("windowOpacity"), &WindowOpacity);
        }

        JsonData_ClosedCaptionsStyles(const JsonData_ClosedCaptionsStyles& other)
        {
            Add(_T("fontFamily"), &FontFamily);
            FontFamily = other.FontFamily;
            Add(_T("fontSize"), &FontSize);
            FontSize = other.FontSize;
            Add(_T("fontColor"), &FontColor);
            FontColor = other.FontColor;
            Add(_T("fontEdge"), &FontEdge);
            FontEdge = other.FontEdge;
            Add(_T("fontEdgeColor"), &FontEdgeColor);
            FontEdgeColor = other.FontEdgeColor;
            Add(_T("fontOpacity"), &FontOpacity);
            FontOpacity = other.FontOpacity;
            Add(_T("backgroundColor"), &BackgroundColor);
            BackgroundColor = other.BackgroundColor;
            Add(_T("backgroundOpacity"), &BackgroundOpacity);
            BackgroundOpacity = other.BackgroundOpacity;
            Add(_T("textAlign"), &TextAlign);
            TextAlign = other.TextAlign;
            Add(_T("textAlignVertical"), &TextAlignVertical);
            TextAlignVertical = other.TextAlignVertical;
            Add(_T("windowColor"), &WindowColor);
            WindowColor = other.WindowColor;
            Add(_T("windowOpacity"), &WindowOpacity);
            WindowOpacity = other.WindowOpacity;
        }

        JsonData_ClosedCaptionsStyles& operator=(const JsonData_ClosedCaptionsStyles& other)
        {
            Add(_T("fontFamily"), &FontFamily);
            FontFamily = other.FontFamily;
            Add(_T("fontSize"), &FontSize);
            FontSize = other.FontSize;
            Add(_T("fontColor"), &FontColor);
            FontColor = other.FontColor;
            Add(_T("fontEdge"), &FontEdge);
            FontEdge = other.FontEdge;
            Add(_T("fontEdgeColor"), &FontEdgeColor);
            FontEdgeColor = other.FontEdgeColor;
            Add(_T("fontOpacity"), &FontOpacity);
            FontOpacity = other.FontOpacity;
            Add(_T("backgroundColor"), &BackgroundColor);
            BackgroundColor = other.BackgroundColor;
            Add(_T("backgroundOpacity"), &BackgroundOpacity);
            BackgroundOpacity = other.BackgroundOpacity;
            Add(_T("textAlign"), &TextAlign);
            TextAlign = other.TextAlign;
            Add(_T("textAlignVertical"), &TextAlignVertical);
            TextAlignVertical = other.TextAlignVertical;
            Add(_T("windowColor"), &WindowColor);
            WindowColor = other.WindowColor;
            Add(_T("windowOpacity"), &WindowOpacity);
            WindowOpacity = other.WindowOpacity;
            return (*this);
        }

    public:
        Firebolt::Accessibility::JsonData_FontFamily FontFamily;
        WPEFramework::Core::JSON::Float FontSize;
        FireboltSDK::JSON::String FontColor;
        Firebolt::Accessibility::JsonData_FontEdge FontEdge;
        FireboltSDK::JSON::String FontEdgeColor;
        WPEFramework::Core::JSON::Float FontOpacity;
        FireboltSDK::JSON::String BackgroundColor;
        WPEFramework::Core::JSON::Float BackgroundOpacity;
        FireboltSDK::JSON::String TextAlign;
        FireboltSDK::JSON::String TextAlignVertical;
        FireboltSDK::JSON::String WindowColor;
        WPEFramework::Core::JSON::Float WindowOpacity;
    };

    class JsonData_ClosedCaptionsSettings: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_ClosedCaptionsSettings() override = default;
  
    public:
        JsonData_ClosedCaptionsSettings()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("enabled"), &Enabled);
            Add(_T("styles"), &Styles);
            Add(_T("preferredLanguages"), &PreferredLanguages);
        }

        JsonData_ClosedCaptionsSettings(const JsonData_ClosedCaptionsSettings& other)
        {
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
            Add(_T("styles"), &Styles);
            Styles = other.Styles;
            Add(_T("preferredLanguages"), &PreferredLanguages);
            PreferredLanguages = other.PreferredLanguages;
        }

        JsonData_ClosedCaptionsSettings& operator=(const JsonData_ClosedCaptionsSettings& other)
        {
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
            Add(_T("styles"), &Styles);
            Styles = other.Styles;
            Add(_T("preferredLanguages"), &PreferredLanguages);
            PreferredLanguages = other.PreferredLanguages;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Enabled;
        Firebolt::Accessibility::JsonData_ClosedCaptionsStyles Styles;
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> PreferredLanguages;
    };

    class JsonData_VoiceGuidanceSettings: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_VoiceGuidanceSettings() override = default;
  
    public:
        JsonData_VoiceGuidanceSettings()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("enabled"), &Enabled);
            Add(_T("navigationHints"), &NavigationHints);
            Add(_T("rate"), &Rate);
            Add(_T("speed"), &Speed);
        }

        JsonData_VoiceGuidanceSettings(const JsonData_VoiceGuidanceSettings& other)
        {
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
            Add(_T("navigationHints"), &NavigationHints);
            NavigationHints = other.NavigationHints;
            Add(_T("rate"), &Rate);
            Rate = other.Rate;
            Add(_T("speed"), &Speed);
            Speed = other.Speed;
        }

        JsonData_VoiceGuidanceSettings& operator=(const JsonData_VoiceGuidanceSettings& other)
        {
            Add(_T("enabled"), &Enabled);
            Enabled = other.Enabled;
            Add(_T("navigationHints"), &NavigationHints);
            NavigationHints = other.NavigationHints;
            Add(_T("rate"), &Rate);
            Rate = other.Rate;
            Add(_T("speed"), &Speed);
            Speed = other.Speed;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean Enabled;
        WPEFramework::Core::JSON::Boolean NavigationHints;
        WPEFramework::Core::JSON::Float Rate;
        WPEFramework::Core::JSON::Float Speed;
    };

}
}
