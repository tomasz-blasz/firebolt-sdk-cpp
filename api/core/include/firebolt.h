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

#include <functional>
#include "types.h"
#include "error.h"
#include "accessibility.h"
#include "account.h"
#include "advertising.h"
#include "authentication.h"
#include "capabilities.h"
#include "device.h"
#include "discovery.h"
#include "keyboard.h"
#include "lifecycle.h"
#include "localization.h"
#include "metrics.h"
#include "parameters.h"
#include "profile.h"
#include "secondscreen.h"
#include "securestorage.h"


namespace Firebolt {

struct IFireboltAccessor {

    virtual ~IFireboltAccessor() = default;

    /**
     * @brief Get the FireboltAccessor singleton instance
     * 
     * @return FireboltAccessor Instance
     * */
    static IFireboltAccessor& Instance();

    /**
     * @brief Inititalize the Firebolt SDK. Sets up the Transport, WorkerPool and Logging Subsystems.
     *
     * @param configLine JSON String with configuration options. At a minimum the user is expected to pass in the Websocket URL.
     *
     * CONFIG Format:
     *  {
     *     "waitTime": 1000,
     *     "logLevel": "Info",
     *     "workerPool":{
     *       "queueSize": 8,
     *       "threadCount": 3
     *      },
     *     "wsUrl": "ws://127.0.0.1:9998"
     *  }
     *
     *
     * @return Firebolt::Error
     *
     */

    virtual Firebolt::Error Initialize ( const std::string& configLine ) = 0;

    /**
     * @brief Deinititlize the SDK. 
     *
     * @return Firebolt::Error
     *
     */
    virtual Firebolt::Error Deinitialize ( ) = 0;


    /**
     * @brief Connection status listener callback
     * 
     * @param connected Connection status: true - Connected, false - Disconnected
     * @param error Reason, if any. 
     * 
     * @return None
    */
    using OnConnectionChanged = std::function<void(const bool connected, const Firebolt::Error error)>;

    /**
     * @brief Attempt a connection to the endpoint. This method is asynchronous and the user is expected to wait for the 
     * OnConnectionChanged callback to report successful connection before calling SDK methods
     *
     * @param listener Connection status listener
     *
     * @return Firebolt::Error
     */
    virtual Firebolt::Error Connect ( OnConnectionChanged listener ) = 0;

    /**
     * @brief Register a callback for any changes in the connection to the endpoint. Only a single callback is supported.
     *
     * @param listener Connection status listener
     *
     * @return None
     */
    virtual void RegisterConnectionChangeListener ( OnConnectionChanged listener ) = 0;

    /**
     * @brief Unregister previously registered callback.
     *
     * @return None
     */
    virtual void UnregisterConnnectionChangeListener ( ) = 0;

    /**
     * @brief Returs whether there is a connection to the endpoint
     *
     * @return bool
     */
    virtual bool IsConnected ( ) const = 0;

    /**
     * @brief Disconnects from the Websocket endpoint.
     * 
     * @return Firebolt::Error
    */
    virtual Firebolt::Error Disconnect ( ) = 0;

    /**
     * @brief Dispose the FireboltAccessor instance and all associated module instances.
     *
     * @return None
     *
     */
    static void Dispose();

    /**
     * @brief Error callback when a method fails.
     * 
     * @param method Name of the method e.g, "Device.id"
     * @param payload JSONRPC Payload of the method.
     * @param error Failure reason.
     * 
     * @return None
    */
    using OnError = std::function<void(const std::string& method, const std::string& payload, const Firebolt::Error error)>;

    /**
     * @brief Register for Error notifications. 
     * 
     * @param notification OnError Notification callback. Passing a nullptr will unregister.
     * 
     * @return None
    */
    virtual void ErrorListener(OnError notification) = 0;


    // Module Instance methods goes here.
    // Instances are owned by the FireboltAcccessor and linked with its lifecycle.

    virtual Accessibility::IAccessibility& AccessibilityInterface() const = 0;

    virtual Account::IAccount& AccountInterface() const = 0;

    virtual Advertising::IAdvertising& AdvertisingInterface() const = 0;

    virtual Authentication::IAuthentication& AuthenticationInterface() const = 0;

    virtual Capabilities::ICapabilities& CapabilitiesInterface() const = 0;

    virtual Device::IDevice& DeviceInterface() const = 0;

    virtual Discovery::IDiscovery& DiscoveryInterface() const = 0;

    virtual Keyboard::IKeyboard& KeyboardInterface() const = 0;

    virtual Lifecycle::ILifecycle& LifecycleInterface() const = 0;

    virtual Localization::ILocalization& LocalizationInterface() const = 0;

    virtual Metrics::IMetrics& MetricsInterface() const = 0;

    virtual Parameters::IParameters& ParametersInterface() const = 0;

    virtual Profile::IProfile& ProfileInterface() const = 0;

    virtual SecondScreen::ISecondScreen& SecondScreenInterface() const = 0;

    virtual SecureStorage::ISecureStorage& SecureStorageInterface() const = 0;


};

}
