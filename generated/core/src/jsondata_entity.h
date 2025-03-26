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

    using JsonData_AdditionalEntityProgramType = WPEFramework::Core::JSON::EnumType<AdditionalEntityProgramType>;

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

    class JsonData_TVEpisodeEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_TVEpisodeEntity() override = default;
  
    public:
        JsonData_TVEpisodeEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("programType"), &ProgramType);
            Add(_T("entityId"), &EntityId);
            Add(_T("seriesId"), &SeriesId);
            Add(_T("seasonId"), &SeasonId);
            Add(_T("assetId"), &AssetId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_TVEpisodeEntity(const JsonData_TVEpisodeEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("seriesId"), &SeriesId);
            SeriesId = other.SeriesId;
            Add(_T("seasonId"), &SeasonId);
            SeasonId = other.SeasonId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_TVEpisodeEntity& operator=(const JsonData_TVEpisodeEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("seriesId"), &SeriesId);
            SeriesId = other.SeriesId;
            Add(_T("seasonId"), &SeasonId);
            SeasonId = other.SeasonId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String EntityType;
        FireboltSDK::JSON::String ProgramType;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String SeriesId;
        FireboltSDK::JSON::String SeasonId;
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String AppContentData;
    };

    class JsonData_TVSeasonEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_TVSeasonEntity() override = default;
  
    public:
        JsonData_TVSeasonEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("programType"), &ProgramType);
            Add(_T("entityId"), &EntityId);
            Add(_T("seriesId"), &SeriesId);
            Add(_T("assetId"), &AssetId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_TVSeasonEntity(const JsonData_TVSeasonEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("seriesId"), &SeriesId);
            SeriesId = other.SeriesId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_TVSeasonEntity& operator=(const JsonData_TVSeasonEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("seriesId"), &SeriesId);
            SeriesId = other.SeriesId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String EntityType;
        FireboltSDK::JSON::String ProgramType;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String SeriesId;
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String AppContentData;
    };

    class JsonData_TVSeriesEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_TVSeriesEntity() override = default;
  
    public:
        JsonData_TVSeriesEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("programType"), &ProgramType);
            Add(_T("entityId"), &EntityId);
            Add(_T("assetId"), &AssetId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_TVSeriesEntity(const JsonData_TVSeriesEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_TVSeriesEntity& operator=(const JsonData_TVSeriesEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
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
        FireboltSDK::JSON::String ProgramType;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String AppContentData;
    };

    class JsonData_AdditionalEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AdditionalEntity() override = default;
  
    public:
        JsonData_AdditionalEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("programType"), &ProgramType);
            Add(_T("entityId"), &EntityId);
            Add(_T("assetId"), &AssetId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_AdditionalEntity(const JsonData_AdditionalEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_AdditionalEntity& operator=(const JsonData_AdditionalEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
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
        Firebolt::Entity::JsonData_AdditionalEntityProgramType ProgramType;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String AppContentData;
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

    class JsonData_MovieEntity: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_MovieEntity() override = default;
  
    public:
        JsonData_MovieEntity()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entityType"), &EntityType);
            Add(_T("programType"), &ProgramType);
            Add(_T("entityId"), &EntityId);
            Add(_T("assetId"), &AssetId);
            Add(_T("appContentData"), &AppContentData);
        }

        JsonData_MovieEntity(const JsonData_MovieEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
            Add(_T("entityId"), &EntityId);
            EntityId = other.EntityId;
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("appContentData"), &AppContentData);
            AppContentData = other.AppContentData;
        }

        JsonData_MovieEntity& operator=(const JsonData_MovieEntity& other)
        {
            Add(_T("entityType"), &EntityType);
            EntityType = other.EntityType;
            Add(_T("programType"), &ProgramType);
            ProgramType = other.ProgramType;
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
        FireboltSDK::JSON::String ProgramType;
        FireboltSDK::JSON::String EntityId;
        FireboltSDK::JSON::String AssetId;
        FireboltSDK::JSON::String AppContentData;
    };

    /* anyOf schema shape is not supported right now */
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

    /* anyOf schema shape is not supported right now */
    /* anyOf schema shape is not supported right now */
}
}
