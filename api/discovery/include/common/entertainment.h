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


} //namespace Entertainment
}
