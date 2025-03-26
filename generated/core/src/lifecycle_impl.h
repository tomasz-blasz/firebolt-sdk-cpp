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
#pragma once

#include "FireboltSDK.h"
#include "IModule.h"
#include "firebolt.h"
#include "jsondata_lifecycle.h"
#include "lifecycle.h"

#include "jsondata_lifecycle.h"


namespace Firebolt {
namespace Lifecycle {

#ifdef GATEWAY_BIDIRECTIONAL
#warning "to be defined when spec ready, some part could be common for UNI-DIRECTIONAL and BI-DIRECTIONAL"



    using JsonData_LifecycleEventSource = WPEFramework::Core::JSON::EnumType<LifecycleEventSource>;


// Types
    class JsonData_LifecycleEvent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_LifecycleEvent() override = default;
  
    public:
        JsonData_LifecycleEvent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("state"), &State);
            Add(_T("previous"), &Previous);
            Add(_T("source"), &Source);
        }

        JsonData_LifecycleEvent(const JsonData_LifecycleEvent& other)
        {
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("previous"), &Previous);
            Previous = other.Previous;
            Add(_T("source"), &Source);
            Source = other.Source;
        }

        JsonData_LifecycleEvent& operator=(const JsonData_LifecycleEvent& other)
        {
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("previous"), &Previous);
            Previous = other.Previous;
            Add(_T("source"), &Source);
            Source = other.Source;
            return (*this);
        }

    public:
        Firebolt::Lifecycle::JsonData_LifecycleState State;
        Firebolt::Lifecycle::JsonData_LifecycleState Previous;
        Firebolt::Lifecycle::JsonData_LifecycleEventSource Source;
    };

class LifecycleImpl : public ILifecycle, public IModule {

public:
    LifecycleImpl() = default;
    LifecycleImpl(const LifecycleImpl&) = delete;
    LifecycleImpl& operator=(const LifecycleImpl&) = delete;
    ~LifecycleImpl() override = default;

    std::string currentState = "INITIALIZING";

    // Methods & Events
        /*
         close
         Request that the platform move your app out of focus
         */
        void close( const CloseReason& reason, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnBackgroundNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnBackgroundNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnForegroundNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnForegroundNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnInactiveNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnInactiveNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnSuspendedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnSuspendedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnUnloadingNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnUnloadingNotification& notification, Firebolt::Error *err = nullptr ) override;


    void finished(Firebolt::Error *err = nullptr) override ;
    void ready(Firebolt::Error *err = nullptr) override;
    std::string state(Firebolt::Error *err = nullptr) override;

};

#else



    using JsonData_LifecycleEventSource = WPEFramework::Core::JSON::EnumType<LifecycleEventSource>;


// Types
    class JsonData_LifecycleEvent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_LifecycleEvent() override = default;
  
    public:
        JsonData_LifecycleEvent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("state"), &State);
            Add(_T("previous"), &Previous);
            Add(_T("source"), &Source);
        }

        JsonData_LifecycleEvent(const JsonData_LifecycleEvent& other)
        {
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("previous"), &Previous);
            Previous = other.Previous;
            Add(_T("source"), &Source);
            Source = other.Source;
        }

        JsonData_LifecycleEvent& operator=(const JsonData_LifecycleEvent& other)
        {
            Add(_T("state"), &State);
            State = other.State;
            Add(_T("previous"), &Previous);
            Previous = other.Previous;
            Add(_T("source"), &Source);
            Source = other.Source;
            return (*this);
        }

    public:
        Firebolt::Lifecycle::JsonData_LifecycleState State;
        Firebolt::Lifecycle::JsonData_LifecycleState Previous;
        Firebolt::Lifecycle::JsonData_LifecycleEventSource Source;
    };

class LifecycleImpl : public ILifecycle, public IModule {

public:
    LifecycleImpl() = default;
    LifecycleImpl(const LifecycleImpl&) = delete;
    LifecycleImpl& operator=(const LifecycleImpl&) = delete;
    ~LifecycleImpl() override = default;

    std::string currentState = "INITIALIZING";

    // Methods & Events
        /*
         close
         Request that the platform move your app out of focus
         */
        void close( const CloseReason& reason, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnBackgroundNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnBackgroundNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnForegroundNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnForegroundNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnInactiveNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnInactiveNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnSuspendedNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnSuspendedNotification& notification, Firebolt::Error *err = nullptr ) override;

        // signature callback params: 
        // method result properties : 
        void subscribe( ILifecycle::IOnUnloadingNotification& notification, Firebolt::Error *err = nullptr ) override;
        void unsubscribe( ILifecycle::IOnUnloadingNotification& notification, Firebolt::Error *err = nullptr ) override;


    void finished(Firebolt::Error *err = nullptr) override ;
    void ready(Firebolt::Error *err = nullptr) override;
    std::string state(Firebolt::Error *err = nullptr) override;
 
};

#endif

} // namespace Lifecycle
} // namespace Firebolt
