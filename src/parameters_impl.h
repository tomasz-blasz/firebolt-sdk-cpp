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
#include "jsondata_intents.h"
#include "jsondata_entity.h"
#include "jsondata_entertainment.h"
#include "jsondata_secondscreen.h"
#include "jsondata_types.h"

#include "parameters.h"


namespace Firebolt {
namespace Parameters {


    // Types
    class JsonData_AppInitializationDiscovery: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AppInitializationDiscovery() override = default;
  
    public:
        JsonData_AppInitializationDiscovery()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("navigateTo"), &NavigateTo);
        }

        JsonData_AppInitializationDiscovery(const JsonData_AppInitializationDiscovery& other)
        {
            Add(_T("navigateTo"), &NavigateTo);
            NavigateTo = other.NavigateTo;
        }

        JsonData_AppInitializationDiscovery& operator=(const JsonData_AppInitializationDiscovery& other)
        {
            Add(_T("navigateTo"), &NavigateTo);
            NavigateTo = other.NavigateTo;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String NavigateTo;
    };

    class JsonData_AppInitializationSecondScreen: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AppInitializationSecondScreen() override = default;
  
    public:
        JsonData_AppInitializationSecondScreen()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("launchRequest"), &LaunchRequest);
        }

        JsonData_AppInitializationSecondScreen(const JsonData_AppInitializationSecondScreen& other)
        {
            Add(_T("launchRequest"), &LaunchRequest);
            LaunchRequest = other.LaunchRequest;
        }

        JsonData_AppInitializationSecondScreen& operator=(const JsonData_AppInitializationSecondScreen& other)
        {
            Add(_T("launchRequest"), &LaunchRequest);
            LaunchRequest = other.LaunchRequest;
            return (*this);
        }

    public:
        Firebolt::SecondScreen::JsonData_SecondScreenEvent LaunchRequest;
    };

    class JsonData_AppInitialization: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_AppInitialization() override = default;
  
    public:
        JsonData_AppInitialization()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("us_privacy"), &Us_privacy);
            Add(_T("lmt"), &Lmt);
            Add(_T("discovery"), &Discovery);
            Add(_T("secondScreen"), &SecondScreen);
        }

        JsonData_AppInitialization(const JsonData_AppInitialization& other)
        {
            Add(_T("us_privacy"), &Us_privacy);
            Us_privacy = other.Us_privacy;
            Add(_T("lmt"), &Lmt);
            Lmt = other.Lmt;
            Add(_T("discovery"), &Discovery);
            Discovery = other.Discovery;
            Add(_T("secondScreen"), &SecondScreen);
            SecondScreen = other.SecondScreen;
        }

        JsonData_AppInitialization& operator=(const JsonData_AppInitialization& other)
        {
            Add(_T("us_privacy"), &Us_privacy);
            Us_privacy = other.Us_privacy;
            Add(_T("lmt"), &Lmt);
            Lmt = other.Lmt;
            Add(_T("discovery"), &Discovery);
            Discovery = other.Discovery;
            Add(_T("secondScreen"), &SecondScreen);
            SecondScreen = other.SecondScreen;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Us_privacy;
        WPEFramework::Core::JSON::DecSInt32 Lmt;
        Firebolt::Parameters::JsonData_AppInitializationDiscovery Discovery;
        Firebolt::Parameters::JsonData_AppInitializationSecondScreen SecondScreen;
    };

    class ParametersImpl : public IParameters, public IModule {

    public:
        ParametersImpl() = default;
        ParametersImpl(const ParametersImpl&) = delete;
        ParametersImpl& operator=(const ParametersImpl&) = delete;

        ~ParametersImpl() override = default;

        // Methods & Events
        /*
         initialization
         Returns any initialization parameters for the app, e.g. initialial `NavigationIntent`.
         */
        AppInitialization initialization( Firebolt::Error *err = nullptr ) const override;

    };

}//namespace Parameters
}
