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
namespace Keyboard {


// Enums
/* EmailUsage  */
enum class EmailUsage {
    SIGN_IN,
    SIGN_UP
};


struct IKeyboardAsyncResponse {

    virtual ~IKeyboardAsyncResponse() = default;

    virtual void response(const std::string& result, Firebolt::Error *err) = 0;
};

struct IKeyboard {

    virtual ~IKeyboard() = default;

    // Methods & Events
    /*
     email
     Prompt the user for their email address with a simplified list of choices.
     */
    virtual void requestEmail(const EmailUsage& type, const std::optional<std::string>& message, IKeyboardAsyncResponse& response, Firebolt::Error *err = nullptr ) = 0;
    virtual void abortEmail(IKeyboardAsyncResponse& response, Firebolt::Error *err = nullptr) = 0;

    /*
     password
     Show the password entry keyboard, with typing obfuscated from visibility
     */
    virtual void requestPassword(const std::optional<std::string>& message, IKeyboardAsyncResponse& response, Firebolt::Error *err = nullptr ) = 0;
    virtual void abortPassword(IKeyboardAsyncResponse& response, Firebolt::Error *err = nullptr) = 0;

    /*
     standard
     Show the standard platform keyboard, and return the submitted value
     */
    virtual void requestStandard(const std::string& message, IKeyboardAsyncResponse& response, Firebolt::Error *err = nullptr ) = 0;
    virtual void abortStandard(IKeyboardAsyncResponse& response, Firebolt::Error *err = nullptr) = 0;

};

} //namespace Keyboard
}
