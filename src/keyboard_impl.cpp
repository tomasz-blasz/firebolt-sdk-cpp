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

    // Methods

    /* emailAsyncResponseInnerCallback */
    static void emailAsyncResponseInnerCallback(void* notification, void* jsonResponse, Firebolt::Error status)
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {

            std::string email;
            FireboltSDK::JSON::String jsonResult(proxyResponse->Value().c_str());
            email = jsonResult.Value().c_str();
            proxyResponse.Release();

            IKeyboardAsyncResponse& notifier = *(reinterpret_cast<IKeyboardAsyncResponse*>(notification));
            notifier.response(email, &status);
        }
    }

    /* email - Prompt the user for their email address with a simplified list of choices. */
    void KeyboardImpl::requestEmail(const EmailUsage& type, const std::optional<std::string>& message, IKeyboardAsyncResponse& response, Firebolt::Error *err)
    {
        JsonObject jsonParameters;
        JsonData_EmailUsage jsonType = type;
        WPEFramework::Core::JSON::Variant typeVariant(jsonType.Data());
        jsonParameters.Set(_T("type"), typeVariant);
        if (message.has_value()) {
            WPEFramework::Core::JSON::Variant messageVariant(message.value());
            jsonParameters.Set(_T("message"), messageVariant);
        }

        Firebolt::Error status = FireboltSDK::Async::Instance().Invoke<FireboltSDK::JSON::String>(_T("Keyboard.email"), jsonParameters, emailAsyncResponseInnerCallback, reinterpret_cast<void*>(&response));
        if (status == Firebolt::Error::None) {
                FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Keyboard.email is successfully invoked");
        } else {
            FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in getting Async::Invoke err = %d", status);
        }

        if (err != nullptr) {
            *err = status;
        }
        return;
    }
    void KeyboardImpl::abortEmail(IKeyboardAsyncResponse& response, Firebolt::Error *err)
    {
        Firebolt::Error status = FireboltSDK::Async::Instance().Abort(_T("Keyboard.email"), reinterpret_cast<void*>(&response));
	if (err != nullptr) {
            *err = status;
        }
    }


    /* passwordAsyncResponseInnerCallback */
    static void passwordAsyncResponseInnerCallback(void* notification, void* jsonResponse, Firebolt::Error status)
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {

            std::string value;
            FireboltSDK::JSON::String jsonResult(proxyResponse->Value().c_str());
            value = jsonResult.Value().c_str();
            proxyResponse.Release();

            IKeyboardAsyncResponse& notifier = *(reinterpret_cast<IKeyboardAsyncResponse*>(notification));
            notifier.response(value, &status);
        }
    }

    /* password - Show the password entry keyboard, with typing obfuscated from visibility */
    void KeyboardImpl::requestPassword(const std::optional<std::string>& message, IKeyboardAsyncResponse& response, Firebolt::Error *err)
    {
        JsonObject jsonParameters;
        if (message.has_value()) {
            WPEFramework::Core::JSON::Variant messageVariant(message.value());
            jsonParameters.Set(_T("message"), messageVariant);
        }

        Firebolt::Error status = FireboltSDK::Async::Instance().Invoke<FireboltSDK::JSON::String>(_T("Keyboard.password"), jsonParameters, passwordAsyncResponseInnerCallback, reinterpret_cast<void*>(&response));
        if (status == Firebolt::Error::None) {
                FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Keyboard.password is successfully invoked");
        } else {
            FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in getting Async::Invoke err = %d", status);
        }

        if (err != nullptr) {
            *err = status;
        }
        return;
    }
    void KeyboardImpl::abortPassword(IKeyboardAsyncResponse& response, Firebolt::Error *err)
    {
        Firebolt::Error status = FireboltSDK::Async::Instance().Abort(_T("Keyboard.password"), reinterpret_cast<void*>(&response));
	if (err != nullptr) {
            *err = status;
        }
    }


    /* standardAsyncResponseInnerCallback */
    static void standardAsyncResponseInnerCallback(void* notification, void* jsonResponse, Firebolt::Error status)
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {

            std::string value;
            FireboltSDK::JSON::String jsonResult(proxyResponse->Value().c_str());
            value = jsonResult.Value().c_str();
            proxyResponse.Release();

            IKeyboardAsyncResponse& notifier = *(reinterpret_cast<IKeyboardAsyncResponse*>(notification));
            notifier.response(value, &status);
        }
    }

    /* standard - Show the standard platform keyboard, and return the submitted value */
    void KeyboardImpl::requestStandard(const std::string& message, IKeyboardAsyncResponse& response, Firebolt::Error *err)
    {
        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant messageVariant(message);
        jsonParameters.Set(_T("message"), messageVariant);

        Firebolt::Error status = FireboltSDK::Async::Instance().Invoke<FireboltSDK::JSON::String>(_T("Keyboard.standard"), jsonParameters, standardAsyncResponseInnerCallback, reinterpret_cast<void*>(&response));
        if (status == Firebolt::Error::None) {
                FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Keyboard.standard is successfully invoked");
        } else {
            FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in getting Async::Invoke err = %d", status);
        }

        if (err != nullptr) {
            *err = status;
        }
        return;
    }
    void KeyboardImpl::abortStandard(IKeyboardAsyncResponse& response, Firebolt::Error *err)
    {
        Firebolt::Error status = FireboltSDK::Async::Instance().Abort(_T("Keyboard.standard"), reinterpret_cast<void*>(&response));
	if (err != nullptr) {
            *err = status;
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
