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
#include "common/localization.h"

namespace Firebolt {
namespace Accessibility {


// Enums
/* FontFamily  */
enum class FontFamily {
    MONOSPACED_SERIF,
    PROPORTIONAL_SERIF,
    MONOSPACED_SANSERIF,
    PROPORTIONAL_SANSERIF,
    SMALLCAPS,
    CURSIVE,
    CASUAL
};

/* FontEdge  */
enum class FontEdge {
    NONE,
    RAISED,
    DEPRESSED,
    UNIFORM,
    DROP_SHADOW_LEFT,
    DROP_SHADOW_RIGHT
};


// Types
struct ClosedCaptionsStyles {
    std::optional<FontFamily> fontFamily;
    std::optional<float> fontSize;
    std::optional<std::string> fontColor;
    std::optional<FontEdge> fontEdge;
    std::optional<std::string> fontEdgeColor;
    std::optional<float> fontOpacity;
    std::optional<std::string> backgroundColor;
    std::optional<float> backgroundOpacity;
    std::optional<std::string> textAlign;
    std::optional<std::string> textAlignVertical;
    std::optional<std::string> windowColor;
    std::optional<float> windowOpacity;
};

struct ClosedCaptionsSettings {
    bool enabled;
    std::optional<ClosedCaptionsStyles> styles;
    std::optional<std::vector<std::string>> preferredLanguages;
};

struct VoiceGuidanceSettings {
    bool enabled;
    bool navigationHints;
    float rate;
    std::optional<float> speed;
};


} //namespace Accessibility
}
