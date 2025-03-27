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

#include <firebolt.h>
#include "FireboltSDK.h"
#include "IModule.h"
#include "localization_impl.h"
#include "metrics_impl.h"
#include "wifi_impl.h"
#include "closedcaptions_impl.h"
#include "audiodescriptions_impl.h"
#include "voiceguidance_impl.h"
#include "device_impl.h"
#include "usergrants_impl.h"
#include "privacy_impl.h"
#include "advertising_impl.h"
#include "account_impl.h"
#include "keyboard_impl.h"
#include "acknowledgechallenge_impl.h"
#include "pinchallenge_impl.h"
#include "securestorage_impl.h"
#include "discovery_impl.h"
#include "hdmiinput_impl.h"


namespace Firebolt {

    class FireboltAccessorImpl : public IFireboltAccessor {
    private:
        using ModuleMap = std::unordered_map<string, IModule*>;

    private:
        FireboltAccessorImpl()
            : _accessor(nullptr)
        {
            ASSERT(_singleton == nullptr);
            _singleton = this;
        }
    public:
        FireboltAccessorImpl(const FireboltAccessorImpl&) = delete;
        FireboltAccessorImpl& operator=(const FireboltAccessorImpl&) = delete;

        ~FireboltAccessorImpl()
        {
            if (_accessor != nullptr) {
                _accessor->Dispose();
                _accessor = nullptr;
            }

            ASSERT(_singleton != nullptr);
            _singleton = nullptr;
        }

        static FireboltAccessorImpl& Instance()
        {
            if (_singleton == nullptr) {
                _singleton = new FireboltAccessorImpl();
                ASSERT(_singleton != nullptr);
            }
            return *_singleton;
        }

        static void Dispose()
        {
            ModuleMap::iterator module = _moduleMap.begin();
            while (module != _moduleMap.end()) {
                delete module->second;
                module = _moduleMap.erase(module);
            }

            ASSERT(_singleton != nullptr);
            if (_singleton != nullptr) {
                delete _singleton;
                _singleton = nullptr;
            }
        }

        Firebolt::Error Initialize( const std::string& configLine ) override
        {
            _accessor = &(FireboltSDK::Accessor::Instance(configLine));
            return Error::None;
        }

        Firebolt::Error Deinitialize() override
        {
            return Error::None;
        }

        Firebolt::Error Connect( OnConnectionChanged listener ) override
        {
            return _accessor->Connect(listener);
        }

        void RegisterConnectionChangeListener( OnConnectionChanged listener ) override
        {
            return _accessor->RegisterConnectionChangeListener(listener);
        }

        void UnregisterConnnectionChangeListener() override
        {
            _accessor->UnregisterConnnectionChangeListener();
        }

        bool IsConnected() const override
        {
            return _accessor->IsConnected();
        }

        Firebolt::Error Disconnect() override
        {
            return _accessor->Disconnect();
        }

        void ErrorListener(OnError notification) override
        {
        }

        Localization::ILocalization& LocalizationInterface() const override
        {
            auto module = _moduleMap.find("Localization");
            Localization::LocalizationImpl* localization = nullptr;

            if (module != _moduleMap.end()) {
                localization = dynamic_cast<Localization::LocalizationImpl*>(module->second);
            } else {
                localization = new Localization::LocalizationImpl();
                _moduleMap.emplace("Localization", localization);
            }
            return *localization;
        }

        Metrics::IMetrics& MetricsInterface() const override
        {
            auto module = _moduleMap.find("Metrics");
            Metrics::MetricsImpl* metrics = nullptr;

            if (module != _moduleMap.end()) {
                metrics = dynamic_cast<Metrics::MetricsImpl*>(module->second);
            } else {
                metrics = new Metrics::MetricsImpl();
                _moduleMap.emplace("Metrics", metrics);
            }
            return *metrics;
        }

        Wifi::IWifi& WifiInterface() const override
        {
            auto module = _moduleMap.find("Wifi");
            Wifi::WifiImpl* wifi = nullptr;

            if (module != _moduleMap.end()) {
                wifi = dynamic_cast<Wifi::WifiImpl*>(module->second);
            } else {
                wifi = new Wifi::WifiImpl();
                _moduleMap.emplace("Wifi", wifi);
            }
            return *wifi;
        }

        ClosedCaptions::IClosedCaptions& ClosedCaptionsInterface() const override
        {
            auto module = _moduleMap.find("ClosedCaptions");
            ClosedCaptions::ClosedCaptionsImpl* closedcaptions = nullptr;

            if (module != _moduleMap.end()) {
                closedcaptions = dynamic_cast<ClosedCaptions::ClosedCaptionsImpl*>(module->second);
            } else {
                closedcaptions = new ClosedCaptions::ClosedCaptionsImpl();
                _moduleMap.emplace("ClosedCaptions", closedcaptions);
            }
            return *closedcaptions;
        }

        AudioDescriptions::IAudioDescriptions& AudioDescriptionsInterface() const override
        {
            auto module = _moduleMap.find("AudioDescriptions");
            AudioDescriptions::AudioDescriptionsImpl* audiodescriptions = nullptr;

            if (module != _moduleMap.end()) {
                audiodescriptions = dynamic_cast<AudioDescriptions::AudioDescriptionsImpl*>(module->second);
            } else {
                audiodescriptions = new AudioDescriptions::AudioDescriptionsImpl();
                _moduleMap.emplace("AudioDescriptions", audiodescriptions);
            }
            return *audiodescriptions;
        }

        VoiceGuidance::IVoiceGuidance& VoiceGuidanceInterface() const override
        {
            auto module = _moduleMap.find("VoiceGuidance");
            VoiceGuidance::VoiceGuidanceImpl* voiceguidance = nullptr;

            if (module != _moduleMap.end()) {
                voiceguidance = dynamic_cast<VoiceGuidance::VoiceGuidanceImpl*>(module->second);
            } else {
                voiceguidance = new VoiceGuidance::VoiceGuidanceImpl();
                _moduleMap.emplace("VoiceGuidance", voiceguidance);
            }
            return *voiceguidance;
        }

        Device::IDevice& DeviceInterface() const override
        {
            auto module = _moduleMap.find("Device");
            Device::DeviceImpl* device = nullptr;

            if (module != _moduleMap.end()) {
                device = dynamic_cast<Device::DeviceImpl*>(module->second);
            } else {
                device = new Device::DeviceImpl();
                _moduleMap.emplace("Device", device);
            }
            return *device;
        }

        UserGrants::IUserGrants& UserGrantsInterface() const override
        {
            auto module = _moduleMap.find("UserGrants");
            UserGrants::UserGrantsImpl* usergrants = nullptr;

            if (module != _moduleMap.end()) {
                usergrants = dynamic_cast<UserGrants::UserGrantsImpl*>(module->second);
            } else {
                usergrants = new UserGrants::UserGrantsImpl();
                _moduleMap.emplace("UserGrants", usergrants);
            }
            return *usergrants;
        }

        Privacy::IPrivacy& PrivacyInterface() const override
        {
            auto module = _moduleMap.find("Privacy");
            Privacy::PrivacyImpl* privacy = nullptr;

            if (module != _moduleMap.end()) {
                privacy = dynamic_cast<Privacy::PrivacyImpl*>(module->second);
            } else {
                privacy = new Privacy::PrivacyImpl();
                _moduleMap.emplace("Privacy", privacy);
            }
            return *privacy;
        }

        Advertising::IAdvertising& AdvertisingInterface() const override
        {
            auto module = _moduleMap.find("Advertising");
            Advertising::AdvertisingImpl* advertising = nullptr;

            if (module != _moduleMap.end()) {
                advertising = dynamic_cast<Advertising::AdvertisingImpl*>(module->second);
            } else {
                advertising = new Advertising::AdvertisingImpl();
                _moduleMap.emplace("Advertising", advertising);
            }
            return *advertising;
        }

        Account::IAccount& AccountInterface() const override
        {
            auto module = _moduleMap.find("Account");
            Account::AccountImpl* account = nullptr;

            if (module != _moduleMap.end()) {
                account = dynamic_cast<Account::AccountImpl*>(module->second);
            } else {
                account = new Account::AccountImpl();
                _moduleMap.emplace("Account", account);
            }
            return *account;
        }

        Keyboard::IKeyboard& KeyboardInterface() const override
        {
            auto module = _moduleMap.find("Keyboard");
            Keyboard::KeyboardImpl* keyboard = nullptr;

            if (module != _moduleMap.end()) {
                keyboard = dynamic_cast<Keyboard::KeyboardImpl*>(module->second);
            } else {
                keyboard = new Keyboard::KeyboardImpl();
                _moduleMap.emplace("Keyboard", keyboard);
            }
            return *keyboard;
        }

        AcknowledgeChallenge::IAcknowledgeChallenge& AcknowledgeChallengeInterface() const override
        {
            auto module = _moduleMap.find("AcknowledgeChallenge");
            AcknowledgeChallenge::AcknowledgeChallengeImpl* acknowledgechallenge = nullptr;

            if (module != _moduleMap.end()) {
                acknowledgechallenge = dynamic_cast<AcknowledgeChallenge::AcknowledgeChallengeImpl*>(module->second);
            } else {
                acknowledgechallenge = new AcknowledgeChallenge::AcknowledgeChallengeImpl();
                _moduleMap.emplace("AcknowledgeChallenge", acknowledgechallenge);
            }
            return *acknowledgechallenge;
        }

        PinChallenge::IPinChallenge& PinChallengeInterface() const override
        {
            auto module = _moduleMap.find("PinChallenge");
            PinChallenge::PinChallengeImpl* pinchallenge = nullptr;

            if (module != _moduleMap.end()) {
                pinchallenge = dynamic_cast<PinChallenge::PinChallengeImpl*>(module->second);
            } else {
                pinchallenge = new PinChallenge::PinChallengeImpl();
                _moduleMap.emplace("PinChallenge", pinchallenge);
            }
            return *pinchallenge;
        }

        SecureStorage::ISecureStorage& SecureStorageInterface() const override
        {
            auto module = _moduleMap.find("SecureStorage");
            SecureStorage::SecureStorageImpl* securestorage = nullptr;

            if (module != _moduleMap.end()) {
                securestorage = dynamic_cast<SecureStorage::SecureStorageImpl*>(module->second);
            } else {
                securestorage = new SecureStorage::SecureStorageImpl();
                _moduleMap.emplace("SecureStorage", securestorage);
            }
            return *securestorage;
        }

        Discovery::IDiscovery& DiscoveryInterface() const override
        {
            auto module = _moduleMap.find("Discovery");
            Discovery::DiscoveryImpl* discovery = nullptr;

            if (module != _moduleMap.end()) {
                discovery = dynamic_cast<Discovery::DiscoveryImpl*>(module->second);
            } else {
                discovery = new Discovery::DiscoveryImpl();
                _moduleMap.emplace("Discovery", discovery);
            }
            return *discovery;
        }

        HDMIInput::IHDMIInput& HDMIInputInterface() const override
        {
            auto module = _moduleMap.find("HDMIInput");
            HDMIInput::HDMIInputImpl* hdmiinput = nullptr;

            if (module != _moduleMap.end()) {
                hdmiinput = dynamic_cast<HDMIInput::HDMIInputImpl*>(module->second);
            } else {
                hdmiinput = new HDMIInput::HDMIInputImpl();
                _moduleMap.emplace("HDMIInput", hdmiinput);
            }
            return *hdmiinput;
        }


    private:
        FireboltSDK::Accessor* _accessor;
        static FireboltAccessorImpl* _singleton;
        static ModuleMap _moduleMap;
    };

    FireboltAccessorImpl::ModuleMap FireboltAccessorImpl::_moduleMap;

    FireboltAccessorImpl* FireboltAccessorImpl::_singleton = nullptr;

    /* static */ IFireboltAccessor& IFireboltAccessor::Instance()
    {
         return (FireboltAccessorImpl::Instance());
    }
    /* static */ void IFireboltAccessor::Dispose()
    {
         FireboltAccessorImpl::Dispose();
    }
}
