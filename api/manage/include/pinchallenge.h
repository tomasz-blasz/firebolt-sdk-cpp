/* Copyright 2023 Comcast Cable Communications Management, LLC
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
namespace PinChallenge {

/* ResultReason The reason for the result of challenging the user */
enum class ResultReason {
    NO_PIN_REQUIRED,
    NO_PIN_REQUIRED_WINDOW,
    EXCEEDED_PIN_FAILURES,
    CORRECT_PIN,
    CANCELLED
};

/* PinSpace The pin space that this challenge is for */
enum class PinSpace {
    PURCHASE,
    CONTENT
};


 // Types
struct ChallengeRequestor {
    std::string id;
    std::string name;
};
 
struct PinChallengeResult {
    bool granted;
    ResultReason reason;
};
 
struct PinChallengeParameters {
    ChallengeRequestor requestor;
    PinSpace pinSpace;
    std::optional<std::string> capability;
};

struct PinChallengeProviderRequest {
    PinChallengeParameters parameters;
};

struct PinChallengeError {
    int32_t code;
    std::string message;
    std::optional<std::string> data;
};

struct IPinChallengeProvider {
    virtual ~IPinChallengeProvider() = default;
    virtual PinChallengeResult challenge( const PinChallengeParameters& parameters) = 0;
};

struct IPinChallenge {

    virtual ~IPinChallenge() = default;

    // Methods & Events
    virtual void provide( IPinChallengeProvider& provider ) = 0;

};
} //namespace PinChallenge
}


