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
#include "jsondata_accessibility.h"
#include "jsondata_localization.h"

#include "closedcaptions.h"


namespace Firebolt {
namespace ClosedCaptions {


    class ClosedCaptionsImpl : public IClosedCaptions, public IModule {

    public:
        ClosedCaptionsImpl() = default;
        ClosedCaptionsImpl(const ClosedCaptionsImpl&) = delete;
        ClosedCaptionsImpl& operator=(const ClosedCaptionsImpl&) = delete;

        ~ClosedCaptionsImpl() override = default;

        // Methods & Events
        /*
         * The preferred background color for displaying closed-captions, .
         * 
         */
        std::string backgroundColor( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred opacity for displaying closed-captions backgrounds.
         * 
         */
        float backgroundOpacity( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether or not closed-captions are enabled.
         * 
         */
        bool enabled( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred font color for displaying closed-captions.
         * 
         */
        std::string fontColor( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred font edge style for displaying closed-captions.
         * 
         */
        Accessibility::FontEdge fontEdge( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred font edge color for displaying closed-captions.
         * 
         */
        std::string fontEdgeColor( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred font family for displaying closed-captions.
         * 
         */
        Accessibility::FontFamily fontFamily( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred opacity for displaying closed-captions characters.
         * 
         */
        float fontOpacity( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred font size for displaying closed-captions.
         * 
         */
        float fontSize( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnBackgroundColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnBackgroundColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnBackgroundOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnBackgroundOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnFontColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnFontColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnFontEdgeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnFontEdgeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnFontEdgeColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnFontEdgeColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnFontFamilyChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnFontFamilyChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnFontOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnFontOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnFontSizeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnFontSizeChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnPreferredLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnPreferredLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnTextAlignChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnTextAlignChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnTextAlignVerticalChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnTextAlignVerticalChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnWindowColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnWindowColorChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IClosedCaptions::IOnWindowOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IClosedCaptions::IOnWindowOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         * A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device.
         * 
         */
        std::vector<std::string> preferredLanguages( Firebolt::Error *err = nullptr ) const override;
        /*
         * setBackgroundColor
         * The preferred background color for displaying closed-captions, .
         */
        void setBackgroundColor( const std::string& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setBackgroundOpacity
         * The preferred opacity for displaying closed-captions backgrounds.
         */
        void setBackgroundOpacity( const float& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setEnabled
         * Whether or not closed-captions are enabled.
         */
        void setEnabled( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setFontColor
         * The preferred font color for displaying closed-captions.
         */
        void setFontColor( const std::string& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setFontEdge
         * The preferred font edge style for displaying closed-captions.
         */
        void setFontEdge( const Accessibility::FontEdge& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setFontEdgeColor
         * The preferred font edge color for displaying closed-captions.
         */
        void setFontEdgeColor( const std::string& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setFontFamily
         * The preferred font family for displaying closed-captions.
         */
        void setFontFamily( const Accessibility::FontFamily& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setFontOpacity
         * The preferred opacity for displaying closed-captions characters.
         */
        void setFontOpacity( const float& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setFontSize
         * The preferred font size for displaying closed-captions.
         */
        void setFontSize( const float& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setPreferredLanguages
         * A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device.
         */
        void setPreferredLanguages( const std::vector<std::string>& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setTextAlign
         * The preferred horizontal alignment for displaying closed-captions characters.
         */
        void setTextAlign( const std::string& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setTextAlignVertical
         * The preferred horizontal alignment for displaying closed-captions characters.
         */
        void setTextAlignVertical( const std::string& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setWindowColor
         * The preferred window color for displaying closed-captions, .
         */
        void setWindowColor( const std::string& value, Firebolt::Error *err = nullptr ) override;

        /*
         * setWindowOpacity
         * The preferred window opacity for displaying closed-captions backgrounds.
         */
        void setWindowOpacity( const float& value, Firebolt::Error *err = nullptr ) override;

        /*
         * The preferred horizontal alignment for displaying closed-captions characters.
         * 
         */
        std::string textAlign( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred horizontal alignment for displaying closed-captions characters.
         * 
         */
        std::string textAlignVertical( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred window color for displaying closed-captions, .
         * 
         */
        std::string windowColor( Firebolt::Error *err = nullptr ) const override;
        /*
         * The preferred window opacity for displaying closed-captions backgrounds.
         * 
         */
        float windowOpacity( Firebolt::Error *err = nullptr ) const override;
    };

}//namespace ClosedCaptions
}
