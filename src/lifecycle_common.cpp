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
#include "jsondata_lifecycle.h"


namespace WPEFramework {

    /* LifecycleState The application lifecycle state */
    ENUM_CONVERSION_BEGIN(Firebolt::Lifecycle::LifecycleState)
        { Firebolt::Lifecycle::LifecycleState::INITIALIZING, _T("initializing") },
        { Firebolt::Lifecycle::LifecycleState::INACTIVE, _T("inactive") },
        { Firebolt::Lifecycle::LifecycleState::FOREGROUND, _T("foreground") },
        { Firebolt::Lifecycle::LifecycleState::BACKGROUND, _T("background") },
        { Firebolt::Lifecycle::LifecycleState::UNLOADING, _T("unloading") },
        { Firebolt::Lifecycle::LifecycleState::SUSPENDED, _T("suspended") },
    ENUM_CONVERSION_END(Firebolt::Lifecycle::LifecycleState)

    /* CloseReason The application close reason */
    ENUM_CONVERSION_BEGIN(Firebolt::Lifecycle::CloseReason)
        { Firebolt::Lifecycle::CloseReason::REMOTE_BUTTON, _T("remoteButton") },
        { Firebolt::Lifecycle::CloseReason::USER_EXIT, _T("userExit") },
        { Firebolt::Lifecycle::CloseReason::DONE, _T("done") },
        { Firebolt::Lifecycle::CloseReason::ERROR, _T("error") },
    ENUM_CONVERSION_END(Firebolt::Lifecycle::CloseReason)

}