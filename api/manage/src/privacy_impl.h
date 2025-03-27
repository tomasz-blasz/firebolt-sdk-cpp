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

#include "privacy.h"


namespace Firebolt {
namespace Privacy {


    // Types
    class JsonData_PrivacySettings: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PrivacySettings() override = default;
  
    public:
        JsonData_PrivacySettings()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("allowACRCollection"), &AllowACRCollection);
            Add(_T("allowResumePoints"), &AllowResumePoints);
            Add(_T("allowAppContentAdTargeting"), &AllowAppContentAdTargeting);
            Add(_T("allowCameraAnalytics"), &AllowCameraAnalytics);
            Add(_T("allowPersonalization"), &AllowPersonalization);
            Add(_T("allowPrimaryBrowseAdTargeting"), &AllowPrimaryBrowseAdTargeting);
            Add(_T("allowPrimaryContentAdTargeting"), &AllowPrimaryContentAdTargeting);
            Add(_T("allowProductAnalytics"), &AllowProductAnalytics);
            Add(_T("allowRemoteDiagnostics"), &AllowRemoteDiagnostics);
            Add(_T("allowUnentitledPersonalization"), &AllowUnentitledPersonalization);
            Add(_T("allowUnentitledResumePoints"), &AllowUnentitledResumePoints);
            Add(_T("allowWatchHistory"), &AllowWatchHistory);
        }

        JsonData_PrivacySettings(const JsonData_PrivacySettings& other)
        {
            Add(_T("allowACRCollection"), &AllowACRCollection);
            AllowACRCollection = other.AllowACRCollection;
            Add(_T("allowResumePoints"), &AllowResumePoints);
            AllowResumePoints = other.AllowResumePoints;
            Add(_T("allowAppContentAdTargeting"), &AllowAppContentAdTargeting);
            AllowAppContentAdTargeting = other.AllowAppContentAdTargeting;
            Add(_T("allowCameraAnalytics"), &AllowCameraAnalytics);
            AllowCameraAnalytics = other.AllowCameraAnalytics;
            Add(_T("allowPersonalization"), &AllowPersonalization);
            AllowPersonalization = other.AllowPersonalization;
            Add(_T("allowPrimaryBrowseAdTargeting"), &AllowPrimaryBrowseAdTargeting);
            AllowPrimaryBrowseAdTargeting = other.AllowPrimaryBrowseAdTargeting;
            Add(_T("allowPrimaryContentAdTargeting"), &AllowPrimaryContentAdTargeting);
            AllowPrimaryContentAdTargeting = other.AllowPrimaryContentAdTargeting;
            Add(_T("allowProductAnalytics"), &AllowProductAnalytics);
            AllowProductAnalytics = other.AllowProductAnalytics;
            Add(_T("allowRemoteDiagnostics"), &AllowRemoteDiagnostics);
            AllowRemoteDiagnostics = other.AllowRemoteDiagnostics;
            Add(_T("allowUnentitledPersonalization"), &AllowUnentitledPersonalization);
            AllowUnentitledPersonalization = other.AllowUnentitledPersonalization;
            Add(_T("allowUnentitledResumePoints"), &AllowUnentitledResumePoints);
            AllowUnentitledResumePoints = other.AllowUnentitledResumePoints;
            Add(_T("allowWatchHistory"), &AllowWatchHistory);
            AllowWatchHistory = other.AllowWatchHistory;
        }

        JsonData_PrivacySettings& operator=(const JsonData_PrivacySettings& other)
        {
            Add(_T("allowACRCollection"), &AllowACRCollection);
            AllowACRCollection = other.AllowACRCollection;
            Add(_T("allowResumePoints"), &AllowResumePoints);
            AllowResumePoints = other.AllowResumePoints;
            Add(_T("allowAppContentAdTargeting"), &AllowAppContentAdTargeting);
            AllowAppContentAdTargeting = other.AllowAppContentAdTargeting;
            Add(_T("allowCameraAnalytics"), &AllowCameraAnalytics);
            AllowCameraAnalytics = other.AllowCameraAnalytics;
            Add(_T("allowPersonalization"), &AllowPersonalization);
            AllowPersonalization = other.AllowPersonalization;
            Add(_T("allowPrimaryBrowseAdTargeting"), &AllowPrimaryBrowseAdTargeting);
            AllowPrimaryBrowseAdTargeting = other.AllowPrimaryBrowseAdTargeting;
            Add(_T("allowPrimaryContentAdTargeting"), &AllowPrimaryContentAdTargeting);
            AllowPrimaryContentAdTargeting = other.AllowPrimaryContentAdTargeting;
            Add(_T("allowProductAnalytics"), &AllowProductAnalytics);
            AllowProductAnalytics = other.AllowProductAnalytics;
            Add(_T("allowRemoteDiagnostics"), &AllowRemoteDiagnostics);
            AllowRemoteDiagnostics = other.AllowRemoteDiagnostics;
            Add(_T("allowUnentitledPersonalization"), &AllowUnentitledPersonalization);
            AllowUnentitledPersonalization = other.AllowUnentitledPersonalization;
            Add(_T("allowUnentitledResumePoints"), &AllowUnentitledResumePoints);
            AllowUnentitledResumePoints = other.AllowUnentitledResumePoints;
            Add(_T("allowWatchHistory"), &AllowWatchHistory);
            AllowWatchHistory = other.AllowWatchHistory;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Boolean AllowACRCollection;
        WPEFramework::Core::JSON::Boolean AllowResumePoints;
        WPEFramework::Core::JSON::Boolean AllowAppContentAdTargeting;
        WPEFramework::Core::JSON::Boolean AllowCameraAnalytics;
        WPEFramework::Core::JSON::Boolean AllowPersonalization;
        WPEFramework::Core::JSON::Boolean AllowPrimaryBrowseAdTargeting;
        WPEFramework::Core::JSON::Boolean AllowPrimaryContentAdTargeting;
        WPEFramework::Core::JSON::Boolean AllowProductAnalytics;
        WPEFramework::Core::JSON::Boolean AllowRemoteDiagnostics;
        WPEFramework::Core::JSON::Boolean AllowUnentitledPersonalization;
        WPEFramework::Core::JSON::Boolean AllowUnentitledResumePoints;
        WPEFramework::Core::JSON::Boolean AllowWatchHistory;
    };

    class PrivacyImpl : public IPrivacy, public IModule {

    public:
        PrivacyImpl() = default;
        PrivacyImpl(const PrivacyImpl&) = delete;
        PrivacyImpl& operator=(const PrivacyImpl&) = delete;

        ~PrivacyImpl() override = default;

        // Methods & Events
        /*
         * Whether the user allows their automatic content recognition data to be collected
         * 
         */
        bool allowACRCollection( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows ads to be targeted to the user while watching content in apps
         * 
         */
        bool allowAppContentAdTargeting( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows data from their camera to be used for Product Analytics
         * 
         */
        bool allowCameraAnalytics( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows their usage data to be used for personalization and recommendations
         * 
         */
        bool allowPersonalization( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows ads to be targeted to the user while browsing in the primary experience
         * 
         */
        bool allowPrimaryBrowseAdTargeting( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows ads to be targeted to the user while watching content in the primary experience
         * 
         */
        bool allowPrimaryContentAdTargeting( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows their usage data can be used for analytics about the product
         * 
         */
        bool allowProductAnalytics( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device
         * 
         */
        bool allowRemoteDiagnostics( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows resume points for content to show in the main experience
         * 
         */
        bool allowResumePoints( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows their usage data to be used for personalization and recommendations for unentitled content
         * 
         */
        bool allowUnentitledPersonalization( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows resume points for content from unentitled providers to show in the main experience
         * 
         */
        bool allowUnentitledResumePoints( Firebolt::Error *err = nullptr ) const override;
        /*
         * Whether the user allows their watch history from all sources to show in the main experience
         * 
         */
        bool allowWatchHistory( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowACRCollectionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowACRCollectionChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowAppContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowAppContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowCameraAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowCameraAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowPrimaryBrowseAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowPrimaryBrowseAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowPrimaryContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowPrimaryContentAdTargetingChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowProductAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowProductAnalyticsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowRemoteDiagnosticsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowRemoteDiagnosticsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowUnentitledPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowUnentitledPersonalizationChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowUnentitledResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowUnentitledResumePointsChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( IPrivacy::IOnAllowWatchHistoryChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( IPrivacy::IOnAllowWatchHistoryChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowACRCollection
         * Whether the user allows their automatic content recognition data to be collected
         */
        void setAllowACRCollection( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowAppContentAdTargeting
         * Whether the user allows ads to be targeted to the user while watching content in apps
         */
        void setAllowAppContentAdTargeting( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowCameraAnalytics
         * Whether the user allows data from their camera to be used for Product Analytics
         */
        void setAllowCameraAnalytics( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowPersonalization
         * Whether the user allows their usage data to be used for personalization and recommendations
         */
        void setAllowPersonalization( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowPrimaryBrowseAdTargeting
         * Whether the user allows ads to be targeted to the user while browsing in the primary experience
         */
        void setAllowPrimaryBrowseAdTargeting( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowPrimaryContentAdTargeting
         * Whether the user allows ads to be targeted to the user while watching content in the primary experience
         */
        void setAllowPrimaryContentAdTargeting( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowProductAnalytics
         * Whether the user allows their usage data can be used for analytics about the product
         */
        void setAllowProductAnalytics( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowRemoteDiagnostics
         * Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device
         */
        void setAllowRemoteDiagnostics( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowResumePoints
         * Whether the user allows resume points for content to show in the main experience
         */
        void setAllowResumePoints( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowUnentitledPersonalization
         * Whether the user allows their usage data to be used for personalization and recommendations for unentitled content
         */
        void setAllowUnentitledPersonalization( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowUnentitledResumePoints
         * Whether the user allows resume points for content from unentitled providers to show in the main experience
         */
        void setAllowUnentitledResumePoints( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         * setAllowWatchHistory
         * Whether the user allows their watch history from all sources to show in the main experience
         */
        void setAllowWatchHistory( const bool value, Firebolt::Error *err = nullptr ) override;

        /*
         settings
         Gets the allowed value for all privacy settings
         */
        PrivacySettings settings( Firebolt::Error *err = nullptr ) const override;

    };

}//namespace Privacy
}
