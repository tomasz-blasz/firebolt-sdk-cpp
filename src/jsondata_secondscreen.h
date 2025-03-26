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
#include "common/secondscreen.h"

namespace Firebolt {
namespace SecondScreen {

    // Types
    using JsonData_SecondScreenEventType = WPEFramework::Core::JSON::EnumType<SecondScreenEventType>;

    class JsonData_SecondScreenEvent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_SecondScreenEvent() override = default;
  
    public:
        JsonData_SecondScreenEvent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("type"), &Type);
            Add(_T("version"), &Version);
            Add(_T("data"), &Data);
        }

        JsonData_SecondScreenEvent(const JsonData_SecondScreenEvent& other)
        {
            Add(_T("type"), &Type);
            Type = other.Type;
            Add(_T("version"), &Version);
            Version = other.Version;
            Add(_T("data"), &Data);
            Data = other.Data;
        }

        JsonData_SecondScreenEvent& operator=(const JsonData_SecondScreenEvent& other)
        {
            Add(_T("type"), &Type);
            Type = other.Type;
            Add(_T("version"), &Version);
            Version = other.Version;
            Add(_T("data"), &Data);
            Data = other.Data;
            return (*this);
        }

    public:
        Firebolt::SecondScreen::JsonData_SecondScreenEventType Type;
        FireboltSDK::JSON::String Version;
        FireboltSDK::JSON::String Data;
    };

}
}
