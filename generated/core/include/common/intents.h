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
#include "common/entity.h"
#include "common/entertainment.h"

namespace Firebolt {
namespace Intents {


// Types
struct IntentContext {
    std::string source;
};



struct Intent {
    std::string action;
    IntentContext context;
};

struct HomeIntent {
    std::string action;
    IntentContext context;
};

struct EntityIntent {
    std::string action;
    std::string data;
    IntentContext context;
};

struct TuneIntentDataOptions {
    std::optional<std::string> assetId;
    std::optional<bool> restartCurrentProgram;
    std::optional<std::string> time;
};

struct PlaybackIntent {
    std::string action;
    std::string data;
    IntentContext context;
};

struct SearchIntentData {
    std::string query;
};

struct SectionIntentData {
    std::string sectionName;
};

struct PlayEntityIntentDataOptions {
    std::optional<std::string> playFirstId;
    std::optional<int32_t> playFirstTrack;
};

struct PlayQueryIntentDataOptions {
    std::optional<std::vector<Entertainment::ProgramType>> programTypes;
    std::optional<std::vector<Entertainment::MusicType>> musicTypes;
};

struct LaunchIntent {
    std::string action;
    IntentContext context;
};

struct TuneIntentData {
    Entity::ChannelEntity entity;
    std::optional<TuneIntentDataOptions> options;
};

struct SearchIntent {
    std::string action;
    std::optional<SearchIntentData> data;
    IntentContext context;
};

struct SectionIntent {
    std::string action;
    SectionIntentData data;
    IntentContext context;
};

struct PlayEntityIntentData {
    std::string entity;
    std::optional<PlayEntityIntentDataOptions> options;
};

struct PlayQueryIntentData {
    std::string query;
    std::optional<PlayQueryIntentDataOptions> options;
};

struct TuneIntent {
    std::string action;
    TuneIntentData data;
    IntentContext context;
};

struct PlayEntityIntent {
    std::string action;
    PlayEntityIntentData data;
    IntentContext context;
};

struct PlayQueryIntent {
    std::string action;
    PlayQueryIntentData data;
    IntentContext context;
};

/* anyOf schema shape is not supported right now */


} //namespace Intents
}
