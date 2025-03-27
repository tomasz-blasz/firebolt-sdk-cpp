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
#include "jsondata_entertainment.h"
#include "jsondata_entity.h"


namespace WPEFramework {

    /* ChannelEntityChannelType  */
    ENUM_CONVERSION_BEGIN(Firebolt::Entity::ChannelEntityChannelType)
        { Firebolt::Entity::ChannelEntityChannelType::STREAMING, _T("streaming") },
        { Firebolt::Entity::ChannelEntityChannelType::OVER_THE_AIR, _T("overTheAir") },
    ENUM_CONVERSION_END(Firebolt::Entity::ChannelEntityChannelType)

    /* AdditionalEntityProgramType  */
    ENUM_CONVERSION_BEGIN(Firebolt::Entity::AdditionalEntityProgramType)
        { Firebolt::Entity::AdditionalEntityProgramType::CONCERT, _T("concert") },
        { Firebolt::Entity::AdditionalEntityProgramType::SPORTING_EVENT, _T("sportingEvent") },
        { Firebolt::Entity::AdditionalEntityProgramType::PREVIEW, _T("preview") },
        { Firebolt::Entity::AdditionalEntityProgramType::OTHER, _T("other") },
        { Firebolt::Entity::AdditionalEntityProgramType::ADVERTISEMENT, _T("advertisement") },
        { Firebolt::Entity::AdditionalEntityProgramType::MUSIC_VIDEO, _T("musicVideo") },
        { Firebolt::Entity::AdditionalEntityProgramType::MINISODE, _T("minisode") },
        { Firebolt::Entity::AdditionalEntityProgramType::EXTRA, _T("extra") },
    ENUM_CONVERSION_END(Firebolt::Entity::AdditionalEntityProgramType)

}