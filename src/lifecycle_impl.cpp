/* Copyright 2023 Comcast Cable Communications Management, LLC
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


#include "lifecycle_impl.h"
#include "Gateway/Gateway.h"


namespace Firebolt {
namespace Lifecycle {


EnumMap<Firebolt::Lifecycle::LifecycleState> lifecycleStateMap = {
    { Firebolt::Lifecycle::LifecycleState::INITIALIZING, "initializing" },
    { Firebolt::Lifecycle::LifecycleState::INACTIVE, "inactive" },
    { Firebolt::Lifecycle::LifecycleState::FOREGROUND, "foreground" },
    { Firebolt::Lifecycle::LifecycleState::BACKGROUND, "background" },
    { Firebolt::Lifecycle::LifecycleState::UNLOADING, "unloading" },
    { Firebolt::Lifecycle::LifecycleState::SUSPENDED, "suspended" }
};

#ifdef GATEWAY_BIDIRECTIONAL

/* ready - Notify the platform that the app is ready */
static void readyDispatcher(const void* result) {
    Firebolt::IFireboltAccessor::Instance().MetricsInterface().ready();
}

// localCallback to update the state
static void onReadyInnerCallback(void* notification, const void* userData, void* jsonResponse)
{
    const LifecycleImpl* selfConst = static_cast<const LifecycleImpl*>(userData);
    LifecycleImpl* self = const_cast<LifecycleImpl*>(selfConst);

    WPEFramework::Core::ProxyType<JsonData_LifecycleEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<JsonData_LifecycleEvent>*>(jsonResponse));
    ASSERT(proxyResponse.IsValid() == true);

    if (proxyResponse.IsValid() == true) {
        LifecycleEvent value;

        value.state = proxyResponse->State;
        std::string stateStr = ConvertEnum<Firebolt::Lifecycle::LifecycleState>(lifecycleStateMap, value.state);
        // Assign stateStr to currentState in LifecycleImpl instance
        self->currentState = stateStr;
        std::cout << "Updated the Current State to: " << self->currentState << std::endl;

        proxyResponse.Release();

    }
}

/* ready - Notify the platform that the app is ready */
void LifecycleImpl::ready(Firebolt::Error *err) {
    Firebolt::Error status = Firebolt::Error::NotConnected;

    JsonObject jsonParameters;

    // Call Prioritize to subscribe to corresponding event, add to internalMap, and prioritize its callback
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onForeground", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onBackground", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onInactive", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onSuspended", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onUnloading", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);

    WPEFramework::Core::JSON::VariantContainer jsonResult;
    status = FireboltSDK::Gateway::Instance().Request("lifecycle.ready", jsonParameters, jsonResult);
    if (status == Firebolt::Error::None) {
        FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Lifecycle.ready is successfully invoked");

        WPEFramework::Core::ProxyType<WPEFramework::Core::IDispatch> job = WPEFramework::Core::ProxyType<WPEFramework::Core::IDispatch>(WPEFramework::Core::ProxyType<FireboltSDK::Worker>::Create(readyDispatcher, nullptr));
        WPEFramework::Core::IWorkerPool::Instance().Submit(job);
    } else {
        FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in invoking lifecycle.ready: %d", status);
    }

    if (err != nullptr) {
        *err = status;
    }
}

/* state - return the state of the app */
std::string LifecycleImpl::state(Firebolt::Error *err)  {
    std::cout << "**CURRENT STATE OF THE APP::::**" << currentState << std::endl;
    return currentState;
}

/* finished - Notify the platform that the app is done unloading */
void LifecycleImpl::finished(Firebolt::Error *err)
{
    Firebolt::Error status = Firebolt::Error::NotConnected;
    if(currentState == "unloading")
    {
        JsonObject jsonParameters;

        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("lifecycle.finished", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Lifecycle.finished is successfully invoked");
        }

        if (err != nullptr) {
            *err = status;
        }
    }

    return;
}

#else

/* ready - Notify the platform that the app is ready */
static void readyDispatcher(const void* result) {
    Firebolt::IFireboltAccessor::Instance().MetricsInterface().ready();
}

// localCallback to update the state
static void onReadyInnerCallback(void* notification, const void* userData, void* jsonResponse)
{
    const LifecycleImpl* selfConst = static_cast<const LifecycleImpl*>(userData);
    LifecycleImpl* self = const_cast<LifecycleImpl*>(selfConst);

    WPEFramework::Core::ProxyType<JsonData_LifecycleEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<JsonData_LifecycleEvent>*>(jsonResponse));
    ASSERT(proxyResponse.IsValid() == true);

    if (proxyResponse.IsValid() == true) {
        LifecycleEvent value;

        value.state = proxyResponse->State;
        std::string stateStr = ConvertEnum<Firebolt::Lifecycle::LifecycleState>(lifecycleStateMap, value.state);
        // Assign stateStr to currentState in LifecycleImpl instance
        self->currentState = stateStr;
        std::cout << "Updated the Current State to: " << self->currentState << std::endl;

        proxyResponse.Release();

    }
}

/* ready - Notify the platform that the app is ready */
void LifecycleImpl::ready(Firebolt::Error *err) {
    Firebolt::Error status = Firebolt::Error::NotConnected;

    JsonObject jsonParameters;

    // Call Prioritize to subscribe to corresponding event, add to internalMap, and prioritize its callback
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onForeground", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onBackground", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onInactive", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onSuspended", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);
    status = FireboltSDK::Event::Instance().Prioritize<JsonData_LifecycleEvent>("lifecycle.onUnloading", jsonParameters, onReadyInnerCallback, (void*)nullptr, this);

    WPEFramework::Core::JSON::VariantContainer jsonResult;
    status = FireboltSDK::Gateway::Instance().Request("lifecycle.ready", jsonParameters, jsonResult);
    if (status == Firebolt::Error::None) {
        FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Lifecycle.ready is successfully invoked");

        WPEFramework::Core::ProxyType<WPEFramework::Core::IDispatch> job = WPEFramework::Core::ProxyType<WPEFramework::Core::IDispatch>(WPEFramework::Core::ProxyType<FireboltSDK::Worker>::Create(readyDispatcher, nullptr));
        WPEFramework::Core::IWorkerPool::Instance().Submit(job);
    } else {
        FIREBOLT_LOG_ERROR(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Error in invoking lifecycle.ready: %d", status);
    }

    if (err != nullptr) {
        *err = status;
    }
}

/* state - return the state of the app */
std::string LifecycleImpl::state(Firebolt::Error *err)  {
    std::cout << "**CURRENT STATE OF THE APP::::**" << currentState << std::endl;
    return currentState;
}

/* finished - Notify the platform that the app is done unloading */
void LifecycleImpl::finished(Firebolt::Error *err)
{
    Firebolt::Error status = Firebolt::Error::NotConnected;
    if(currentState == "unloading")
    {
        JsonObject jsonParameters;

        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("lifecycle.finished", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Lifecycle.finished is successfully invoked");
        }

        if (err != nullptr) {
            *err = status;
        }
    }

    return;
}

#endif

// Methods
    /* close - Request that the platform move your app out of focus */
    void LifecycleImpl::close( const CloseReason& reason, Firebolt::Error *err ) 
    {
        Firebolt::Error status = Firebolt::Error::NotConnected;


        JsonObject jsonParameters;
        JsonData_CloseReason jsonReason = reason;
            WPEFramework::Core::JSON::Variant reasonVariant(jsonReason.Data());
            jsonParameters.Set(_T("reason"), reasonVariant);
        WPEFramework::Core::JSON::VariantContainer jsonResult;
        status = FireboltSDK::Gateway::Instance().Request("lifecycle.close", jsonParameters, jsonResult);
        if (status == Firebolt::Error::None) {
            FIREBOLT_LOG_INFO(FireboltSDK::Logger::Category::OpenRPC, FireboltSDK::Logger::Module<FireboltSDK::Accessor>(), "Lifecycle.close is successfully invoked");

        }

        if (err != nullptr) {
            *err = status;
        }

        return;
    }


// Events
    /* onBackground - Listen to the background event */
    static void onBackgroundInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            LifecycleEvent result;

            result.state = proxyResponse->State;
            result.previous = proxyResponse->Previous;
            if (proxyResponse->Source.IsSet()) {
                result.source = proxyResponse->Source;
            }

            proxyResponse.Release();

            ILifecycle::IOnBackgroundNotification& notifier = *(reinterpret_cast<ILifecycle::IOnBackgroundNotification*>(notification));
            notifier.onBackground(result);
        }
    }
    void LifecycleImpl::subscribe( ILifecycle::IOnBackgroundNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("lifecycle.onBackground");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Lifecycle::JsonData_LifecycleEvent>(eventName, jsonParameters, onBackgroundInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LifecycleImpl::unsubscribe( ILifecycle::IOnBackgroundNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("lifecycle.onBackground"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onForeground - Listen to the foreground event */
    static void onForegroundInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            LifecycleEvent result;

            result.state = proxyResponse->State;
            result.previous = proxyResponse->Previous;
            if (proxyResponse->Source.IsSet()) {
                result.source = proxyResponse->Source;
            }

            proxyResponse.Release();

            ILifecycle::IOnForegroundNotification& notifier = *(reinterpret_cast<ILifecycle::IOnForegroundNotification*>(notification));
            notifier.onForeground(result);
        }
    }
    void LifecycleImpl::subscribe( ILifecycle::IOnForegroundNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("lifecycle.onForeground");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Lifecycle::JsonData_LifecycleEvent>(eventName, jsonParameters, onForegroundInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LifecycleImpl::unsubscribe( ILifecycle::IOnForegroundNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("lifecycle.onForeground"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onInactive - Listen to the inactive event */
    static void onInactiveInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            LifecycleEvent result;

            result.state = proxyResponse->State;
            result.previous = proxyResponse->Previous;
            if (proxyResponse->Source.IsSet()) {
                result.source = proxyResponse->Source;
            }

            proxyResponse.Release();

            ILifecycle::IOnInactiveNotification& notifier = *(reinterpret_cast<ILifecycle::IOnInactiveNotification*>(notification));
            notifier.onInactive(result);
        }
    }
    void LifecycleImpl::subscribe( ILifecycle::IOnInactiveNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("lifecycle.onInactive");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Lifecycle::JsonData_LifecycleEvent>(eventName, jsonParameters, onInactiveInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LifecycleImpl::unsubscribe( ILifecycle::IOnInactiveNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("lifecycle.onInactive"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onSuspended - Listen to the suspended event */
    static void onSuspendedInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            LifecycleEvent result;

            result.state = proxyResponse->State;
            result.previous = proxyResponse->Previous;
            if (proxyResponse->Source.IsSet()) {
                result.source = proxyResponse->Source;
            }

            proxyResponse.Release();

            ILifecycle::IOnSuspendedNotification& notifier = *(reinterpret_cast<ILifecycle::IOnSuspendedNotification*>(notification));
            notifier.onSuspended(result);
        }
    }
    void LifecycleImpl::subscribe( ILifecycle::IOnSuspendedNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("lifecycle.onSuspended");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Lifecycle::JsonData_LifecycleEvent>(eventName, jsonParameters, onSuspendedInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LifecycleImpl::unsubscribe( ILifecycle::IOnSuspendedNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("lifecycle.onSuspended"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }



    /* onUnloading - Listen to the unloading event */
    static void onUnloadingInnerCallback( void* notification, const void* userData, void* jsonResponse )
    {
        WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>& proxyResponse = *(reinterpret_cast<WPEFramework::Core::ProxyType<Firebolt::Lifecycle::JsonData_LifecycleEvent>*>(jsonResponse));

        ASSERT(proxyResponse.IsValid() == true);

        if (proxyResponse.IsValid() == true) {
            LifecycleEvent result;

            result.state = proxyResponse->State;
            result.previous = proxyResponse->Previous;
            if (proxyResponse->Source.IsSet()) {
                result.source = proxyResponse->Source;
            }

            proxyResponse.Release();

            ILifecycle::IOnUnloadingNotification& notifier = *(reinterpret_cast<ILifecycle::IOnUnloadingNotification*>(notification));
            notifier.onUnloading(result);
        }
    }
    void LifecycleImpl::subscribe( ILifecycle::IOnUnloadingNotification& notification, Firebolt::Error *err )
    {
        const string eventName = _T("lifecycle.onUnloading");
        Firebolt::Error status = Firebolt::Error::None;

        JsonObject jsonParameters;

        status = FireboltSDK::Event::Instance().Subscribe<Firebolt::Lifecycle::JsonData_LifecycleEvent>(eventName, jsonParameters, onUnloadingInnerCallback, reinterpret_cast<void*>(&notification), nullptr);

        if (err != nullptr) {
            *err = status;
        }
    }
    void LifecycleImpl::unsubscribe( ILifecycle::IOnUnloadingNotification& notification, Firebolt::Error *err )
    {
        Firebolt::Error status = FireboltSDK::Event::Instance().Unsubscribe(_T("lifecycle.onUnloading"), reinterpret_cast<void*>(&notification));

        if (err != nullptr) {
            *err = status;
        }
    }




}//namespace Lifecycle
}


namespace WPEFramework {

    /* LifecycleEventSource The source of the lifecycle change. */
    ENUM_CONVERSION_BEGIN(Firebolt::Lifecycle::LifecycleEventSource)
        { Firebolt::Lifecycle::LifecycleEventSource::VOICE, _T("voice") },
        { Firebolt::Lifecycle::LifecycleEventSource::REMOTE, _T("remote") },
    ENUM_CONVERSION_END(Firebolt::Lifecycle::LifecycleEventSource)

}