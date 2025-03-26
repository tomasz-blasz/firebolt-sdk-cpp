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

#include "parameters_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Parameters {

    // Methods
    /* initialization - Returns any initialization parameters for the app, e.g. initialial `NavigationIntent`. */
    AppInitialization ParametersImpl::initialization( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        AppInitialization init;

        JsonObject jsonParameters;

        Firebolt::Parameters::JsonData_AppInitialization jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("parameters.initialization", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Parameters.initialization is successfully invoked");
            AppInitialization initResult;
                if (jsonResult.Us_privacy.IsSet()) {
                    initResult.us_privacy = jsonResult.Us_privacy.Value();
                }
                if (jsonResult.Lmt.IsSet()) {
                    initResult.lmt = jsonResult.Lmt.Value();
                }
                if (jsonResult.Discovery.IsSet()) {
                    initResult.discovery = std::make_optional<AppInitializationDiscovery>();
                    if (jsonResult.Discovery.NavigateTo.IsSet()) {
                        string navigateToStr;
                        jsonResult.Discovery.NavigateTo.ToString(navigateToStr);
                        initResult.discovery.value().navigateTo = navigateToStr;
                    }
                  if (jsonResult.Discovery.NavigateTo.IsSet()) {
                        initResult.discovery.value().navigateTo = jsonResult.Discovery.NavigateTo;
                    }
                }
                if (jsonResult.SecondScreen.IsSet()) {
                    initResult.secondScreen = std::make_optional<AppInitializationSecondScreen>();
                    if (jsonResult.SecondScreen.LaunchRequest.IsSet()) {
                        initResult.secondScreen.value().launchRequest = std::make_optional<SecondScreen::SecondScreenEvent>();
                      initResult.secondScreen.value().launchRequest.value().type = jsonResult.SecondScreen.LaunchRequest.Type;
                      if (jsonResult.SecondScreen.LaunchRequest.Version.IsSet()) {
                            initResult.secondScreen.value().launchRequest.value().version = jsonResult.SecondScreen.LaunchRequest.Version;
                        }
                      if (jsonResult.SecondScreen.LaunchRequest.Data.IsSet()) {
                            initResult.secondScreen.value().launchRequest.value().data = jsonResult.SecondScreen.LaunchRequest.Data;
                        }
                    }
                }
                init = initResult;
        }

        if (err != nullptr) {
            *err = status;
        }

        return init;
    }


    // Events

}//namespace Parameters
}

