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
#include "common/entertainment.h"

namespace Firebolt {
namespace Entity {


// Enums
/* ChannelEntityChannelType  */
enum class ChannelEntityChannelType {
    STREAMING,
    OVER_THE_AIR
};

/* AdditionalEntityProgramType  */
enum class AdditionalEntityProgramType {
    CONCERT,
    SPORTING_EVENT,
    PREVIEW,
    OTHER,
    ADVERTISEMENT,
    MUSIC_VIDEO,
    MINISODE,
    EXTRA
};


// Types
struct MusicEntity {
    std::string entityType;
    Entertainment::MusicType musicType;
    std::string entityId;
};

struct TVEpisodeEntity {
    std::string entityType;
    std::string programType;
    std::string entityId;
    std::string seriesId;
    std::string seasonId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

struct TVSeasonEntity {
    std::string entityType;
    std::string programType;
    std::string entityId;
    std::string seriesId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

struct TVSeriesEntity {
    std::string entityType;
    std::string programType;
    std::string entityId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

struct AdditionalEntity {
    std::string entityType;
    AdditionalEntityProgramType programType;
    std::string entityId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

struct PlaylistEntity {
    std::string entityType;
    std::string entityId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

struct MovieEntity {
    std::string entityType;
    std::string programType;
    std::string entityId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

/* anyOf schema shape is not supported right now */

struct UntypedEntity {
    std::string entityId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

struct ChannelEntity {
    std::string entityType;
    ChannelEntityChannelType channelType;
    std::string entityId;
    std::optional<std::string> appContentData;
};

/* anyOf schema shape is not supported right now */

/* anyOf schema shape is not supported right now */


} //namespace Entity
}
