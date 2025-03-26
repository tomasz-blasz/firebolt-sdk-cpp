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
namespace Authentication {


// Enums
/* TokenType  */
enum class TokenType {
    PLATFORM,
    DEVICE,
    DISTRIBUTOR
};


// Types
/* Options */
using Options = std::string;

struct Token {
    std::string value;
    std::optional<std::string> expires;
    std::optional<std::string> type;
};


struct IAuthentication {

    virtual ~IAuthentication() = default;

    // Methods & Events
    /*
     device
     Get a device token scoped to the current app.
     
     */
    virtual std::string device( Firebolt::Error *err = nullptr ) const = 0;
    /*
     root
     Get a root device token.
     
     */
    virtual std::string root( Firebolt::Error *err = nullptr ) const = 0;
    /*
     session
     Get a destributor session token.
     
     */
    virtual std::string session( Firebolt::Error *err = nullptr ) const = 0;
    /*
     token
     Get a specific `type` of authentication token
      * @deprecated since version 0.9.0
     */
    virtual Token token( const TokenType& type, const std::optional<Options>& options, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace Authentication
}
