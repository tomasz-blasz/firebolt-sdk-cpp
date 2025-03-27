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
#include "jsondata_discovery.h"


namespace WPEFramework {

    /* InterestType  */
    ENUM_CONVERSION_BEGIN(Firebolt::Discovery::InterestType)
        { Firebolt::Discovery::InterestType::INTEREST, _T("interest") },
        { Firebolt::Discovery::InterestType::DISINTEREST, _T("disinterest") },
    ENUM_CONVERSION_END(Firebolt::Discovery::InterestType)

    /* InterestReason  */
    ENUM_CONVERSION_BEGIN(Firebolt::Discovery::InterestReason)
        { Firebolt::Discovery::InterestReason::PLAYLIST, _T("playlist") },
        { Firebolt::Discovery::InterestReason::REACTION, _T("reaction") },
        { Firebolt::Discovery::InterestReason::RECORDING, _T("recording") },
    ENUM_CONVERSION_END(Firebolt::Discovery::InterestReason)

}