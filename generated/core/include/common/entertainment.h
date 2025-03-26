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
#include "common/types.h"

namespace Firebolt {
namespace Entertainment {


// Enums
/* ProgramType In the case of a program `entityType`, specifies the program type. */
enum class ProgramType {
    MOVIE,
    EPISODE,
    SEASON,
    SERIES,
    OTHER,
    PREVIEW,
    EXTRA,
    CONCERT,
    SPORTING_EVENT,
    ADVERTISEMENT,
    MUSIC_VIDEO,
    MINISODE
};

/* MusicType In the case of a music `entityType`, specifies the type of music entity. */
enum class MusicType {
    SONG,
    ALBUM
};

/* OfferingType The offering type of the WayToWatch. */
enum class OfferingType {
    FREE,
    SUBSCRIBE,
    BUY,
    RENT
};

/* EntityInfoEntityType The type of the entity, e.g. `program` or `music`. */
enum class EntityInfoEntityType {
    PROGRAM,
    MUSIC
};

/* WayToWatchVideoQuality  */
enum class WayToWatchVideoQuality {
    SD,
    HD,
    UHD
};

/* ContentRatingScheme The rating scheme. */
enum class ContentRatingScheme {
    CA_MOVIE,
    CA_TV,
    CA_MOVIE_FR,
    CA_TV_FR,
    US_MOVIE,
    US_TV
};


// Types
struct ContentIdentifiers {
    std::optional<std::string> assetId;
    std::optional<std::string> entityId;
    std::optional<std::string> seasonId;
    std::optional<std::string> seriesId;
    std::optional<std::string> appContentData;
};

struct WayToWatch {
    ContentIdentifiers identifiers;
    std::optional<std::string> expires;
    std::optional<bool> entitled;
    std::optional<std::string> entitledExpires;
    std::optional<OfferingType> offeringType;
    std::optional<bool> hasAds;
    std::optional<float> price;
    std::optional<std::vector<WayToWatchVideoQuality>> videoQuality;
    std::vector<Types::AudioProfile> audioProfile;
    std::optional<std::vector<std::string>> audioLanguages;
    std::optional<std::vector<std::string>> closedCaptions;
    std::optional<std::vector<std::string>> subtitles;
    std::optional<std::vector<std::string>> audioDescriptions;
};

struct ContentRating {
    ContentRatingScheme scheme;
    std::string rating;
    std::optional<std::vector<std::string>> advisories;
};

struct Entitlement {
    std::string entitlementId;
    std::optional<std::string> startTime;
    std::optional<std::string> endTime;
};

struct EntityInfo {
    ContentIdentifiers identifiers;
    std::string title;
    EntityInfoEntityType entityType;
    std::optional<ProgramType> programType;
    std::optional<MusicType> musicType;
    std::optional<std::string> synopsis;
    std::optional<float> seasonNumber;
    std::optional<float> seasonCount;
    std::optional<float> episodeNumber;
    std::optional<float> episodeCount;
    std::optional<std::string> releaseDate;
    std::optional<std::vector<ContentRating>> contentRatings;
    std::optional<std::vector<WayToWatch>> waysToWatch;
};


} //namespace Entertainment
}
