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
#include "accessibility_impl.h"
#include "account_impl.h"
#include "advertising_impl.h"
#include "authentication_impl.h"
#include "capabilities_impl.h"
#include "device_impl.h"
#include "discovery_impl.h"
#include "keyboard_impl.h"
#include "lifecycle_impl.h"
#include "localization_impl.h"
#include "metrics_impl.h"
#include "parameters_impl.h"
#include "profile_impl.h"
#include "secondscreen_impl.h"
#include "securestorage_impl.h"


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

        Accessibility::IAccessibility& AccessibilityInterface() const override
        {
            auto module = _moduleMap.find("Accessibility");
            Accessibility::AccessibilityImpl* accessibility = nullptr;

            if (module != _moduleMap.end()) {
                accessibility = dynamic_cast<Accessibility::AccessibilityImpl*>(module->second);
            } else {
                accessibility = new Accessibility::AccessibilityImpl();
                _moduleMap.emplace("Accessibility", accessibility);
            }
            return *accessibility;
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

        Authentication::IAuthentication& AuthenticationInterface() const override
        {
            auto module = _moduleMap.find("Authentication");
            Authentication::AuthenticationImpl* authentication = nullptr;

            if (module != _moduleMap.end()) {
                authentication = dynamic_cast<Authentication::AuthenticationImpl*>(module->second);
            } else {
                authentication = new Authentication::AuthenticationImpl();
                _moduleMap.emplace("Authentication", authentication);
            }
            return *authentication;
        }

        Capabilities::ICapabilities& CapabilitiesInterface() const override
        {
            auto module = _moduleMap.find("Capabilities");
            Capabilities::CapabilitiesImpl* capabilities = nullptr;

            if (module != _moduleMap.end()) {
                capabilities = dynamic_cast<Capabilities::CapabilitiesImpl*>(module->second);
            } else {
                capabilities = new Capabilities::CapabilitiesImpl();
                _moduleMap.emplace("Capabilities", capabilities);
            }
            return *capabilities;
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

        Lifecycle::ILifecycle& LifecycleInterface() const override
        {
            auto module = _moduleMap.find("Lifecycle");
            Lifecycle::LifecycleImpl* lifecycle = nullptr;

            if (module != _moduleMap.end()) {
                lifecycle = dynamic_cast<Lifecycle::LifecycleImpl*>(module->second);
            } else {
                lifecycle = new Lifecycle::LifecycleImpl();
                _moduleMap.emplace("Lifecycle", lifecycle);
            }
            return *lifecycle;
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

        Parameters::IParameters& ParametersInterface() const override
        {
            auto module = _moduleMap.find("Parameters");
            Parameters::ParametersImpl* parameters = nullptr;

            if (module != _moduleMap.end()) {
                parameters = dynamic_cast<Parameters::ParametersImpl*>(module->second);
            } else {
                parameters = new Parameters::ParametersImpl();
                _moduleMap.emplace("Parameters", parameters);
            }
            return *parameters;
        }

        Profile::IProfile& ProfileInterface() const override
        {
            auto module = _moduleMap.find("Profile");
            Profile::ProfileImpl* profile = nullptr;

            if (module != _moduleMap.end()) {
                profile = dynamic_cast<Profile::ProfileImpl*>(module->second);
            } else {
                profile = new Profile::ProfileImpl();
                _moduleMap.emplace("Profile", profile);
            }
            return *profile;
        }

        SecondScreen::ISecondScreen& SecondScreenInterface() const override
        {
            auto module = _moduleMap.find("SecondScreen");
            SecondScreen::SecondScreenImpl* secondscreen = nullptr;

            if (module != _moduleMap.end()) {
                secondscreen = dynamic_cast<SecondScreen::SecondScreenImpl*>(module->second);
            } else {
                secondscreen = new SecondScreen::SecondScreenImpl();
                _moduleMap.emplace("SecondScreen", secondscreen);
            }
            return *secondscreen;
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
