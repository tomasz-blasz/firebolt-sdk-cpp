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
    using JsonData_ProgramType = WPEFramework::Core::JSON::EnumType<ProgramType>;

    using JsonData_MusicType = WPEFramework::Core::JSON::EnumType<MusicType>;

    using JsonData_OfferingType = WPEFramework::Core::JSON::EnumType<OfferingType>;

    using JsonData_EntityInfoEntityType = WPEFramework::Core::JSON::EnumType<EntityInfoEntityType>;

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

    class JsonData_Entitlement: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_Entitlement() override = default;
  
    public:
        JsonData_Entitlement()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entitlementId"), &EntitlementId);
            Add(_T("startTime"), &StartTime);
            Add(_T("endTime"), &EndTime);
        }

        JsonData_Entitlement(const JsonData_Entitlement& other)
        {
            Add(_T("entitlementId"), &EntitlementId);
            EntitlementId = other.EntitlementId;
            Add(_T("startTime"), &StartTime);
            StartTime = other.StartTime;
            Add(_T("endTime"), &EndTime);
            EndTime = other.EndTime;
        }

        JsonData_Entitlement& operator=(const JsonData_Entitlement& other)
        {
            Add(_T("entitlementId"), &EntitlementId);
            EntitlementId = other.EntitlementId;
            Add(_T("startTime"), &StartTime);
            StartTime = other.StartTime;
            Add(_T("endTime"), &EndTime);
            EndTime = other.EndTime;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String EntitlementId;
        FireboltSDK::JSON::String StartTime;
        FireboltSDK::JSON::String EndTime;
    };

    class JsonData_EntityInfo: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_EntityInfo() override = default;
  
    public:
        JsonData_EntityInfo()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("identifiers"), &Identifiers);
            Add(_T("title"), &Title);
            Add(_T("entityType"), &EntityType);
            Add(_T("programType"), &ProgramType);
            Add(_T("musicType"), &MusicType);
            Add(_T("synopsis"), &Synopsis);
            Add(_T("seasonNumber"), &SeasonNumber);
            Add(_T("seasonCount"), &SeasonCount);
            Add(_T("episodeNumber"), &EpisodeNumber);
            Add(_T("episodeCount"), &EpisodeCount);
            Add(_T("releaseDate"), &ReleaseDate);
            Add(_T("contentRatings"), &ContentRatings);
            Add(_T("waysToWatch"), &WaysToWatch);
        }

        JsonData_EntityInfo(const JsonData_EntityInfo& other)
        {
            Add(_T("identifiers"), &Identifiers);
            Identifiers = other.Identifiers;
            Add(_T("title"), &Title);
            Title = other.Title;
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("musicType"), &MusicType);
            MusicType = other.MusicType;
            Add(_T("synopsis"), &Synopsis);
            Synopsis = other.Synopsis;
            Add(_T("seasonNumber"), &SeasonNumber);
            SeasonNumber = other.SeasonNumber;
            Add(_T("seasonCount"), &SeasonCount);
            SeasonCount = other.SeasonCount;
            Add(_T("episodeNumber"), &EpisodeNumber);
            EpisodeNumber = other.EpisodeNumber;
            Add(_T("episodeCount"), &EpisodeCount);
            EpisodeCount = other.EpisodeCount;
            Add(_T("releaseDate"), &ReleaseDate);
            ReleaseDate = other.ReleaseDate;
            Add(_T("contentRatings"), &ContentRatings);
            ContentRatings = other.ContentRatings;
            Add(_T("waysToWatch"), &WaysToWatch);
            WaysToWatch = other.WaysToWatch;
        }

        JsonData_EntityInfo& operator=(const JsonData_EntityInfo& other)
        {
            Add(_T("identifiers"), &Identifiers);
            Identifiers = other.Identifiers;
            Add(_T("title"), &Title);
            Title = other.Title;
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("musicType"), &MusicType);
            MusicType = other.MusicType;
            Add(_T("synopsis"), &Synopsis);
            Synopsis = other.Synopsis;
            Add(_T("seasonNumber"), &SeasonNumber);
            SeasonNumber = other.SeasonNumber;
            Add(_T("seasonCount"), &SeasonCount);
            SeasonCount = other.SeasonCount;
            Add(_T("episodeNumber"), &EpisodeNumber);
            EpisodeNumber = other.EpisodeNumber;
            Add(_T("episodeCount"), &EpisodeCount);
            EpisodeCount = other.EpisodeCount;
            Add(_T("releaseDate"), &ReleaseDate);
            ReleaseDate = other.ReleaseDate;
            Add(_T("contentRatings"), &ContentRatings);
            ContentRatings = other.ContentRatings;
            Add(_T("waysToWatch"), &WaysToWatch);
            WaysToWatch = other.WaysToWatch;
            return (*this);
        }

    public:
        Firebolt::Entertainment::JsonData_ContentIdentifiers Identifiers;
        FireboltSDK::JSON::String Title;
        Firebolt::Entertainment::JsonData_EntityInfoEntityType EntityType;
        Firebolt::Entertainment::JsonData_ProgramType ProgramType;
        Firebolt::Entertainment::JsonData_MusicType MusicType;
        FireboltSDK::JSON::String Synopsis;
        WPEFramework::Core::JSON::Float SeasonNumber;
        WPEFramework::Core::JSON::Float SeasonCount;
        WPEFramework::Core::JSON::Float EpisodeNumber;
        WPEFramework::Core::JSON::Float EpisodeCount;
        FireboltSDK::JSON::String ReleaseDate;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_ContentRating> ContentRatings;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_WayToWatch> WaysToWatch;
    };

}
}
