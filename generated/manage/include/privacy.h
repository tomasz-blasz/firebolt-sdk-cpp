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


namespace Firebolt {
namespace Privacy {


// Types
struct PrivacySettings {
    bool allowACRCollection;
    bool allowResumePoints;
    bool allowAppContentAdTargeting;
    bool allowCameraAnalytics;
    bool allowPersonalization;
    bool allowPrimaryBrowseAdTargeting;
    bool allowPrimaryContentAdTargeting;
    bool allowProductAnalytics;
    bool allowRemoteDiagnostics;
    bool allowUnentitledPersonalization;
    bool allowUnentitledResumePoints;
    bool allowWatchHistory;
};


struct IPrivacy {

    virtual ~IPrivacy() = default;

    // Methods & Events
    /*
     * Whether the user allows their automatic content recognition data to be collected
     * 
     */
    virtual bool allowACRCollection( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows ads to be targeted to the user while watching content in apps
     * 
     */
    virtual bool allowAppContentAdTargeting( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows data from their camera to be used for Product Analytics
     * 
     */
    virtual bool allowCameraAnalytics( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows their usage data to be used for personalization and recommendations
     * 
     */
    virtual bool allowPersonalization( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows ads to be targeted to the user while browsing in the primary experience
     * 
     */
    virtual bool allowPrimaryBrowseAdTargeting( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows ads to be targeted to the user while watching content in the primary experience
     * 
     */
    virtual bool allowPrimaryContentAdTargeting( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows their usage data can be used for analytics about the product
     * 
     */
    virtual bool allowProductAnalytics( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device
     * 
     */
    virtual bool allowRemoteDiagnostics( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows resume points for content to show in the main experience
     * 
     */
    virtual bool allowResumePoints( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows their usage data to be used for personalization and recommendations for unentitled content
     * 
     */
    virtual bool allowUnentitledPersonalization( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows resume points for content from unentitled providers to show in the main experience
     * 
     */
    virtual bool allowUnentitledResumePoints( Firebolt::Error *err = nullptr ) const = 0;

    /*
     * Whether the user allows their watch history from all sources to show in the main experience
     * 
     */
    virtual bool allowWatchHistory( Firebolt::Error *err = nullptr ) const = 0;

    /* onAllowACRCollectionChanged - Whether the user allows their automatic content recognition data to be collected */
    struct IOnAllowACRCollectionChangedNotification {
        virtual void onAllowACRCollectionChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowACRCollectionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowACRCollectionChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowAppContentAdTargetingChanged - Whether the user allows ads to be targeted to the user while watching content in apps */
    struct IOnAllowAppContentAdTargetingChangedNotification {
        virtual void onAllowAppContentAdTargetingChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowAppContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowAppContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowCameraAnalyticsChanged - Whether the user allows data from their camera to be used for Product Analytics */
    struct IOnAllowCameraAnalyticsChangedNotification {
        virtual void onAllowCameraAnalyticsChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowCameraAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowCameraAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowPersonalizationChanged - Whether the user allows their usage data to be used for personalization and recommendations */
    struct IOnAllowPersonalizationChangedNotification {
        virtual void onAllowPersonalizationChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowPrimaryBrowseAdTargetingChanged - Whether the user allows ads to be targeted to the user while browsing in the primary experience */
    struct IOnAllowPrimaryBrowseAdTargetingChangedNotification {
        virtual void onAllowPrimaryBrowseAdTargetingChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowPrimaryBrowseAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowPrimaryBrowseAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowPrimaryContentAdTargetingChanged - Whether the user allows ads to be targeted to the user while watching content in the primary experience */
    struct IOnAllowPrimaryContentAdTargetingChangedNotification {
        virtual void onAllowPrimaryContentAdTargetingChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowPrimaryContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowPrimaryContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowProductAnalyticsChanged - Whether the user allows their usage data can be used for analytics about the product */
    struct IOnAllowProductAnalyticsChangedNotification {
        virtual void onAllowProductAnalyticsChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowProductAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowProductAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowRemoteDiagnosticsChanged - Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device */
    struct IOnAllowRemoteDiagnosticsChangedNotification {
        virtual void onAllowRemoteDiagnosticsChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowRemoteDiagnosticsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowRemoteDiagnosticsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowResumePointsChanged - Whether the user allows resume points for content to show in the main experience */
    struct IOnAllowResumePointsChangedNotification {
        virtual void onAllowResumePointsChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowUnentitledPersonalizationChanged - Whether the user allows their usage data to be used for personalization and recommendations for unentitled content */
    struct IOnAllowUnentitledPersonalizationChangedNotification {
        virtual void onAllowUnentitledPersonalizationChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowUnentitledPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowUnentitledPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowUnentitledResumePointsChanged - Whether the user allows resume points for content from unentitled providers to show in the main experience */
    struct IOnAllowUnentitledResumePointsChangedNotification {
        virtual void onAllowUnentitledResumePointsChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowUnentitledResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowUnentitledResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /* onAllowWatchHistoryChanged - Whether the user allows their watch history from all sources to show in the main experience */
    struct IOnAllowWatchHistoryChangedNotification {
        virtual void onAllowWatchHistoryChanged( const bool ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnAllowWatchHistoryChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnAllowWatchHistoryChangedNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowACRCollection
     Whether the user allows their automatic content recognition data to be collected
     */
    virtual void setAllowACRCollection( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowAppContentAdTargeting
     Whether the user allows ads to be targeted to the user while watching content in apps
     */
    virtual void setAllowAppContentAdTargeting( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowCameraAnalytics
     Whether the user allows data from their camera to be used for Product Analytics
     */
    virtual void setAllowCameraAnalytics( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowPersonalization
     Whether the user allows their usage data to be used for personalization and recommendations
     */
    virtual void setAllowPersonalization( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowPrimaryBrowseAdTargeting
     Whether the user allows ads to be targeted to the user while browsing in the primary experience
     */
    virtual void setAllowPrimaryBrowseAdTargeting( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowPrimaryContentAdTargeting
     Whether the user allows ads to be targeted to the user while watching content in the primary experience
     */
    virtual void setAllowPrimaryContentAdTargeting( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowProductAnalytics
     Whether the user allows their usage data can be used for analytics about the product
     */
    virtual void setAllowProductAnalytics( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowRemoteDiagnostics
     Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device
     */
    virtual void setAllowRemoteDiagnostics( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowResumePoints
     Whether the user allows resume points for content to show in the main experience
     */
    virtual void setAllowResumePoints( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowUnentitledPersonalization
     Whether the user allows their usage data to be used for personalization and recommendations for unentitled content
     */
    virtual void setAllowUnentitledPersonalization( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowUnentitledResumePoints
     Whether the user allows resume points for content from unentitled providers to show in the main experience
     */
    virtual void setAllowUnentitledResumePoints( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     setAllowWatchHistory
     Whether the user allows their watch history from all sources to show in the main experience
     */
    virtual void setAllowWatchHistory( const bool value, Firebolt::Error *err = nullptr ) = 0;

    /*
     settings
     Gets the allowed value for all privacy settings
     
     */
    virtual PrivacySettings settings( Firebolt::Error *err = nullptr ) const = 0;
};

} //namespace Privacy
}
