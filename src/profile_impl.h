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
#include "jsondata_types.h"

#include "profile.h"


namespace Firebolt {
namespace Profile {


    class ProfileImpl : public IProfile, public IModule {

    public:
        ProfileImpl() = default;
        ProfileImpl(const ProfileImpl&) = delete;
        ProfileImpl& operator=(const ProfileImpl&) = delete;

        ~ProfileImpl() override = default;

        // Methods & Events
        /*
         approveContentRating
         Verifies that the current profile should have access to mature/adult content.
         */
        bool approveContentRating( Firebolt::Error *err = nullptr ) const override;

        /*
         approvePurchase
         Verifies that the current profile should have access to making purchases.
         */
        bool approvePurchase( Firebolt::Error *err = nullptr ) const override;

        /*
         flags
         Get a map of profile flags for the current session.
         */
        Types::FlatMap flags( Firebolt::Error *err = nullptr ) const override;

    };

}//namespace Profile
}
