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
#include "jsondata_advertising.h"


namespace WPEFramework {

    /* SkipRestriction The advertisement skip restriction.

Applies to fast-forward/rewind (e.g. trick mode), seeking over an entire opportunity (e.g. jump), seeking out of what's currently playing, and "Skip this ad..." features. Seeking over multiple ad opportunities only requires playback of the _last_ opportunity, not all opportunities, preceding the seek destination.

| Value        | Description                                                                    |
|--------------|--------------------------------------------------------------------------------|
| none         |No fast-forward, jump, or skip restrictions                                    |
| adsUnwatched | Restrict fast-forward, jump, and skip for unwatched ad opportunities only.     |
| adsAll       | Restrict fast-forward, jump, and skip for all ad opportunities                 |
| all          | Restrict fast-forward, jump, and skip for all ad opportunities and all content |

Namespace: `xrn:advertising:policy:skipRestriction:`

 */
    ENUM_CONVERSION_BEGIN(Firebolt::Advertising::SkipRestriction)
        { Firebolt::Advertising::SkipRestriction::NONE, _T("none") },
        { Firebolt::Advertising::SkipRestriction::ADS_UNWATCHED, _T("adsUnwatched") },
        { Firebolt::Advertising::SkipRestriction::ADS_ALL, _T("adsAll") },
        { Firebolt::Advertising::SkipRestriction::ALL, _T("all") },
    ENUM_CONVERSION_END(Firebolt::Advertising::SkipRestriction)

}