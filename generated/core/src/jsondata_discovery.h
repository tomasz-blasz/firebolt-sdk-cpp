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
#include "jsondata_entertainment.h"
#include "common/discovery.h"

namespace Firebolt {
namespace Discovery {

    // Types
    class JsonData_PurchasedContentResult: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PurchasedContentResult() override = default;
  
    public:
        JsonData_PurchasedContentResult()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("expires"), &Expires);
            Add(_T("totalCount"), &TotalCount);
            Add(_T("entries"), &Entries);
        }

        JsonData_PurchasedContentResult(const JsonData_PurchasedContentResult& other)
        {
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("totalCount"), &TotalCount);
            TotalCount = other.TotalCount;
            Add(_T("entries"), &Entries);
            Entries = other.Entries;
        }

        JsonData_PurchasedContentResult& operator=(const JsonData_PurchasedContentResult& other)
        {
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("totalCount"), &TotalCount);
            TotalCount = other.TotalCount;
            Add(_T("entries"), &Entries);
            Entries = other.Entries;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Expires;
        WPEFramework::Core::JSON::DecSInt32 TotalCount;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_EntityInfo> Entries;
    };

    class JsonData_EntityInfoResult: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_EntityInfoResult() override = default;
  
    public:
        JsonData_EntityInfoResult()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("expires"), &Expires);
            Add(_T("entity"), &Entity);
            Add(_T("related"), &Related);
        }

        JsonData_EntityInfoResult(const JsonData_EntityInfoResult& other)
        {
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("entity"), &Entity);
            Entity = other.Entity;
            Add(_T("related"), &Related);
            Related = other.Related;
        }

        JsonData_EntityInfoResult& operator=(const JsonData_EntityInfoResult& other)
        {
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("entity"), &Entity);
            Entity = other.Entity;
            Add(_T("related"), &Related);
            Related = other.Related;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Expires;
        Firebolt::Entertainment::JsonData_EntityInfo Entity;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_EntityInfo> Related;
    };

}
}
