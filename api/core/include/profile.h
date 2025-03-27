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
#include "common/types.h"


namespace Firebolt {
namespace Profile {



struct IProfile {

    virtual ~IProfile() = default;

    // Methods & Events
    /*
     approveContentRating
     Verifies that the current profile should have access to mature/adult content.
     
     */
    virtual bool approveContentRating( Firebolt::Error *err = nullptr ) const = 0;
    /*
     approvePurchase
     Verifies that the current profile should have access to making purchases.
     
     */
    virtual bool approvePurchase( Firebolt::Error *err = nullptr ) const = 0;
    /*
     flags
     Get a map of profile flags for the current session.
     
     */
    virtual Types::FlatMap flags( Firebolt::Error *err = nullptr ) const = 0;
};

} //namespace Profile
}
