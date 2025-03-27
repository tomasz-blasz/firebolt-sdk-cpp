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

#include "profile_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Profile {

    // Methods
    /* approveContentRating - Verifies that the current profile should have access to mature/adult content. */
    bool ProfileImpl::approveContentRating( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool allow = false;

        JsonObject jsonParameters;

        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("profile.approveContentRating", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Profile.approveContentRating is successfully invoked");
            allow = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }

    /* approvePurchase - Verifies that the current profile should have access to making purchases. */
    bool ProfileImpl::approvePurchase( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        bool allow = false;

        JsonObject jsonParameters;

        WPEFramework::Core::JSON::Boolean jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("profile.approvePurchase", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Profile.approvePurchase is successfully invoked");
            allow = jsonResult.Value();
        }

        if (err != nullptr) {
            *err = status;
        }

        return allow;
    }

    /* flags - Get a map of profile flags for the current session. */
    Types::FlatMap ProfileImpl::flags( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        Types::FlatMap flags;

        JsonObject jsonParameters;

        Firebolt::Types::JsonData_FlatMap jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("profile.flags", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Profile.flags is successfully invoked");
            WPEFramework::Core::JSON::VariantContainer::Iterator variants = jsonResult.Variants(); 
                while (variants.Next()) {
                    std::string key = variants.Label();
                    flags.emplace(std::piecewise_construct,
                        std::forward_as_tuple(key),
                        std::forward_as_tuple(variants.Current().String()));
                }
    
        }

        if (err != nullptr) {
            *err = status;
        }

        return flags;
    }


    // Events

}//namespace Profile
}

