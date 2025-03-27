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
#include "jsondata_entertainment.h"
#include "common/entity.h"

namespace Firebolt {
namespace Entity {

    // Types
    using JsonData_ChannelEntityChannelType = WPEFramework::Core::JSON::EnumType<ChannelEntityChannelType>;

    class JsonData_MusicEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_MusicEntity() override = default;
  
    public:
        JsonData_MusicEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("musicType"), &MusicType);
            Add(_T("entityId"), &EntityId);
        }

        JsonData_MusicEntity(const JsonData_MusicEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("musicType"), &MusicType);
            MusicType = other.MusicType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
        }

        JsonData_MusicEntity& operator=(const JsonData_MusicEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("musicType"), &MusicType);
            MusicType = other.MusicType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String EntityType;
        Firebolt::Entertainment::JsonData_MusicType MusicType;
        FireboltSDK::JSON::String EntityId;
    };

    class JsonData_PlaylistEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlaylistEntity() override = default;
  
    public:
        JsonData_PlaylistEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("entityId"), &EntityId);
            Add(_T("assetId"), &AssetId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_PlaylistEntity(const JsonData_PlaylistEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_PlaylistEntity& operator=(const JsonData_PlaylistEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String EntityType;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String AppContentData;
    };

    class JsonData_UntypedEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_UntypedEntity() override = default;
  
    public:
        JsonData_UntypedEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityId"), &EntityId);
            Add(_T("assetId"), &AssetId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_UntypedEntity(const JsonData_UntypedEntity& other)
        {
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_UntypedEntity& operator=(const JsonData_UntypedEntity& other)
        {
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String AppContentData;
    };

    class JsonData_ChannelEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_ChannelEntity() override = default;
  
    public:
        JsonData_ChannelEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("channelType"), &ChannelType);
            Add(_T("entityId"), &EntityId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_ChannelEntity(const JsonData_ChannelEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("channelType"), &ChannelType);
            ChannelType = other.ChannelType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_ChannelEntity& operator=(const JsonData_ChannelEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("channelType"), &ChannelType);
            ChannelType = other.ChannelType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String EntityType;
        Firebolt::Entity::JsonData_ChannelEntityChannelType ChannelType;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String AppContentData;
    };

    class JsonData_Metadata: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_Metadata() override = default;
  
    public:
        JsonData_Metadata()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("title"), &Title);
            Add(_T("synopsis"), &Synopsis);
            Add(_T("seasonNumber"), &SeasonNumber);
            Add(_T("seasonCount"), &SeasonCount);
            Add(_T("episodeNumber"), &EpisodeNumber);
            Add(_T("episodeCount"), &EpisodeCount);
            Add(_T("releaseDate"), &ReleaseDate);
            Add(_T("contentRatings"), &ContentRatings);
        }

        JsonData_Metadata(const JsonData_Metadata& other)
        {
            Add(_T("title"), &Title);
            Title = other.Title;
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
        }

        JsonData_Metadata& operator=(const JsonData_Metadata& other)
        {
            Add(_T("title"), &Title);
            Title = other.Title;
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
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Title;
        FireboltSDK::JSON::String Synopsis;
        WPEFramework::Core::JSON::Float SeasonNumber;
        WPEFramework::Core::JSON::Float SeasonCount;
        WPEFramework::Core::JSON::Float EpisodeNumber;
        WPEFramework::Core::JSON::Float EpisodeCount;
        FireboltSDK::JSON::String ReleaseDate;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_ContentRating> ContentRatings;
    };

    /* anyOf schema shape is not supported right now */
    class JsonData_EntityDetails: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_EntityDetails() override = default;
  
    public:
        JsonData_EntityDetails()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("identifiers"), &Identifiers);
            Add(_T("info"), &Info);
            Add(_T("waysToWatch"), &WaysToWatch);
        }

        JsonData_EntityDetails(const JsonData_EntityDetails& other)
        {
            Add(_T("identifiers"), &Identifiers);
            Identifiers = other.Identifiers;
            Add(_T("info"), &Info);
            Info = other.Info;
            Add(_T("waysToWatch"), &WaysToWatch);
            WaysToWatch = other.WaysToWatch;
        }

        JsonData_EntityDetails& operator=(const JsonData_EntityDetails& other)
        {
            Add(_T("identifiers"), &Identifiers);
            Identifiers = other.Identifiers;
            Add(_T("info"), &Info);
            Info = other.Info;
            Add(_T("waysToWatch"), &WaysToWatch);
            WaysToWatch = other.WaysToWatch;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Identifiers;
        Firebolt::Entity::JsonData_Metadata Info;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_WayToWatch> WaysToWatch;
    };

}
}
