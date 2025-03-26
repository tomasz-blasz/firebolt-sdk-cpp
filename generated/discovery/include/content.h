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
#include "common/entity.h"
#include "common/discovery.h"
#include "common/entertainment.h"
#include "common/types.h"


namespace Firebolt {
namespace Content {


// Types
struct InterestResult {
    std::string appId;
    Entity::EntityDetails entity;
};

struct InterestEvent {
    std::string appId;
    Discovery::InterestType type;
    Discovery::InterestReason reason;
    Entity::EntityDetails entity;
};


struct IContent {

    virtual ~IContent() = default;

    // Methods & Events
    /* onUserInterest - Provide information about the entity currently displayed or selected on the screen. */
    struct IOnUserInterestNotification {
        virtual void onUserInterest( const InterestEvent& ) = 0;
    };
    // signature callback params: 
    // method result properties : 
    virtual void subscribe( IOnUserInterestNotification& notification, Firebolt::Error *err = nullptr ) = 0;
    virtual void unsubscribe( IOnUserInterestNotification& notification, Firebolt::Error *err = nullptr ) = 0;

    /*
     requestUserInterest
     Provide information about the entity currently displayed or selected on the screen.
     
     */
    virtual InterestResult requestUserInterest( const Discovery::InterestType& type, const Discovery::InterestReason& reason, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace Content
}
