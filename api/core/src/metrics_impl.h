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
#include "jsondata_types.h"
#include "metrics.h"


namespace Firebolt {
namespace Metrics {


    using JsonData_ErrorType = WPEFramework::Core::JSON::EnumType<ErrorType>;

    using JsonData_Category = WPEFramework::Core::JSON::EnumType<Category>;


    // Types
    /* anyOf schema shape is not supported right now */
    class MetricsImpl : public IMetrics, public IModule {

    public:
        MetricsImpl() = default;
        MetricsImpl(const MetricsImpl&) = delete;
        MetricsImpl& operator=(const MetricsImpl&) = delete;

        ~MetricsImpl() override = default;

   
         bool ready( Firebolt::Error *err = nullptr )   ;
         bool signIn( Firebolt::Error *err = nullptr )  ;
         bool signOut( Firebolt::Error *err = nullptr ) ;
    


        // Methods & Events
        /*
         action
         Inform the platform of something not covered by other Metrics APIs.
         */
        bool action( const Category& category, const std::string& type, const std::optional<Types::FlatMap>& parameters, Firebolt::Error *err = nullptr ) override;

        /*
         error
         Inform the platform of an error that has occured in your app.
         */
        bool error( const ErrorType& type, const std::string& code, const std::string& description, const bool visible, const std::optional<Types::FlatMap>& parameters, Firebolt::Error *err = nullptr ) override;

        /*
         mediaEnded
         Called when playback has stopped because the end of the media was reached.
         */
        bool mediaEnded( const std::string& entityId, Firebolt::Error *err = nullptr ) override;

        /*
         mediaLoadStart
         Called when setting the URL of a media asset to play, in order to infer load time.
         */
        bool mediaLoadStart( const std::string& entityId, Firebolt::Error *err = nullptr ) override;

        /*
         mediaPause
         Called when media playback will pause due to an intentional pause operation.
         */
        bool mediaPause( const std::string& entityId, Firebolt::Error *err = nullptr ) override;

        /*
         mediaPlay
         Called when media playback should start due to autoplay, user-initiated play, or unpausing.
         */
        bool mediaPlay( const std::string& entityId, Firebolt::Error *err = nullptr ) override;

        /*
         mediaPlaying
         Called when media playback actually starts due to autoplay, user-initiated play, unpausing, or recovering from a buffering interuption.
         */
        bool mediaPlaying( const std::string& entityId, Firebolt::Error *err = nullptr ) override;

        /*
         mediaProgress
         Called every 60 seconds as media playback progresses.
         */
        bool mediaProgress( const std::string& entityId, const std::string& progress, Firebolt::Error *err = nullptr ) override;

        /*
         mediaRateChange
         Called when the playback rate of media is changed.
         */
        bool mediaRateChange( const std::string& entityId, const float rate, Firebolt::Error *err = nullptr ) override;

        /*
         mediaRenditionChange
         Called when the playback rendition (e.g. bitrate, dimensions, profile, etc) is changed.
         */
        bool mediaRenditionChange( const std::string& entityId, const float bitrate, const float width, const float height, const std::optional<std::string>& profile, Firebolt::Error *err = nullptr ) override;

        /*
         mediaSeeked
         Called when a seek is completed during media playback.
         */
        bool mediaSeeked( const std::string& entityId, const std::string& position, Firebolt::Error *err = nullptr ) override;

        /*
         mediaSeeking
         Called when a seek is initiated during media playback.
         */
        bool mediaSeeking( const std::string& entityId, const std::string& target, Firebolt::Error *err = nullptr ) override;

        /*
         mediaWaiting
         Called when media playback will halt due to a network, buffer, or other unintentional constraint.
         */
        bool mediaWaiting( const std::string& entityId, Firebolt::Error *err = nullptr ) override;

        /*
         page
         Inform the platform that your user has navigated to a page or view.
         */
        bool page( const std::string& pageId, Firebolt::Error *err = nullptr ) override;

        /*
         startContent
         Inform the platform that your user has started content.
         */
        bool startContent( const std::optional<std::string>& entityId, Firebolt::Error *err = nullptr ) override;

        /*
         stopContent
         Inform the platform that your user has stopped content.
         */
        bool stopContent( const std::optional<std::string>& entityId, Firebolt::Error *err = nullptr ) override;

    };

}//namespace Metrics
}