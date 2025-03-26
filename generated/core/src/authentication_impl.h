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
#include "IModule.h"

#include "authentication.h"


namespace Firebolt {
namespace Authentication {


    using JsonData_TokenType = WPEFramework::Core::JSON::EnumType<TokenType>;


    // Types
    using JsonData_Options = WPEFramework::Core::JSON::VariantContainer;

    class JsonData_Token: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_Token() override = default;
  
    public:
        JsonData_Token()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("value"), &Value);
            Add(_T("expires"), &Expires);
            Add(_T("type"), &Type);
        }

        JsonData_Token(const JsonData_Token& other)
        {
            Add(_T("value"), &Value);
            Value = other.Value;
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("type"), &Type);
            Type = other.Type;
        }

        JsonData_Token& operator=(const JsonData_Token& other)
        {
            Add(_T("value"), &Value);
            Value = other.Value;
            Add(_T("expires"), &Expires);
            Expires = other.Expires;
            Add(_T("type"), &Type);
            Type = other.Type;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Value;
        FireboltSDK::JSON::String Expires;
        FireboltSDK::JSON::String Type;
    };

    class AuthenticationImpl : public IAuthentication, public IModule {

    public:
        AuthenticationImpl() = default;
        AuthenticationImpl(const AuthenticationImpl&) = delete;
        AuthenticationImpl& operator=(const AuthenticationImpl&) = delete;

        ~AuthenticationImpl() override = default;

        // Methods & Events
        /*
         device
         Get a device token scoped to the current app.
         */
        std::string device( Firebolt::Error *err = nullptr ) const override;

        /*
         root
         Get a root device token.
         */
        std::string root( Firebolt::Error *err = nullptr ) const override;

        /*
         session
         Get a destributor session token.
         */
        std::string session( Firebolt::Error *err = nullptr ) const override;

        /*
         token
         Get a specific `type` of authentication token
         */
        Token token( const TokenType& type, const std::optional<Options>& options, Firebolt::Error *err = nullptr ) override;

    };

}//namespace Authentication
}
