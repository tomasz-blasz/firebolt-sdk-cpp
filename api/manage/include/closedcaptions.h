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

#include "error.h"
#include "common/accessibility.h"
#include "common/localization.h"


namespace Firebolt {
namespace ClosedCaptions {



struct IClosedCaptions {

    virtual ~IClosedCaptions() = default;

    // Methods & Events
    /*
     * The preferred background color for displaying closed-captions, .
     * 
     */
    virtual std::string backgroundColor( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred opacity for displaying closed-captions backgrounds.
     * 
     */
    virtual float backgroundOpacity( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether or not closed-captions are enabled.
     * 
     */
    virtual bool enabled( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred font color for displaying closed-captions.
     * 
     */
    virtual std::string fontColor( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred font edge style for displaying closed-captions.
     * 
     */
    virtual Accessibility::FontEdge fontEdge( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred font edge color for displaying closed-captions.
     * 
     */
    virtual std::string fontEdgeColor( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred font family for displaying closed-captions.
     * 
     */
    virtual Accessibility::FontFamily fontFamily( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred opacity for displaying closed-captions characters.
     * 
     */
    virtual float fontOpacity( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred font size for displaying closed-captions.
     * 
     */
    virtual float fontSize( Firebolt::Error *err = nullptr ) const = 0;

    /* onBackgroundColorChanged - The preferred background color for displaying closed-captions, . */
    struct IOnBackgroundColorChangedNotification {
        virtual void onBackgroundColorChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnBackgroundColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnBackgroundColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onBackgroundOpacityChanged - The preferred opacity for displaying closed-captions backgrounds. */
    struct IOnBackgroundOpacityChangedNotification {
        virtual void onBackgroundOpacityChanged( const float& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnBackgroundOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnBackgroundOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onEnabledChanged - Whether or not closed-captions are enabled. */
    struct IOnEnabledChangedNotification {
        virtual void onEnabledChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnEnabledChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onFontColorChanged - The preferred font color for displaying closed-captions. */
    struct IOnFontColorChangedNotification {
        virtual void onFontColorChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnFontColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnFontColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onFontEdgeChanged - The preferred font edge style for displaying closed-captions. */
    struct IOnFontEdgeChangedNotification {
        virtual void onFontEdgeChanged( const Accessibility::FontEdge& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnFontEdgeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnFontEdgeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onFontEdgeColorChanged - The preferred font edge color for displaying closed-captions. */
    struct IOnFontEdgeColorChangedNotification {
        virtual void onFontEdgeColorChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnFontEdgeColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnFontEdgeColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onFontFamilyChanged - The preferred font family for displaying closed-captions. */
    struct IOnFontFamilyChangedNotification {
        virtual void onFontFamilyChanged( const Accessibility::FontFamily& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnFontFamilyChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnFontFamilyChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onFontOpacityChanged - The preferred opacity for displaying closed-captions characters. */
    struct IOnFontOpacityChangedNotification {
        virtual void onFontOpacityChanged( const float& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnFontOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnFontOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onFontSizeChanged - The preferred font size for displaying closed-captions. */
    struct IOnFontSizeChangedNotification {
        virtual void onFontSizeChanged( const float& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnFontSizeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnFontSizeChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onPreferredLanguagesChanged - A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device. */
    struct IOnPreferredLanguagesChangedNotification {
        virtual void onPreferredLanguagesChanged( const std::vector<std::string>& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnPreferredLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnPreferredLanguagesChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onTextAlignChanged - The preferred horizontal alignment for displaying closed-captions characters. */
    struct IOnTextAlignChangedNotification {
        virtual void onTextAlignChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnTextAlignChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnTextAlignChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onTextAlignVerticalChanged - The preferred horizontal alignment for displaying closed-captions characters. */
    struct IOnTextAlignVerticalChangedNotification {
        virtual void onTextAlignVerticalChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnTextAlignVerticalChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnTextAlignVerticalChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onWindowColorChanged - The preferred window color for displaying closed-captions, . */
    struct IOnWindowColorChangedNotification {
        virtual void onWindowColorChanged( const std::string& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnWindowColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnWindowColorChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onWindowOpacityChanged - The preferred window opacity for displaying closed-captions backgrounds. */
    struct IOnWindowOpacityChangedNotification {
        virtual void onWindowOpacityChanged( const float& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnWindowOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnWindowOpacityChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     * A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device.
     * 
     */
    virtual std::vector<std::string> preferredLanguages( Firebolt::Error *err = nullptr ) const = 0;

    /*
     setBackgroundColor
     The preferred background color for displaying closed-captions, .
     */
    virtual void setBackgroundColor( const std::string& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setBackgroundOpacity
     The preferred opacity for displaying closed-captions backgrounds.
     */
    virtual void setBackgroundOpacity( const float& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setEnabled
     Whether or not closed-captions are enabled.
     */
    virtual void setEnabled( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setFontColor
     The preferred font color for displaying closed-captions.
     */
    virtual void setFontColor( const std::string& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setFontEdge
     The preferred font edge style for displaying closed-captions.
     */
    virtual void setFontEdge( const Accessibility::FontEdge& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setFontEdgeColor
     The preferred font edge color for displaying closed-captions.
     */
    virtual void setFontEdgeColor( const std::string& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setFontFamily
     The preferred font family for displaying closed-captions.
     */
    virtual void setFontFamily( const Accessibility::FontFamily& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setFontOpacity
     The preferred opacity for displaying closed-captions characters.
     */
    virtual void setFontOpacity( const float& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setFontSize
     The preferred font size for displaying closed-captions.
     */
    virtual void setFontSize( const float& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setPreferredLanguages
     A prioritized list of ISO 639-2/B codes for the preferred closed captions languages on this device.
     */
    virtual void setPreferredLanguages( const std::vector<std::string>& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setTextAlign
     The preferred horizontal alignment for displaying closed-captions characters.
     */
    virtual void setTextAlign( const std::string& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setTextAlignVertical
     The preferred horizontal alignment for displaying closed-captions characters.
     */
    virtual void setTextAlignVertical( const std::string& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setWindowColor
     The preferred window color for displaying closed-captions, .
     */
    virtual void setWindowColor( const std::string& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setWindowOpacity
     The preferred window opacity for displaying closed-captions backgrounds.
     */
    virtual void setWindowOpacity( const float& value, Firebolt::Error *err = nullptr ) = 0;

    /*
     * The preferred horizontal alignment for displaying closed-captions characters.
     * 
     */
    virtual std::string textAlign( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred horizontal alignment for displaying closed-captions characters.
     * 
     */
    virtual std::string textAlignVertical( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred window color for displaying closed-captions, .
     * 
     */
    virtual std::string windowColor( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * The preferred window opacity for displaying closed-captions backgrounds.
     * 
     */
    virtual float windowOpacity( Firebolt::Error *err = nullptr ) const = 0;

};

} //namespace ClosedCaptions
}
