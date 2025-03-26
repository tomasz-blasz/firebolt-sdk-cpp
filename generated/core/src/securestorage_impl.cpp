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

#include "securestorage_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace SecureStorage {

    // Methods
    /* clear - Clears all the secure data values */
    void SecureStorageImpl::clear( const StorageScope& scope, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        JsonData_StorageScope jsonScope = scope;
            WPEFramework::Core::JSON::Variant scopeVariant(jsonScope.Data());
            jsonParameters.Set(_T("scope"), scopeVariant);
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("securestorage.clear", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "SecureStorage.clear is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* get - Get stored value by key */
    std::string SecureStorageImpl::get( const StorageScope& scope, const std::string& key, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        std::string value;

        JsonObject jsonParameters;
        JsonData_StorageScope jsonScope = scope;
            WPEFramework::Core::JSON::Variant scopeVariant(jsonScope.Data());
            jsonParameters.Set(_T("scope"), scopeVariant);
            WPEFramework::Core::JSON::Variant keyVariant(key);
            jsonParameters.Set(_T("key"), keyVariant);
        FireboltSDK::JSON::String jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("securestorage.get", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "SecureStorage.get is successfully invoked");
            std::string resultStr;
                jsonResult.ToString(resultStr);
                value = resultStr;
        }

        if (err != nullptr) {
            *err = status;
        }

        return value;
    }

    /* remove - Remove a secure data value */
    void SecureStorageImpl::remove( const StorageScope& scope, const std::string& key, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        JsonData_StorageScope jsonScope = scope;
            WPEFramework::Core::JSON::Variant scopeVariant(jsonScope.Data());
            jsonParameters.Set(_T("scope"), scopeVariant);
            WPEFramework::Core::JSON::Variant keyVariant(key);
            jsonParameters.Set(_T("key"), keyVariant);
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("securestorage.remove", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "SecureStorage.remove is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* set - Set or update a secure data value */
    void SecureStorageImpl::set( const StorageScope& scope, const std::string& key, const std::string& value, const std::optional<StorageOptions>& options, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        JsonData_StorageScope jsonScope = scope;
            WPEFramework::Core::JSON::Variant scopeVariant(jsonScope.Data());
            jsonParameters.Set(_T("scope"), scopeVariant);
            WPEFramework::Core::JSON::Variant keyVariant(key);
            jsonParameters.Set(_T("key"), keyVariant);
            WPEFramework::Core::JSON::Variant valueVariant(value);
            jsonParameters.Set(_T("value"), valueVariant);
            if (options.has_value()) {
                auto element = options.value();
                JsonData_StorageOptions optionsContainer;
                optionsContainer.Ttl = element.ttl;
                string optionsStr;
                optionsContainer.ToString(optionsStr);
                WPEFramework::Core::JSON::VariantContainer optionsVariantContainer(optionsStr);
                WPEFramework::Core::JSON::Variant optionsVariant = optionsVariantContainer;
                jsonParameters.Set(_T("options"), optionsVariant);
            }
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("securestorage.set", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "SecureStorage.set is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }


    // Events

}//namespace SecureStorage
}


namespace WPEFramework {

    /* StorageScope The scope of the data */
    ENUM_CONVERSION_BEGIN(Firebolt::SecureStorage::StorageScope)
        { Firebolt::SecureStorage::StorageScope::DEVICE, _T("device") },
        { Firebolt::SecureStorage::StorageScope::ACCOUNT, _T("account") },
    ENUM_CONVERSION_END(Firebolt::SecureStorage::StorageScope)

}
