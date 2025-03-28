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

#include "keyboard_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Keyboard {

    // Will add PROVIDER_CLASSES templates in another PR
    // Static for now

    static std::string KeyboardEmailSessionInnerCallback( void* provider, void* jsonRequest )
    {
        WPEFramework::Core::ProxyType<JsonData_KeyboardEmailProviderRequest>& proxyRequest = *(reinterpret_cast<WPEFramework::Core::ProxyType<JsonData_KeyboardEmailProviderRequest>*>(jsonRequest));

        ASSERT(proxyRequest.IsValid() == true);

        if (!proxyRequest.IsValid()) {
          return R"({"error": { "code": )" + std::to_string(static_cast<int32_t>(Firebolt::Error::InvalidParams)) + R"(, "message": "Invalid Parameters"}, "result": ""})";
        }
        KeyboardEmailParameters parameters;

        parameters.type = (*proxyRequest).Parameters.Type;
        parameters.message = (*proxyRequest).Parameters.Message;

        proxyRequest.Release();

        IKeyboardProvider& keyboardProvider = *(reinterpret_cast<IKeyboardProvider*>(provider));
        KeyboardResult result = keyboardProvider.email(parameters);
        return "{\"result\":\"" + result.message + "\"}";
    }


    static std::string KeyboardPasswordSessionInnerCallback( void* provider, void* jsonRequest )
    {
        WPEFramework::Core::ProxyType<JsonData_KeyboardProviderRequest>& proxyRequest = *(reinterpret_cast<WPEFramework::Core::ProxyType<JsonData_KeyboardProviderRequest>*>(jsonRequest));

        ASSERT(proxyRequest.IsValid() == true);

        if (!proxyRequest.IsValid()) {
            return R"({"error": { "code": )" + std::to_string(static_cast<int32_t>(Firebolt::Error::InvalidParams)) + R"(, "message": "Invalid Parameters"}, "result": ""})";
        }
        KeyboardParameters parameters;

        parameters.message = (*proxyRequest).Parameters.Message;

        proxyRequest.Release();

        IKeyboardProvider& keyboardProvider = *(reinterpret_cast<IKeyboardProvider*>(provider));
        KeyboardResult result = keyboardProvider.password(parameters);
        return "{\"result\":\"" + result.message + "\"}";
    }


    static std::string KeyboardStandardSessionInnerCallback( void* provider, void* jsonRequest )
    {
        WPEFramework::Core::ProxyType<JsonData_KeyboardProviderRequest>& proxyRequest = *(reinterpret_cast<WPEFramework::Core::ProxyType<JsonData_KeyboardProviderRequest>*>(jsonRequest));

        ASSERT(proxyRequest.IsValid() == true);

        if (!proxyRequest.IsValid()) {
            return R"({"error": { "code": )" + std::to_string(static_cast<int32_t>(Firebolt::Error::InvalidParams)) + R"(, "message": "Invalid Parameters"}, "result": ""})";
        }
        KeyboardParameters parameters;

        parameters.message = (*proxyRequest).Parameters.Message;

        proxyRequest.Release();

        IKeyboardProvider& keyboardProvider = *(reinterpret_cast<IKeyboardProvider*>(provider));
        KeyboardResult result = keyboardProvider.standard(parameters);
        return "{\"result\":\"" + result.message + "\"}";
    }

    // Custom provider method
    void KeyboardImpl::provide( IKeyboardProvider& provider )
    {
        string eventName;
        Firebolt::Error status = Firebolt::Error::None;
        JsonObject jsonParameters;

        eventName = _T("keyboard.onRequestStandard");
        status = FireboltSDK::Gateway::Instance().RegisterProviderInterface<JsonData_KeyboardProviderRequest>(eventName, jsonParameters, KeyboardStandardSessionInnerCallback, reinterpret_cast<void*>(&provider));
        if (status != Firebolt::Error::None) {
            FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in %s subscribe = %d", eventName.c_str(), status);
        }

        eventName = _T("keyboard.onRequestPassword");
        status = FireboltSDK::Gateway::Instance().RegisterProviderInterface<JsonData_KeyboardProviderRequest>(eventName, jsonParameters, KeyboardPasswordSessionInnerCallback, reinterpret_cast<void*>(&provider));
        if (status != Firebolt::Error::None) {
            FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in %s subscribe = %d", eventName.c_str(), status);
        }

        eventName = _T("keyboard.onRequestEmail");
        status = FireboltSDK::Gateway::Instance().RegisterProviderInterface<JsonData_KeyboardProviderRequest>(eventName, jsonParameters, KeyboardEmailSessionInnerCallback, reinterpret_cast<void*>(&provider));
        if (status != Firebolt::Error::None) {
            FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in %s subscribe = %d", eventName.c_str(), status);
        }
    }

    // Events

}//namespace Keyboard
}


namespace WPEFramework {

    /* EmailUsage  */
    ENUM_CONVERSION_BEGIN(Firebolt::Keyboard::EmailUsage)
        { Firebolt::Keyboard::EmailUsage::SIGN_IN, _T("signIn") },
        { Firebolt::Keyboard::EmailUsage::SIGN_UP, _T("signUp") },
    ENUM_CONVERSION_END(Firebolt::Keyboard::EmailUsage)

}

