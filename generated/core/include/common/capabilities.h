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

namespace Firebolt {
namespace Capabilities {


// Enums
/* Role Role provides access level for the app for a given capability. */
enum class Role {
    USE,
    MANAGE,
    PROVIDE
};

/* DenyReason Reasons why a Capability might not be invokable */
enum class DenyReason {
    UNPERMITTED,
    UNSUPPORTED,
    DISABLED,
    UNAVAILABLE,
    GRANT_DENIED,
    UNGRANTED
};


// Types
struct Permission {
    std::optional<Role> role;
    std::string capability;
};

struct CapPermissionStatus {
    std::optional<bool> permitted;
    std::optional<bool> granted;
};

struct CapabilityInfo {
    std::optional<std::string> capability;
    bool supported;
    bool available;
    CapPermissionStatus use;
    CapPermissionStatus manage;
    CapPermissionStatus provide;
    std::optional<std::vector<DenyReason>> details;
};


} //namespace Capabilities
}
