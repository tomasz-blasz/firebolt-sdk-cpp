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
namespace SecureStorage {


// Enums
/* StorageScope The scope of the data */
enum class StorageScope {
    DEVICE,
    ACCOUNT
};


// Types
struct StorageOptions {
    float ttl;
};


struct ISecureStorage {

    virtual ~ISecureStorage() = default;

    // Methods & Events
    /*
     clear
     Clears all the secure data values
     
     */
    virtual void clear( const StorageScope& scope, Firebolt::Error *err = nullptr ) = 0;
    /*
     get
     Get stored value by key
     
     */
    virtual std::string get( const StorageScope& scope, const std::string& key, Firebolt::Error *err = nullptr ) = 0;
    /*
     remove
     Remove a secure data value
     
     */
    virtual void remove( const StorageScope& scope, const std::string& key, Firebolt::Error *err = nullptr ) = 0;
    /*
     set
     Set or update a secure data value
     
     */
    virtual void set( const StorageScope& scope, const std::string& key, const std::string& value, const std::optional<StorageOptions>& options, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace SecureStorage
}
