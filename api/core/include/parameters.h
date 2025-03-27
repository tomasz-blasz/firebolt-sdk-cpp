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
#include "common/intents.h"
#include "common/entity.h"
#include "common/entertainment.h"
#include "common/secondscreen.h"
#include "common/types.h"


namespace Firebolt {
namespace Parameters {


// Types
struct AppInitializationDiscovery {
    std::optional<std::string> navigateTo;
};

struct AppInitializationSecondScreen {
    std::optional<SecondScreen::SecondScreenEvent> launchRequest;
};

struct AppInitialization {
    std::optional<std::string> us_privacy;
    std::optional<int32_t> lmt;
    std::optional<AppInitializationDiscovery> discovery;
    std::optional<AppInitializationSecondScreen> secondScreen;
};


struct IParameters {

    virtual ~IParameters() = default;

    // Methods & Events
    /*
     initialization
     Returns any initialization parameters for the app, e.g. initialial `NavigationIntent`.
     
     */
    virtual AppInitialization initialization( Firebolt::Error *err = nullptr ) const = 0;
};

} //namespace Parameters
}
