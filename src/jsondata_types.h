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

#include "FireboltSDK.h"
#include "common/types.h"

namespace Firebolt {
namespace Types {

    // Types
    using JsonData_AudioProfile = WPEFramework::Core::JSON::EnumType<AudioProfile>;

    class JsonData_SemanticVersion: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_SemanticVersion() override = default;
  
    public:
        JsonData_SemanticVersion()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("major"), &Major);
            Add(_T("minor"), &Minor);
            Add(_T("patch"), &Patch);
            Add(_T("readable"), &Readable);
        }

        JsonData_SemanticVersion(const JsonData_SemanticVersion& other)
        {
            Add(_T("major"), &Major);
            Major = other.Major;
            Add(_T("minor"), &Minor);
            Minor = other.Minor;
            Add(_T("patch"), &Patch);
            Patch = other.Patch;
            Add(_T("readable"), &Readable);
            Readable = other.Readable;
        }

        JsonData_SemanticVersion& operator=(const JsonData_SemanticVersion& other)
        {
            Add(_T("major"), &Major);
            Major = other.Major;
            Add(_T("minor"), &Minor);
            Minor = other.Minor;
            Add(_T("patch"), &Patch);
            Patch = other.Patch;
            Add(_T("readable"), &Readable);
            Readable = other.Readable;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::DecSInt32 Major;
        WPEFramework::Core::JSON::DecSInt32 Minor;
        WPEFramework::Core::JSON::DecSInt32 Patch;
        FireboltSDK::JSON::String Readable;
    };

    using JsonData_BooleanMap = WPEFramework::Core::JSON::VariantContainer;
    using JsonData_FlatMap = WPEFramework::Core::JSON::VariantContainer;
    /* anyOf schema shape is not supported right now */
}
}
