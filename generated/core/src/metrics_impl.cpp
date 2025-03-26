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

#include "metrics_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Metrics {


    /* ready - Inform the platform that your app is minimally usable. This method is called automatically by `Lifecycle.ready()` */
    bool MetricsImpl::ready( Firebolt::Error *err )
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.ready", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.ready is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* signIn - Log a sign In event, called by Discovery.signIn(). */
    bool MetricsImpl::signIn( Firebolt::Error *err )
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.signIn", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.signOut is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }
        return success;

    }

    /* signOut - Log a sign out event, called by Discovery.signOut(). */
    bool MetricsImpl::signOut( Firebolt::Error *err )
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.signOut", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.signOut is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }


    // Methods
    /* action - Inform the platform of something not covered by other Metrics APIs. */
    bool MetricsImpl::action( const Category& category, const std::string& type, const std::optional<Types::FlatMap>& parameters, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        JsonData_Category jsonCategory = category;
            WPEFramework::Core::JSON::Variant categoryVariant(jsonCategory.Data());
            jsonParameters.Set(_T("category"), categoryVariant);
            WPEFramework::Core::JSON::Variant typeVariant(type);
            jsonParameters.Set(_T("type"), typeVariant);
            Firebolt::Types::FlatMap map;
            if (parameters.has_value()) {
                map = parameters.value();
            }
            WPEFramework::Core::JSON::Variant parametersVariant;
            for (auto element: map) {
                WPEFramework::Core::JSON::Variant jsonElement = element.second;
                WPEFramework::Core::JSON::VariantContainer jsonContainer;
                jsonContainer.Set(element.first.c_str(), jsonElement);
                parametersVariant = jsonContainer;
            }
            jsonParameters.Set(_T("parameters"), parametersVariant);
    
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.action", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.action is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* error - Inform the platform of an error that has occured in your app. */
    bool MetricsImpl::error( const ErrorType& type, const std::string& code, const std::string& description, const bool visible, const std::optional<Types::FlatMap>& parameters, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        JsonData_ErrorType jsonType = type;
            WPEFramework::Core::JSON::Variant typeVariant(jsonType.Data());
            jsonParameters.Set(_T("type"), typeVariant);
            WPEFramework::Core::JSON::Variant codeVariant(code);
            jsonParameters.Set(_T("code"), codeVariant);
            WPEFramework::Core::JSON::Variant descriptionVariant(description);
            jsonParameters.Set(_T("description"), descriptionVariant);
            WPEFramework::Core::JSON::Variant visibleVariant(visible);
            jsonParameters.Set(_T("visible"), visibleVariant);
            Firebolt::Types::FlatMap map;
            if (parameters.has_value()) {
                map = parameters.value();
            }
            WPEFramework::Core::JSON::Variant parametersVariant;
            for (auto element: map) {
                WPEFramework::Core::JSON::Variant jsonElement = element.second;
                WPEFramework::Core::JSON::VariantContainer jsonContainer;
                jsonContainer.Set(element.first.c_str(), jsonElement);
                parametersVariant = jsonContainer;
            }
            jsonParameters.Set(_T("parameters"), parametersVariant);
    
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.error", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.error is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaEnded - Called when playback has stopped because the end of the media was reached. */
    bool MetricsImpl::mediaEnded( const std::string& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaEnded", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaEnded is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaLoadStart - Called when setting the URL of a media asset to play, in order to infer load time. */
    bool MetricsImpl::mediaLoadStart( const std::string& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaLoadStart", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaLoadStart is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaPause - Called when media playback will pause due to an intentional pause operation. */
    bool MetricsImpl::mediaPause( const std::string& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaPause", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaPause is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaPlay - Called when media playback should start due to autoplay, user-initiated play, or unpausing. */
    bool MetricsImpl::mediaPlay( const std::string& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaPlay", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaPlay is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaPlaying - Called when media playback actually starts due to autoplay, user-initiated play, unpausing, or recovering from a buffering interuption. */
    bool MetricsImpl::mediaPlaying( const std::string& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaPlaying", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaPlaying is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaProgress - Called every 60 seconds as media playback progresses. */
    bool MetricsImpl::mediaProgress( const std::string& entityId, const std::string& progress, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
            WPEFramework::Core::JSON::Variant progressVariant(progress);
            jsonParameters.Set(_T("progress"), progressVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaProgress", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaProgress is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaRateChange - Called when the playback rate of media is changed. */
    bool MetricsImpl::mediaRateChange( const std::string& entityId, const float rate, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
            WPEFramework::Core::JSON::Variant rateVariant(rate);
            jsonParameters.Set(_T("rate"), rateVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaRateChange", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaRateChange is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaRenditionChange - Called when the playback rendition (e.g. bitrate, dimensions, profile, etc) is changed. */
    bool MetricsImpl::mediaRenditionChange( const std::string& entityId, const float bitrate, const float width, const float height, const std::optional<std::string>& profile, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
            WPEFramework::Core::JSON::Variant bitrateVariant(bitrate);
            jsonParameters.Set(_T("bitrate"), bitrateVariant);
            WPEFramework::Core::JSON::Variant widthVariant(width);
            jsonParameters.Set(_T("width"), widthVariant);
            WPEFramework::Core::JSON::Variant heightVariant(height);
            jsonParameters.Set(_T("height"), heightVariant);
            if (profile.has_value()) {
                WPEFramework::Core::JSON::Variant profileVariant(profile.value());
                jsonParameters.Set(_T("profile"), profileVariant);
            }
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaRenditionChange", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaRenditionChange is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaSeeked - Called when a seek is completed during media playback. */
    bool MetricsImpl::mediaSeeked( const std::string& entityId, const std::string& position, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
            WPEFramework::Core::JSON::Variant positionVariant(position);
            jsonParameters.Set(_T("position"), positionVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaSeeked", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaSeeked is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaSeeking - Called when a seek is initiated during media playback. */
    bool MetricsImpl::mediaSeeking( const std::string& entityId, const std::string& target, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
            WPEFramework::Core::JSON::Variant targetVariant(target);
            jsonParameters.Set(_T("target"), targetVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaSeeking", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaSeeking is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* mediaWaiting - Called when media playback will halt due to a network, buffer, or other unintentional constraint. */
    bool MetricsImpl::mediaWaiting( const std::string& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant entityIdVariant(entityId);
            jsonParameters.Set(_T("entityId"), entityIdVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.mediaWaiting", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.mediaWaiting is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* page - Inform the platform that your user has navigated to a page or view. */
    bool MetricsImpl::page( const std::string& pageId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant pageIdVariant(pageId);
            jsonParameters.Set(_T("pageId"), pageIdVariant);
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.page", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.page is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* startContent - Inform the platform that your user has started content. */
    bool MetricsImpl::startContent( const std::optional<std::string>& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        if (entityId.has_value()) {
                WPEFramework::Core::JSON::Variant entityIdVariant(entityId.value());
                jsonParameters.Set(_T("entityId"), entityIdVariant);
            }
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.startContent", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.startContent is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }

    /* stopContent - Inform the platform that your user has stopped content. */
    bool MetricsImpl::stopContent( const std::optional<std::string>& entityId, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool success = false;

        JsonObject jsonParameters;
        if (entityId.has_value()) {
                WPEFramework::Core::JSON::Variant entityIdVariant(entityId.value());
                jsonParameters.Set(_T("entityId"), entityIdVariant);
            }
        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("metrics.stopContent", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Metrics.stopContent is successfully invoked");
            success = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return success;
    }


    // Events

}//namespace Metrics
}


namespace WPEFramework {

    /* ErrorType  */
    ENUM_CONVERSION_BEGIN(Firebolt::Metrics::ErrorType)
        { Firebolt::Metrics::ErrorType::NETWORK, _T("network") },
        { Firebolt::Metrics::ErrorType::MEDIA, _T("media") },
        { Firebolt::Metrics::ErrorType::RESTRICTION, _T("restriction") },
        { Firebolt::Metrics::ErrorType::ENTITLEMENT, _T("entitlement") },
        { Firebolt::Metrics::ErrorType::OTHER, _T("other") },
    ENUM_CONVERSION_END(Firebolt::Metrics::ErrorType)

    /* Category  */
    ENUM_CONVERSION_BEGIN(Firebolt::Metrics::Category)
        { Firebolt::Metrics::Category::USER, _T("user") },
        { Firebolt::Metrics::Category::APP, _T("app") },
    ENUM_CONVERSION_END(Firebolt::Metrics::Category)

}