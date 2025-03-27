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
#include "jsondata_capabilities.h"


namespace WPEFramework {

    /* Role Role provides access level for the app for a given capability. */
    ENUM_CONVERSION_BEGIN(Firebolt::Capabilities::Role)
        { Firebolt::Capabilities::Role::USE, _T("use") },
        { Firebolt::Capabilities::Role::MANAGE, _T("manage") },
        { Firebolt::Capabilities::Role::PROVIDE, _T("provide") },
    ENUM_CONVERSION_END(Firebolt::Capabilities::Role)

    /* DenyReason Reasons why a Capability might not be invokable */
    ENUM_CONVERSION_BEGIN(Firebolt::Capabilities::DenyReason)
        { Firebolt::Capabilities::DenyReason::UNPERMITTED, _T("unpermitted") },
        { Firebolt::Capabilities::DenyReason::UNSUPPORTED, _T("unsupported") },
        { Firebolt::Capabilities::DenyReason::DISABLED, _T("disabled") },
        { Firebolt::Capabilities::DenyReason::UNAVAILABLE, _T("unavailable") },
        { Firebolt::Capabilities::DenyReason::GRANT_DENIED, _T("grantDenied") },
        { Firebolt::Capabilities::DenyReason::UNGRANTED, _T("ungranted") },
    ENUM_CONVERSION_END(Firebolt::Capabilities::DenyReason)

}