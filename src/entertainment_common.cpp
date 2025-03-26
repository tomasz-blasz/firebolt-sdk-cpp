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

#include "FireboltSDK.h"
#include "jsondata_types.h"
#include "jsondata_entertainment.h"


namespace WPEFramework {

    /* ProgramType In the case of a program `entityType`, specifies the program type. */
    ENUM_CONVERSION_BEGIN(Firebolt::Entertainment::ProgramType)
        { Firebolt::Entertainment::ProgramType::MOVIE, _T("movie") },
        { Firebolt::Entertainment::ProgramType::EPISODE, _T("episode") },
        { Firebolt::Entertainment::ProgramType::SEASON, _T("season") },
        { Firebolt::Entertainment::ProgramType::SERIES, _T("series") },
        { Firebolt::Entertainment::ProgramType::OTHER, _T("other") },
        { Firebolt::Entertainment::ProgramType::PREVIEW, _T("preview") },
        { Firebolt::Entertainment::ProgramType::EXTRA, _T("extra") },
        { Firebolt::Entertainment::ProgramType::CONCERT, _T("concert") },
        { Firebolt::Entertainment::ProgramType::SPORTING_EVENT, _T("sportingEvent") },
        { Firebolt::Entertainment::ProgramType::ADVERTISEMENT, _T("advertisement") },
        { Firebolt::Entertainment::ProgramType::MUSIC_VIDEO, _T("musicVideo") },
        { Firebolt::Entertainment::ProgramType::MINISODE, _T("minisode") },
    ENUM_CONVERSION_END(Firebolt::Entertainment::ProgramType)

    /* MusicType In the case of a music `entityType`, specifies the type of music entity. */
    ENUM_CONVERSION_BEGIN(Firebolt::Entertainment::MusicType)
        { Firebolt::Entertainment::MusicType::SONG, _T("song") },
        { Firebolt::Entertainment::MusicType::ALBUM, _T("album") },
    ENUM_CONVERSION_END(Firebolt::Entertainment::MusicType)

    /* OfferingType The offering type of the WayToWatch. */
    ENUM_CONVERSION_BEGIN(Firebolt::Entertainment::OfferingType)
        { Firebolt::Entertainment::OfferingType::FREE, _T("free") },
        { Firebolt::Entertainment::OfferingType::SUBSCRIBE, _T("subscribe") },
        { Firebolt::Entertainment::OfferingType::BUY, _T("buy") },
        { Firebolt::Entertainment::OfferingType::RENT, _T("rent") },
    ENUM_CONVERSION_END(Firebolt::Entertainment::OfferingType)

    /* EntityInfoEntityType The type of the entity, e.g. `program` or `music`. */
    ENUM_CONVERSION_BEGIN(Firebolt::Entertainment::EntityInfoEntityType)
        { Firebolt::Entertainment::EntityInfoEntityType::PROGRAM, _T("program") },
        { Firebolt::Entertainment::EntityInfoEntityType::MUSIC, _T("music") },
    ENUM_CONVERSION_END(Firebolt::Entertainment::EntityInfoEntityType)

    /* WayToWatchVideoQuality  */
    ENUM_CONVERSION_BEGIN(Firebolt::Entertainment::WayToWatchVideoQuality)
        { Firebolt::Entertainment::WayToWatchVideoQuality::SD, _T("SD") },
        { Firebolt::Entertainment::WayToWatchVideoQuality::HD, _T("HD") },
        { Firebolt::Entertainment::WayToWatchVideoQuality::UHD, _T("UHD") },
    ENUM_CONVERSION_END(Firebolt::Entertainment::WayToWatchVideoQuality)

    /* ContentRatingScheme The rating scheme. */
    ENUM_CONVERSION_BEGIN(Firebolt::Entertainment::ContentRatingScheme)
        { Firebolt::Entertainment::ContentRatingScheme::CA_MOVIE, _T("CA-Movie") },
        { Firebolt::Entertainment::ContentRatingScheme::CA_TV, _T("CA-TV") },
        { Firebolt::Entertainment::ContentRatingScheme::CA_MOVIE_FR, _T("CA-Movie-Fr") },
        { Firebolt::Entertainment::ContentRatingScheme::CA_TV_FR, _T("CA-TV-Fr") },
        { Firebolt::Entertainment::ContentRatingScheme::US_MOVIE, _T("US-Movie") },
        { Firebolt::Entertainment::ContentRatingScheme::US_TV, _T("US-TV") },
    ENUM_CONVERSION_END(Firebolt::Entertainment::ContentRatingScheme)

}