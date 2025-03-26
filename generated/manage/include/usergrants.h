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
#include "common/capabilities.h"


namespace Firebolt {
namespace UserGrants {


// Enums
/* GrantState The state the grant is in */
enum class GrantState {
    GRANTED,
    DENIED
};

/* GrantInfoLifespan  */
enum class GrantInfoLifespan {
    ONCE,
    FOREVER,
    APP_ACTIVE,
    POWER_ACTIVE,
    SECONDS
};


// Types
struct RequestOptions {
    std::optional<bool> force;
};

struct AppInfo {
    std::string id;
    std::optional<std::string> title;
};

struct GrantInfo {
    std::optional<AppInfo> app;
    GrantState state;
    std::string capability;
    Capabilities::Role role;
    GrantInfoLifespan lifespan;
    std::optional<std::string> expires;
};

struct GrantModificationOptions {
    std::optional<std::string> appId;
};


struct IUserGrants {

    virtual ~IUserGrants() = default;

    // Methods & Events
    /*
     app
     Get all granted and denied user grants for the given app
     
     */
    virtual std::vector<GrantInfo> app( const std::string& appId, Firebolt::Error *err = nullptr ) = 0;
    /*
     capability
     Get all granted and denied user grants for the given capability
     
     */
    virtual std::vector<GrantInfo> capability( const std::string& capability, Firebolt::Error *err = nullptr ) = 0;
    /*
     clear
     Clears the grant for a given capability, to a specific app if appropriate. Calling this results in a persisted Denied Grant that lasts for the duration of the Grant Policy lifespan. 
     
     */
    virtual void clear( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err = nullptr ) = 0;
    /*
     deny
     Denies a given capability, to a specific app if appropriate. Calling this results in a persisted Denied Grant that lasts for the duration of the Grant Policy lifespan. 
     
     */
    virtual void deny( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err = nullptr ) = 0;
    /*
     device
     Get all granted and denied user grants for the device
     
     */
    virtual std::vector<GrantInfo> device( Firebolt::Error *err = nullptr ) const = 0;
    /*
     grant
     Grants a given capability to a specific app, if appropriate. Calling this results in a persisted active grant that lasts for the duration of the grant policy lifespan. 
     
     */
    virtual void grant( const Capabilities::Role& role, const std::string& capability, const std::optional<GrantModificationOptions>& options, Firebolt::Error *err = nullptr ) = 0;
    /*
     request
     Requests Firebolt to carry out a set of user grants for a given application such that the user grant provider is notified or an existing user grant is reused.
     
     */
    virtual std::vector<GrantInfo> request( const std::string& appId, const std::vector<Capabilities::Permission>& permissions, const std::optional<RequestOptions>& options, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace UserGrants
}
