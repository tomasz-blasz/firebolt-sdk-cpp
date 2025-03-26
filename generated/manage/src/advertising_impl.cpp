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

#include "advertising_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Advertising {

    // Methods
    /* resetIdentifier - Resets a user's identifier in the ad platform so that the advertising id that apps get will be a new value */
    void AdvertisingImpl::resetIdentifier( Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;

        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("advertising.resetIdentifier", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Advertising.resetIdentifier is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* skipRestriction - Set the value for AdPolicy.skipRestriction */
    SkipRestriction AdvertisingImpl::skipRestriction( Firebolt::Error *err ) const
    {
        const string method = _T("advertising.skipRestriction");
        
        
        Firebolt::Advertising::JsonData_SkipRestriction jsonResult;
        SkipRestriction result;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            result = jsonResult.Value();
        }
        if (err != nullptr) {
            *err = status;
        }

        return result;
    }
    /* setSkipRestriction - Set the value for AdPolicy.skipRestriction */
    void AdvertisingImpl::setSkipRestriction( const SkipRestriction& value, Firebolt::Error *err )
    {
        const string method = _T("advertising.setSkipRestriction");

        JsonObject jsonParameters;
        JsonData_SkipRestriction jsonValue = value;
        WPEFramework::Core::JSON::Variant valueVariant(jsonValue.Data());
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }


    // Events
    /* onSkipRestrictionChanged - Set the value for AdPolicy.skipRestriction */
    static void onSkipRestrictionChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Advertising::JsonData_SkipRestriction>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Advertising::JsonData_SkipRestriction>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            SkipRestriction result;

            result = proxyResponse->Value();
            proxyResponse.Release();

            IAdvertising::IOnSkipRestrictionChangedNotification& notifier = *(reinterpret_cast<IAdvertising::IOnSkipRestrictionChangedNotification*>(notification));
            notifier.onSkipRestrictionChanged(result);
        }
    }
    void AdvertisingImpl::subscribe( IAdvertising::IOnSkipRestrictionChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("advertising.onSkipRestrictionChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Advertising::JsonData_SkipRestriction>(eventName, jsonParameters, onSkipRestrictionChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void AdvertisingImpl::unsubscribe( IAdvertising::IOnSkipRestrictionChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("advertising.onSkipRestrictionChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Advertising
}

