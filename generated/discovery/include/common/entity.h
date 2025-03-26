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


// Types
struct MusicEntity {
    std::string entityType;
    Entertainment::MusicType musicType;
    std::string entityId;
};

struct PlaylistEntity {
    std::string entityType;
    std::string entityId;
    std::optional<std::string> assetId;
    std::optional<std::string> appContentData;
};

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

struct Metadata {
    std::optional<std::string> title;
    std::optional<std::string> synopsis;
    std::optional<float> seasonNumber;
    std::optional<float> seasonCount;
    std::optional<float> episodeNumber;
    std::optional<float> episodeCount;
    std::optional<std::string> releaseDate;
    std::optional<std::vector<Entertainment::ContentRating>> contentRatings;
};

/* anyOf schema shape is not supported right now */

struct EntityDetails {
    std::string identifiers;
    std::optional<Metadata> info;
    std::optional<std::vector<Entertainment::WayToWatch>> waysToWatch;
};


} //namespace Entity
}
