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

#include "authentication_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Authentication {

    // Methods
    /* device - Get a device token scoped to the current app. */
    std::string AuthenticationImpl::device( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::string token;

        JsonObject jsonParameters;

        FireboltSDK::JSON::String jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("authentication.device", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Authentication.device is successfully invoked");
            token = jsonResult.Value().c_str();
        }

        if (err != nullptr) {
            *err = status;
        }

        return token;
    }

    /* root - Get a root device token. */
    std::string AuthenticationImpl::root( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::string token;

        JsonObject jsonParameters;

        FireboltSDK::JSON::String jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("authentication.root", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Authentication.root is successfully invoked");
            token = jsonResult.Value().c_str();
        }

        if (err != nullptr) {
            *err = status;
        }

        return token;
    }

    /* session - Get a destributor session token. */
    std::string AuthenticationImpl::session( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::string token;

        JsonObject jsonParameters;

        FireboltSDK::JSON::String jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("authentication.session", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Authentication.session is successfully invoked");
            token = jsonResult.Value().c_str();
        }

        if (err != nullptr) {
            *err = status;
        }

        return token;
    }

    /* token - Get a specific `type` of authentication token */
    Token AuthenticationImpl::token( const TokenType& type, const std::optional<Options>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        Token token;

        JsonObject jsonParameters;
        JsonData_TokenType jsonType = type;
            WPEFramework::Core::JSON::Variant typeVariant(jsonType.Data());
            jsonParameters.Set(_T("type"), typeVariant);
            if (options.has_value()) {
                WPEFramework::Core::JSON::Variant optionsVariant(options.value());
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        Firebolt::Authentication::JsonData_Token jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("authentication.token", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Authentication.token is successfully invoked");
            Token tokenResult;
                tokenResult.value = jsonResult.Value.Value();
                if (jsonResult.Expires.IsSet()) {
                    tokenResult.expires = jsonResult.Expires.Value();
                }
                if (jsonResult.Type.IsSet()) {
                    tokenResult.type = jsonResult.Type.Value();
                }
                token = tokenResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return token;
    }


    // Events

}//namespace Authentication
}


namespace WPEFramework {

    /* TokenType  */
    ENUM_CONVERSION_BEGIN(Firebolt::Authentication::TokenType)
        { Firebolt::Authentication::TokenType::PLATFORM, _T("platform") },
        { Firebolt::Authentication::TokenType::DEVICE, _T("device") },
        { Firebolt::Authentication::TokenType::DISTRIBUTOR, _T("distributor") },
    ENUM_CONVERSION_END(Firebolt::Authentication::TokenType)

}
