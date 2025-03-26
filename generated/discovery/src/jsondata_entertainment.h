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
#include "jsondata_types.h"
#include "common/entertainment.h"

namespace Firebolt {
namespace Entertainment {

    // Types
    using JsonData_MusicType = WPEFramework::Core::JSON::EnumType<MusicType>;

    using JsonData_OfferingType = WPEFramework::Core::JSON::EnumType<OfferingType>;

    using JsonData_WayToWatchVideoQuality = WPEFramework::Core::JSON::EnumType<WayToWatchVideoQuality>;

    using JsonData_ContentRatingScheme = WPEFramework::Core::JSON::EnumType<ContentRatingScheme>;

    class JsonData_ContentIdentifiers: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_ContentIdentifiers() override = default;
  
    public:
        JsonData_ContentIdentifiers()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("assetId"), &AssetId);
            Add(_T("entityId"), &EntityId);
            Add(_T("seasonId"), &SeasonId);
            Add(_T("seriesId"), &SeriesId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_ContentIdentifiers(const JsonData_ContentIdentifiers& other)
        {
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("seasonId"), &SeasonId);
            SeasonId = other.SeasonId;
            Add(_T("seriesId"), &SeriesId);
            SeriesId = other.SeriesId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_ContentIdentifiers& operator=(const JsonData_ContentIdentifiers& other)
        {
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("seasonId"), &SeasonId);
            SeasonId = other.SeasonId;
            Add(_T("seriesId"), &SeriesId);
            SeriesId = other.SeriesId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String SeasonId;
        FireboltSDK::JSON::String SeriesId;
        FireboltSDK::JSON::String AppContentData;
    };

    class JsonData_WayToWatch: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_WayToWatch() override = default;
  
    public:
        JsonData_WayToWatch()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("identifiers"), &Identifiers);
            Add(_T("expires"), &Expires);
            Add(_T("entitled"), &Entitled);
            Add(_T("entitledExpires"), &EntitledExpires);
            Add(_T("offeringType"), &OfferingType);
            Add(_T("hasAds"), &HasAds);
            Add(_T("price"), &Price);
            Add(_T("videoQuality"), &VideoQuality);
            Add(_T("audioProfile"), &AudioProfile);
            Add(_T("audioLanguages"), &AudioLanguages);
            Add(_T("closedCaptions"), &ClosedCaptions);
            Add(_T("subtitles"), &Subtitles);
            Add(_T("audioDescriptions"), &AudioDescriptions);
        }

        JsonData_WayToWatch(const JsonData_WayToWatch& other)
        {
            Add(_T("identifiers"), &Identifiers);
            Identifiers = other.Identifiers;
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("entitled"), &Entitled);
            Entitled = other.Entitled;
            Add(_T("entitledExpires"), &EntitledExpires);
            EntitledExpires = other.EntitledExpires;
            Add(_T("offeringType"), &OfferingType);
            OfferingType = other.OfferingType;
            Add(_T("hasAds"), &HasAds);
            HasAds = other.HasAds;
            Add(_T("price"), &Price);
            Price = other.Price;
            Add(_T("videoQuality"), &VideoQuality);
            VideoQuality = other.VideoQuality;
            Add(_T("audioProfile"), &AudioProfile);
            AudioProfile = other.AudioProfile;
            Add(_T("audioLanguages"), &AudioLanguages);
            AudioLanguages = other.AudioLanguages;
            Add(_T("closedCaptions"), &ClosedCaptions);
            ClosedCaptions = other.ClosedCaptions;
            Add(_T("subtitles"), &Subtitles);
            Subtitles = other.Subtitles;
            Add(_T("audioDescriptions"), &AudioDescriptions);
            AudioDescriptions = other.AudioDescriptions;
        }

        JsonData_WayToWatch& operator=(const JsonData_WayToWatch& other)
        {
            Add(_T("identifiers"), &Identifiers);
            Identifiers = other.Identifiers;
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("entitled"), &Entitled);
            Entitled = other.Entitled;
            Add(_T("entitledExpires"), &EntitledExpires);
            EntitledExpires = other.EntitledExpires;
            Add(_T("offeringType"), &OfferingType);
            OfferingType = other.OfferingType;
            Add(_T("hasAds"), &HasAds);
            HasAds = other.HasAds;
            Add(_T("price"), &Price);
            Price = other.Price;
            Add(_T("videoQuality"), &VideoQuality);
            VideoQuality = other.VideoQuality;
            Add(_T("audioProfile"), &AudioProfile);
            AudioProfile = other.AudioProfile;
            Add(_T("audioLanguages"), &AudioLanguages);
            AudioLanguages = other.AudioLanguages;
            Add(_T("closedCaptions"), &ClosedCaptions);
            ClosedCaptions = other.ClosedCaptions;
            Add(_T("subtitles"), &Subtitles);
            Subtitles = other.Subtitles;
            Add(_T("audioDescriptions"), &AudioDescriptions);
            AudioDescriptions = other.AudioDescriptions;
            return (*this);
        }

    public:
        Firebolt::Entertainment::JsonData_ContentIdentifiers Identifiers;
        FireboltSDK::JSON::String Expires;
        WPEFramework::Core::JSON::Boolean Entitled;
        FireboltSDK::JSON::String EntitledExpires;
        Firebolt::Entertainment::JsonData_OfferingType OfferingType;
        WPEFramework::Core::JSON::Boolean HasAds;
        WPEFramework::Core::JSON::Float Price;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_WayToWatchVideoQuality> VideoQuality;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Types::JsonData_AudioProfile> AudioProfile;
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> AudioLanguages;
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> ClosedCaptions;
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> Subtitles;
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> AudioDescriptions;
    };

    class JsonData_ContentRating: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_ContentRating() override = default;
  
    public:
        JsonData_ContentRating()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("scheme"), &Scheme);
            Add(_T("rating"), &Rating);
            Add(_T("advisories"), &Advisories);
        }

        JsonData_ContentRating(const JsonData_ContentRating& other)
        {
            Add(_T("scheme"), &Scheme);
            Scheme = other.Scheme;
            Add(_T("rating"), &Rating);
            Rating = other.Rating;
            Add(_T("advisories"), &Advisories);
            Advisories = other.Advisories;
        }

        JsonData_ContentRating& operator=(const JsonData_ContentRating& other)
        {
            Add(_T("scheme"), &Scheme);
            Scheme = other.Scheme;
            Add(_T("rating"), &Rating);
            Rating = other.Rating;
            Add(_T("advisories"), &Advisories);
            Advisories = other.Advisories;
            return (*this);
        }

    public:
        Firebolt::Entertainment::JsonData_ContentRatingScheme Scheme;
        FireboltSDK::JSON::String Rating;
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> Advisories;
    };

}
}
