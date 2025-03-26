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

#include "localization_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Localization {

    // Methods
    /* addAdditionalInfo - Add any platform-specific localization information in key/value pair */
    void LocalizationImpl::addAdditionalInfo( const std::string& key, const std::string& value, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant keyVariant(key);
            jsonParameters.Set(_T("key"), keyVariant);
            WPEFramework::Core::JSON::Variant valueVariant(value);
            jsonParameters.Set(_T("value"), valueVariant);
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("localization.addAdditionalInfo", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Localization.addAdditionalInfo is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* additionalInfo - Get any platform-specific localization information, in an Map<string, string> */
    Info LocalizationImpl::additionalInfo( Firebolt::Error *err )  const
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;
        Info info;

        JsonObject jsonParameters;

        Firebolt::Localization::JsonData_Info jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("localization.additionalInfo", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Localization.additionalInfo is successfully invoked");
            WPEFramework::Core::JSON::VariantContainer::Iterator variants = jsonResult.Variants(); 
                while (variants.Next()) {
                    std::string key = variants.Label();
                    info.emplace(std::piecewise_construct,
                        std::forward_as_tuple(key),
                        std::forward_as_tuple(variants.Current().String()));
                }
    
        }

        if (err != nullptr) {
            *err = status;
        }

        return info;
    }

    /* countryCode - Get the ISO 3166-1 alpha-2 code for the country device is located in */
    std::string LocalizationImpl::countryCode( Firebolt::Error *err ) const
    {
        const string method = _T("localization.countryCode");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string code;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            code = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return code;
    }
    /* setCountryCode - Get the ISO 3166-1 alpha-2 code for the country device is located in */
    void LocalizationImpl::setCountryCode( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("localization.setCountryCode");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* language - Get the ISO 639 1/2 code for the preferred language */
    std::string LocalizationImpl::language( Firebolt::Error *err ) const
    {
        const string method = _T("localization.language");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string lang;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            lang = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return lang;
    }
    /* setLanguage - Get the ISO 639 1/2 code for the preferred language */
    void LocalizationImpl::setLanguage( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("localization.setLanguage");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* locale - Get the *full* BCP 47 code, including script, region, variant, etc., for the preferred langauage/locale */
    std::string LocalizationImpl::locale( Firebolt::Error *err ) const
    {
        const string method = _T("localization.locale");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string locale;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            locale = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return locale;
    }
    /* setLocale - Get the *full* BCP 47 code, including script, region, variant, etc., for the preferred langauage/locale */
    void LocalizationImpl::setLocale( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("localization.setLocale");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* locality - Get the locality/city the device is located in */
    std::string LocalizationImpl::locality( Firebolt::Error *err ) const
    {
        const string method = _T("localization.locality");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string locality;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            locality = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return locality;
    }
    /* setLocality - Get the locality/city the device is located in */
    void LocalizationImpl::setLocality( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("localization.setLocality");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* postalCode - Get the postal code the device is located in */
    std::string LocalizationImpl::postalCode( Firebolt::Error *err ) const
    {
        const string method = _T("localization.postalCode");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string postalCode;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            postalCode = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return postalCode;
    }
    /* setPostalCode - Get the postal code the device is located in */
    void LocalizationImpl::setPostalCode( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("localization.setPostalCode");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* preferredAudioLanguages - A prioritized list of ISO 639 1/2 codes for the preferred audio languages on this device. */
    std::vector<std::string> LocalizationImpl::preferredAudioLanguages( Firebolt::Error *err ) const
    {
        const string method = _T("localization.preferredAudioLanguages");
        
        
        WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String> jsonResult;
        std::vector<std::string> languages;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            auto index(jsonResult.Elements());
            while (index.Next() == true) {
                languages.push_back(index.Current().Value());
            }
        }
        if (err != nullptr) {
            *err = status;
        }

        return languages;
    }
    /* setPreferredAudioLanguages - A prioritized list of ISO 639 1/2 codes for the preferred audio languages on this device. */
    void LocalizationImpl::setPreferredAudioLanguages( const std::vector<std::string>& value, Firebolt::Error *err )
    {
        const string method = _T("localization.setPreferredAudioLanguages");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::ArrayType<WPEFramework::Core::JSON::Variant> valueArray;
        for (auto& element : value) {
             valueArray.Add() = element;
        }
        WPEFramework::Core::JSON::Variant valueVariant;
        valueVariant.Array(valueArray);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* removeAdditionalInfo - Remove any platform-specific localization information from map */
    void LocalizationImpl::removeAdditionalInfo( const std::string& key, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant keyVariant(key);
            jsonParameters.Set(_T("key"), keyVariant);
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("localization.removeAdditionalInfo", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Localization.removeAdditionalInfo is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }

    /* timeZone - Set the IANA timezone for the device */
    std::string LocalizationImpl::timeZone( Firebolt::Error *err ) const
    {
        const string method = _T("localization.timeZone");
        
        
        FireboltSDK::JSON::String jsonResult;
        std::string result;
        
        Firebolt::Error status = FireboltSDK::Properties::Get(method, jsonResult);
        if (status == Firebolt::Error::None) {
            result = jsonResult.Value().c_str();
        }
        if (err != nullptr) {
            *err = status;
        }

        return result;
    }
    /* setTimeZone - Set the IANA timezone for the device */
    void LocalizationImpl::setTimeZone( const std::string& value, Firebolt::Error *err )
    {
        const string method = _T("localization.setTimeZone");

        JsonObject jsonParameters;
        WPEFramework::Core::JSON::Variant valueVariant(value);
        jsonParameters.Set(_T("value"), valueVariant);

        Firebolt::Error status = FireboltSDK::Properties::Set(method, jsonParameters);
        if (err != nullptr) {
            *err = status;
        }

        return;
    }


    // Events
    /* onCountryCodeChanged - Get the ISO 3166-1 alpha-2 code for the country device is located in */
    static void onCountryCodeChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            ILocalization::IOnCountryCodeChangedNotification& notifier = *(reinterpret_cast<ILocalization::IOnCountryCodeChangedNotification*>(notification));
            notifier.onCountryCodeChanged(result);
        }
    }
    void LocalizationImpl::subscribe( ILocalization::IOnCountryCodeChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("localization.onCountryCodeChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onCountryCodeChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LocalizationImpl::unsubscribe( ILocalization::IOnCountryCodeChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("localization.onCountryCodeChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onLanguageChanged - Get the ISO 639 1/2 code for the preferred language */
    static void onLanguageChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            ILocalization::IOnLanguageChangedNotification& notifier = *(reinterpret_cast<ILocalization::IOnLanguageChangedNotification*>(notification));
            notifier.onLanguageChanged(result);
        }
    }
    void LocalizationImpl::subscribe( ILocalization::IOnLanguageChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("localization.onLanguageChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onLanguageChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LocalizationImpl::unsubscribe( ILocalization::IOnLanguageChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("localization.onLanguageChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onLocaleChanged - Get the *full* BCP 47 code, including script, region, variant, etc., for the preferred langauage/locale */
    static void onLocaleChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            ILocalization::IOnLocaleChangedNotification& notifier = *(reinterpret_cast<ILocalization::IOnLocaleChangedNotification*>(notification));
            notifier.onLocaleChanged(result);
        }
    }
    void LocalizationImpl::subscribe( ILocalization::IOnLocaleChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("localization.onLocaleChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onLocaleChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LocalizationImpl::unsubscribe( ILocalization::IOnLocaleChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("localization.onLocaleChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onLocalityChanged - Get the locality/city the device is located in */
    static void onLocalityChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            ILocalization::IOnLocalityChangedNotification& notifier = *(reinterpret_cast<ILocalization::IOnLocalityChangedNotification*>(notification));
            notifier.onLocalityChanged(result);
        }
    }
    void LocalizationImpl::subscribe( ILocalization::IOnLocalityChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("localization.onLocalityChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onLocalityChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LocalizationImpl::unsubscribe( ILocalization::IOnLocalityChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("localization.onLocalityChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onPostalCodeChanged - Get the postal code the device is located in */
    static void onPostalCodeChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            ILocalization::IOnPostalCodeChangedNotification& notifier = *(reinterpret_cast<ILocalization::IOnPostalCodeChangedNotification*>(notification));
            notifier.onPostalCodeChanged(result);
        }
    }
    void LocalizationImpl::subscribe( ILocalization::IOnPostalCodeChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("localization.onPostalCodeChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onPostalCodeChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LocalizationImpl::unsubscribe( ILocalization::IOnPostalCodeChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("localization.onPostalCodeChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onPreferredAudioLanguagesChanged - A prioritized list of ISO 639 1/2 codes for the preferred audio languages on this device. */
    static void onPreferredAudioLanguagesChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String>>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String>>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::vector<std::string> result;


            auto index(proxyResponse->Elements());
            while (index.Next() == true) {
                result.push_back(index.Current().Value());
            }
            proxyResponse.Release();

            ILocalization::IOnPreferredAudioLanguagesChangedNotification& notifier = *(reinterpret_cast<ILocalization::IOnPreferredAudioLanguagesChangedNotification*>(notification));
            notifier.onPreferredAudioLanguagesChanged(result);
        }
    }
    void LocalizationImpl::subscribe( ILocalization::IOnPreferredAudioLanguagesChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("localization.onPreferredAudioLanguagesChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<WPEFramework::Core::JSON::ArrayType<FireboltSDK::JSON::String>>(eventName, jsonParameters, onPreferredAudioLanguagesChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LocalizationImpl::unsubscribe( ILocalization::IOnPreferredAudioLanguagesChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("localization.onPreferredAudioLanguagesChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onTimeZoneChanged - Set the IANA timezone for the device */
    static void onTimeZoneChangedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<FireboltSDK::JSON::String>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            std::string result;

            result = proxyResponse->Value();

            proxyResponse.Release();

            ILocalization::IOnTimeZoneChangedNotification& notifier = *(reinterpret_cast<ILocalization::IOnTimeZoneChangedNotification*>(notification));
            notifier.onTimeZoneChanged(result);
        }
    }
    void LocalizationImpl::subscribe( ILocalization::IOnTimeZoneChangedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("localization.onTimeZoneChanged");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<FireboltSDK::JSON::String>(eventName, jsonParameters, onTimeZoneChangedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LocalizationImpl::unsubscribe( ILocalization::IOnTimeZoneChangedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("localization.onTimeZoneChanged"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Localization
}

