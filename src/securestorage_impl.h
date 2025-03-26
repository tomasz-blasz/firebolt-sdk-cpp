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

#include "securestorage.h"


namespace Firebolt {
namespace SecureStorage {


    using JsonData_StorageScope = WPEFramework::Core::JSON::EnumType<StorageScope>;


    // Types
    class JsonData_StorageOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_StorageOptions() override = default;
  
    public:
        JsonData_StorageOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("ttl"), &Ttl);
        }

        JsonData_StorageOptions(const JsonData_StorageOptions& other)
        {
            Add(_T("ttl"), &Ttl);
            Ttl = other.Ttl;
        }

        JsonData_StorageOptions& operator=(const JsonData_StorageOptions& other)
        {
            Add(_T("ttl"), &Ttl);
            Ttl = other.Ttl;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::Float Ttl;
    };

    class SecureStorageImpl : public ISecureStorage, public IModule {

    public:
        SecureStorageImpl() = default;
        SecureStorageImpl(const SecureStorageImpl&) = delete;
        SecureStorageImpl& operator=(const SecureStorageImpl&) = delete;

        ~SecureStorageImpl() override = default;

        // Methods & Events
        /*
         clear
         Clears all the secure data values
         */
        void clear( const StorageScope& scope, Firebolt::Error *err = nullptr ) override;

        /*
         get
         Get stored value by key
         */
        std::string get( const StorageScope& scope, const std::string& key, Firebolt::Error *err = nullptr ) override;

        /*
         remove
         Remove a secure data value
         */
        void remove( const StorageScope& scope, const std::string& key, Firebolt::Error *err = nullptr ) override;

        /*
         set
         Set or update a secure data value
         */
        void set( const StorageScope& scope, const std::string& key, const std::string& value, const std::optional<StorageOptions>& options, Firebolt::Error *err = nullptr ) override;

    };

}//namespace SecureStorage
}
