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

#include "account_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Account {

    // Methods
    /* id - Get the platform back-office account identifier */
    std::string AccountImpl::id( Firebolt::Error *err ) const
    {
        const string method = _T("account.id");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string id;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            id = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return id;
    }

    /* uid - Gets a unique id for the current app & account */
    std::string AccountImpl::uid( Firebolt::Error *err ) const
    {
        const string method = _T("account.uid");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string uniqueId;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            uniqueId = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return uniqueId;
    }


    // Events

}//namespace Account
}

