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

#include "privacy_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Privacy {

    // Methods
    /* allowACRCollection - Whether the user allows their automatic content recognition data to be collected */
    bool PrivacyImpl::allowACRCollection( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowACRCollection");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowACRCollection - Whether the user allows their automatic content recognition data to be collected */
    void PrivacyImpl::setAllowACRCollection( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowACRCollection");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowAppContentAdTargeting - Whether the user allows ads to be targeted to the user while watching content in apps */
    bool PrivacyImpl::allowAppContentAdTargeting( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowAppContentAdTargeting");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowAppContentAdTargeting - Whether the user allows ads to be targeted to the user while watching content in apps */
    void PrivacyImpl::setAllowAppContentAdTargeting( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowAppContentAdTargeting");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowCameraAnalytics - Whether the user allows data from their camera to be used for Product Analytics */
    bool PrivacyImpl::allowCameraAnalytics( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowCameraAnalytics");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowCameraAnalytics - Whether the user allows data from their camera to be used for Product Analytics */
    void PrivacyImpl::setAllowCameraAnalytics( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowCameraAnalytics");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowPersonalization - Whether the user allows their usage data to be used for personalization and recommendations */
    bool PrivacyImpl::allowPersonalization( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowPersonalization");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowPersonalization - Whether the user allows their usage data to be used for personalization and recommendations */
    void PrivacyImpl::setAllowPersonalization( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowPersonalization");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowPrimaryBrowseAdTargeting - Whether the user allows ads to be targeted to the user while browsing in the primary experience */
    bool PrivacyImpl::allowPrimaryBrowseAdTargeting( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowPrimaryBrowseAdTargeting");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowPrimaryBrowseAdTargeting - Whether the user allows ads to be targeted to the user while browsing in the primary experience */
    void PrivacyImpl::setAllowPrimaryBrowseAdTargeting( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowPrimaryBrowseAdTargeting");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowPrimaryContentAdTargeting - Whether the user allows ads to be targeted to the user while watching content in the primary experience */
    bool PrivacyImpl::allowPrimaryContentAdTargeting( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowPrimaryContentAdTargeting");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowPrimaryContentAdTargeting - Whether the user allows ads to be targeted to the user while watching content in the primary experience */
    void PrivacyImpl::setAllowPrimaryContentAdTargeting( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowPrimaryContentAdTargeting");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowProductAnalytics - Whether the user allows their usage data can be used for analytics about the product */
    bool PrivacyImpl::allowProductAnalytics( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowProductAnalytics");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowProductAnalytics - Whether the user allows their usage data can be used for analytics about the product */
    void PrivacyImpl::setAllowProductAnalytics( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowProductAnalytics");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowRemoteDiagnostics - Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device */
    bool PrivacyImpl::allowRemoteDiagnostics( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowRemoteDiagnostics");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowRemoteDiagnostics - Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device */
    void PrivacyImpl::setAllowRemoteDiagnostics( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowRemoteDiagnostics");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowResumePoints - Whether the user allows resume points for content to show in the main experience */
    bool PrivacyImpl::allowResumePoints( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowResumePoints");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowResumePoints - Whether the user allows resume points for content to show in the main experience */
    void PrivacyImpl::setAllowResumePoints( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowResumePoints");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowUnentitledPersonalization - Whether the user allows their usage data to be used for personalization and recommendations for unentitled content */
    bool PrivacyImpl::allowUnentitledPersonalization( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowUnentitledPersonalization");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowUnentitledPersonalization - Whether the user allows their usage data to be used for personalization and recommendations for unentitled content */
    void PrivacyImpl::setAllowUnentitledPersonalization( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowUnentitledPersonalization");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowUnentitledResumePoints - Whether the user allows resume points for content from unentitled providers to show in the main experience */
    bool PrivacyImpl::allowUnentitledResumePoints( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowUnentitledResumePoints");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowUnentitledResumePoints - Whether the user allows resume points for content from unentitled providers to show in the main experience */
    void PrivacyImpl::setAllowUnentitledResumePoints( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowUnentitledResumePoints");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* allowWatchHistory - Whether the user allows their watch history from all sources to show in the main experience */
    bool PrivacyImpl::allowWatchHistory( Firebolt::Error *err ) const
    {
        const string method = _T("privacy.allowWatchHistory");
        
        
        WPEFramework::Core::JSON::Boolean jsonResult;
        bool allow = false;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            allow = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }
    /* setAllowWatchHistory - Whether the user allows their watch history from all sources to show in the main experience */
    void PrivacyImpl::setAllowWatchHistory( const bool value, Firebolt::Error *err )
    {
        const string method = _T("privacy.setAllowWatchHistory");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* settings - Gets the allowed value for all privacy settings */
    PrivacySettings PrivacyImpl::settings( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        PrivacySettings settings;

        JsonObject jsonParameters;

        Firebolt::Privacy::JsonData_PrivacySettings jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("privacy.settings", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Privacy.settings is successfully invoked");
            PrivacySettings settingsResult;
                settingsResult.allowACRCollection = jsonResult.AllowACRCollection.Value();
                settingsResult.allowResumePoints = jsonResult.AllowResumePoints.Value();
                settingsResult.allowAppContentAdTargeting = jsonResult.AllowAppContentAdTargeting.Value();
                settingsResult.allowCameraAnalytics = jsonResult.AllowCameraAnalytics.Value();
                settingsResult.allowPersonalization = jsonResult.AllowPersonalization.Value();
                settingsResult.allowPrimaryBrowseAdTargeting = jsonResult.AllowPrimaryBrowseAdTargeting.Value();
                settingsResult.allowPrimaryContentAdTargeting = jsonResult.AllowPrimaryContentAdTargeting.Value();
                settingsResult.allowProductAnalytics = jsonResult.AllowProductAnalytics.Value();
                settingsResult.allowRemoteDiagnostics = jsonResult.AllowRemoteDiagnostics.Value();
                settingsResult.allowUnentitledPersonalization = jsonResult.AllowUnentitledPersonalization.Value();
                settingsResult.allowUnentitledResumePoints = jsonResult.AllowUnentitledResumePoints.Value();
                settingsResult.allowWatchHistory = jsonResult.AllowWatchHistory.Value();
                settings = settingsResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return settings;
    }


    // Events
    /* onAllowACRCollectionChanged - Whether the user allows their automatic content recognition data to be collected */
    static void onAllowACRCollectionChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowACRCollectionChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowACRCollectionChangedNotification*>(notification));
            notifier.onAllowACRCollectionChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowACRCollectionChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowACRCollectionChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowACRCollectionChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowACRCollectionChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowACRCollectionChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowAppContentAdTargetingChanged - Whether the user allows ads to be targeted to the user while watching content in apps */
    static void onAllowAppContentAdTargetingChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowAppContentAdTargetingChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowAppContentAdTargetingChangedNotification*>(notification));
            notifier.onAllowAppContentAdTargetingChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowAppContentAdTargetingChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowAppContentAdTargetingChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowAppContentAdTargetingChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowAppContentAdTargetingChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowAppContentAdTargetingChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowCameraAnalyticsChanged - Whether the user allows data from their camera to be used for Product Analytics */
    static void onAllowCameraAnalyticsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowCameraAnalyticsChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowCameraAnalyticsChangedNotification*>(notification));
            notifier.onAllowCameraAnalyticsChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowCameraAnalyticsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowCameraAnalyticsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowCameraAnalyticsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowCameraAnalyticsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowCameraAnalyticsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowPersonalizationChanged - Whether the user allows their usage data to be used for personalization and recommendations */
    static void onAllowPersonalizationChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowPersonalizationChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowPersonalizationChangedNotification*>(notification));
            notifier.onAllowPersonalizationChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowPersonalizationChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowPersonalizationChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowPersonalizationChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowPersonalizationChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowPersonalizationChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowPrimaryBrowseAdTargetingChanged - Whether the user allows ads to be targeted to the user while browsing in the primary experience */
    static void onAllowPrimaryBrowseAdTargetingChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowPrimaryBrowseAdTargetingChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowPrimaryBrowseAdTargetingChangedNotification*>(notification));
            notifier.onAllowPrimaryBrowseAdTargetingChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowPrimaryBrowseAdTargetingChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowPrimaryBrowseAdTargetingChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowPrimaryBrowseAdTargetingChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowPrimaryBrowseAdTargetingChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowPrimaryBrowseAdTargetingChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowPrimaryContentAdTargetingChanged - Whether the user allows ads to be targeted to the user while watching content in the primary experience */
    static void onAllowPrimaryContentAdTargetingChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowPrimaryContentAdTargetingChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowPrimaryContentAdTargetingChangedNotification*>(notification));
            notifier.onAllowPrimaryContentAdTargetingChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowPrimaryContentAdTargetingChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowPrimaryContentAdTargetingChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowPrimaryContentAdTargetingChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowPrimaryContentAdTargetingChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowPrimaryContentAdTargetingChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowProductAnalyticsChanged - Whether the user allows their usage data can be used for analytics about the product */
    static void onAllowProductAnalyticsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowProductAnalyticsChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowProductAnalyticsChangedNotification*>(notification));
            notifier.onAllowProductAnalyticsChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowProductAnalyticsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowProductAnalyticsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowProductAnalyticsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowProductAnalyticsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowProductAnalyticsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowRemoteDiagnosticsChanged - Whether the user allows their personal data to be included in diagnostic telemetry. This also allows whether device logs can be remotely accessed from the client device */
    static void onAllowRemoteDiagnosticsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowRemoteDiagnosticsChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowRemoteDiagnosticsChangedNotification*>(notification));
            notifier.onAllowRemoteDiagnosticsChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowRemoteDiagnosticsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowRemoteDiagnosticsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowRemoteDiagnosticsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowRemoteDiagnosticsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowRemoteDiagnosticsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowResumePointsChanged - Whether the user allows resume points for content to show in the main experience */
    static void onAllowResumePointsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowResumePointsChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowResumePointsChangedNotification*>(notification));
            notifier.onAllowResumePointsChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowResumePointsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowResumePointsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowResumePointsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowResumePointsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowResumePointsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowUnentitledPersonalizationChanged - Whether the user allows their usage data to be used for personalization and recommendations for unentitled content */
    static void onAllowUnentitledPersonalizationChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowUnentitledPersonalizationChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowUnentitledPersonalizationChangedNotification*>(notification));
            notifier.onAllowUnentitledPersonalizationChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowUnentitledPersonalizationChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowUnentitledPersonalizationChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowUnentitledPersonalizationChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowUnentitledPersonalizationChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowUnentitledPersonalizationChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowUnentitledResumePointsChanged - Whether the user allows resume points for content from unentitled providers to show in the main experience */
    static void onAllowUnentitledResumePointsChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowUnentitledResumePointsChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowUnentitledResumePointsChangedNotification*>(notification));
            notifier.onAllowUnentitledResumePointsChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowUnentitledResumePointsChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowUnentitledResumePointsChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowUnentitledResumePointsChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowUnentitledResumePointsChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowUnentitledResumePointsChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onAllowWatchHistoryChanged - Whether the user allows their watch history from all sources to show in the main experience */
    static void onAllowWatchHistoryChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::Boolean>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            bool result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            IPrivacy::IOnAllowWatchHistoryChangedNotification& notifier = *(reinterpret_cast<IPrivacy::IOnAllowWatchHistoryChangedNotification*>(notification));
            notifier.onAllowWatchHistoryChanged(result);
        }
    }
    void PrivacyImpl::subscribe( IPrivacy::IOnAllowWatchHistoryChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("privacy.onAllowWatchHistoryChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::Boolean>(eventName, jsonParameters, onAllowWatchHistoryChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void PrivacyImpl::unsubscribe( IPrivacy::IOnAllowWatchHistoryChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("privacy.onAllowWatchHistoryChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Privacy
}

