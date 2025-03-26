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
#include "jsondata_secondscreen.h"

#include "secondscreen.h"


namespace Firebolt {
namespace SecondScreen {


    class SecondScreenImpl : public ISecondScreen, public IModule {

    public:
        SecondScreenImpl() = default;
        SecondScreenImpl(const SecondScreenImpl&) = delete;
        SecondScreenImpl& operator=(const SecondScreenImpl&) = delete;

        ~SecondScreenImpl() override = default;

        // Methods & Events
        /*
         device
         Get the broadcasted id for the device
         */
        std::string device( const std::optional<std::string>& type, Firebolt::Error *err = nullptr ) override;

        /*
         * Get the broadcasted friendly name for the device
         * 
         */
        std::string friendlyName( Firebolt::Error *err = nullptr ) const override;
        // signature callback params: 
        // method result properties : 
        void subscribe( ISecondScreen::IOnCloseRequestNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ISecondScreen::IOnCloseRequestNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ISecondScreen::IOnFriendlyNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ISecondScreen::IOnFriendlyNameChangedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ISecondScreen::IOnLaunchRequestNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ISecondScreen::IOnLaunchRequestNotification& notification, Firebolt::Error *err = nullptr ) override;

        /*
         protocols
         Get the supported second screen discovery protocols
         */
        Types::BooleanMap protocols( Firebolt::Error *err = nullptr ) const override;

    };

}//namespace SecondScreen
}
