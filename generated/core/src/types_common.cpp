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


namespace WPEFramework {

    /* AudioProfile  */
    ENUM_CONVERSION_BEGIN(Firebolt::Types::AudioProfile)
        { Firebolt::Types::AudioProfile::STEREO, _T("stereo") },
        { Firebolt::Types::AudioProfile::DOLBY_DIGITAL_5_1, _T("dolbyDigital5.1") },
        { Firebolt::Types::AudioProfile::DOLBY_DIGITAL_7_1, _T("dolbyDigital7.1") },
        { Firebolt::Types::AudioProfile::DOLBY_DIGITAL_5_1_PLUS, _T("dolbyDigital5.1+") },
        { Firebolt::Types::AudioProfile::DOLBY_DIGITAL_7_1_PLUS, _T("dolbyDigital7.1+") },
        { Firebolt::Types::AudioProfile::DOLBY_ATMOS, _T("dolbyAtmos") },
    ENUM_CONVERSION_END(Firebolt::Types::AudioProfile)

}