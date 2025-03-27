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
#include "jsondata_entity.h"
#include "jsondata_entertainment.h"
#include "common/intents.h"

namespace Firebolt {
namespace Intents {

    // Types
    class JsonData_IntentContext: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_IntentContext() override = default;
  
    public:
        JsonData_IntentContext()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("source"), &Source);
        }

        JsonData_IntentContext(const JsonData_IntentContext& other)
        {
            Add(_T("source"), &Source);
            Source = other.Source;
        }

        JsonData_IntentContext& operator=(const JsonData_IntentContext& other)
        {
            Add(_T("source"), &Source);
            Source = other.Source;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Source;
    };

    class JsonData_Intent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_Intent() override = default;
  
    public:
        JsonData_Intent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("context"), &Context);
        }

        JsonData_Intent(const JsonData_Intent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_Intent& operator=(const JsonData_Intent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_HomeIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_HomeIntent() override = default;
  
    public:
        JsonData_HomeIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("context"), &Context);
        }

        JsonData_HomeIntent(const JsonData_HomeIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_HomeIntent& operator=(const JsonData_HomeIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_EntityIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_EntityIntent() override = default;
  
    public:
        JsonData_EntityIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("data"), &Data);
            Add(_T("context"), &Context);
        }

        JsonData_EntityIntent(const JsonData_EntityIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_EntityIntent& operator=(const JsonData_EntityIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        FireboltSDK::JSON::String Data;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_TuneIntentDataOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_TuneIntentDataOptions() override = default;
  
    public:
        JsonData_TuneIntentDataOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("assetId"), &AssetId);
            Add(_T("restartCurrentProgram"), &RestartCurrentProgram);
            Add(_T("time"), &Time);
        }

        JsonData_TuneIntentDataOptions(const JsonData_TuneIntentDataOptions& other)
        {
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("restartCurrentProgram"), &RestartCurrentProgram);
            RestartCurrentProgram = other.RestartCurrentProgram;
            Add(_T("time"), &Time);
            Time = other.Time;
        }

        JsonData_TuneIntentDataOptions& operator=(const JsonData_TuneIntentDataOptions& other)
        {
            Add(_T("assetId"), &AssetId);
            AssetId = other.AssetId;
            Add(_T("restartCurrentProgram"), &RestartCurrentProgram);
            RestartCurrentProgram = other.RestartCurrentProgram;
            Add(_T("time"), &Time);
            Time = other.Time;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String AssetId;
        WPEFramework::Core::JSON::Boolean RestartCurrentProgram;
        FireboltSDK::JSON::String Time;
    };

    class JsonData_PlaybackIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlaybackIntent() override = default;
  
    public:
        JsonData_PlaybackIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("data"), &Data);
            Add(_T("context"), &Context);
        }

        JsonData_PlaybackIntent(const JsonData_PlaybackIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_PlaybackIntent& operator=(const JsonData_PlaybackIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        FireboltSDK::JSON::String Data;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_SearchIntentData: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_SearchIntentData() override = default;
  
    public:
        JsonData_SearchIntentData()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("query"), &Query);
        }

        JsonData_SearchIntentData(const JsonData_SearchIntentData& other)
        {
            Add(_T("query"), &Query);
            Query = other.Query;
        }

        JsonData_SearchIntentData& operator=(const JsonData_SearchIntentData& other)
        {
            Add(_T("query"), &Query);
            Query = other.Query;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Query;
    };

    class JsonData_SectionIntentData: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_SectionIntentData() override = default;
  
    public:
        JsonData_SectionIntentData()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("sectionName"), &SectionName);
        }

        JsonData_SectionIntentData(const JsonData_SectionIntentData& other)
        {
            Add(_T("sectionName"), &SectionName);
            SectionName = other.SectionName;
        }

        JsonData_SectionIntentData& operator=(const JsonData_SectionIntentData& other)
        {
            Add(_T("sectionName"), &SectionName);
            SectionName = other.SectionName;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String SectionName;
    };

    class JsonData_PlayEntityIntentDataOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlayEntityIntentDataOptions() override = default;
  
    public:
        JsonData_PlayEntityIntentDataOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("playFirstId"), &PlayFirstId);
            Add(_T("playFirstTrack"), &PlayFirstTrack);
        }

        JsonData_PlayEntityIntentDataOptions(const JsonData_PlayEntityIntentDataOptions& other)
        {
            Add(_T("playFirstId"), &PlayFirstId);
            PlayFirstId = other.PlayFirstId;
            Add(_T("playFirstTrack"), &PlayFirstTrack);
            PlayFirstTrack = other.PlayFirstTrack;
        }

        JsonData_PlayEntityIntentDataOptions& operator=(const JsonData_PlayEntityIntentDataOptions& other)
        {
            Add(_T("playFirstId"), &PlayFirstId);
            PlayFirstId = other.PlayFirstId;
            Add(_T("playFirstTrack"), &PlayFirstTrack);
            PlayFirstTrack = other.PlayFirstTrack;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String PlayFirstId;
        WPEFramework::Core::JSON::DecSInt32 PlayFirstTrack;
    };

    class JsonData_PlayQueryIntentDataOptions: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlayQueryIntentDataOptions() override = default;
  
    public:
        JsonData_PlayQueryIntentDataOptions()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("programTypes"), &ProgramTypes);
            Add(_T("musicTypes"), &MusicTypes);
        }

        JsonData_PlayQueryIntentDataOptions(const JsonData_PlayQueryIntentDataOptions& other)
        {
            Add(_T("programTypes"), &ProgramTypes);
            ProgramTypes = other.ProgramTypes;
            Add(_T("musicTypes"), &MusicTypes);
            MusicTypes = other.MusicTypes;
        }

        JsonData_PlayQueryIntentDataOptions& operator=(const JsonData_PlayQueryIntentDataOptions& other)
        {
            Add(_T("programTypes"), &ProgramTypes);
            ProgramTypes = other.ProgramTypes;
            Add(_T("musicTypes"), &MusicTypes);
            MusicTypes = other.MusicTypes;
            return (*this);
        }

    public:
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_ProgramType> ProgramTypes;
        WPEFramework::Core::JSON::ArrayType<Firebolt::Entertainment::JsonData_MusicType> MusicTypes;
    };

    class JsonData_LaunchIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_LaunchIntent() override = default;
  
    public:
        JsonData_LaunchIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("context"), &Context);
        }

        JsonData_LaunchIntent(const JsonData_LaunchIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_LaunchIntent& operator=(const JsonData_LaunchIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_TuneIntentData: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_TuneIntentData() override = default;
  
    public:
        JsonData_TuneIntentData()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entity"), &Entity);
            Add(_T("options"), &Options);
        }

        JsonData_TuneIntentData(const JsonData_TuneIntentData& other)
        {
            Add(_T("entity"), &Entity);
            Entity = other.Entity;
            Add(_T("options"), &Options);
            Options = other.Options;
        }

        JsonData_TuneIntentData& operator=(const JsonData_TuneIntentData& other)
        {
            Add(_T("entity"), &Entity);
            Entity = other.Entity;
            Add(_T("options"), &Options);
            Options = other.Options;
            return (*this);
        }

    public:
        Firebolt::Entity::JsonData_ChannelEntity Entity;
        Firebolt::Intents::JsonData_TuneIntentDataOptions Options;
    };

    class JsonData_SearchIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_SearchIntent() override = default;
  
    public:
        JsonData_SearchIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("data"), &Data);
            Add(_T("context"), &Context);
        }

        JsonData_SearchIntent(const JsonData_SearchIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_SearchIntent& operator=(const JsonData_SearchIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_SearchIntentData Data;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_SectionIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_SectionIntent() override = default;
  
    public:
        JsonData_SectionIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("data"), &Data);
            Add(_T("context"), &Context);
        }

        JsonData_SectionIntent(const JsonData_SectionIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_SectionIntent& operator=(const JsonData_SectionIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_SectionIntentData Data;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_PlayEntityIntentData: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlayEntityIntentData() override = default;
  
    public:
        JsonData_PlayEntityIntentData()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("entity"), &Entity);
            Add(_T("options"), &Options);
        }

        JsonData_PlayEntityIntentData(const JsonData_PlayEntityIntentData& other)
        {
            Add(_T("entity"), &Entity);
            Entity = other.Entity;
            Add(_T("options"), &Options);
            Options = other.Options;
        }

        JsonData_PlayEntityIntentData& operator=(const JsonData_PlayEntityIntentData& other)
        {
            Add(_T("entity"), &Entity);
            Entity = other.Entity;
            Add(_T("options"), &Options);
            Options = other.Options;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Entity;
        Firebolt::Intents::JsonData_PlayEntityIntentDataOptions Options;
    };

    class JsonData_PlayQueryIntentData: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlayQueryIntentData() override = default;
  
    public:
        JsonData_PlayQueryIntentData()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("query"), &Query);
            Add(_T("options"), &Options);
        }

        JsonData_PlayQueryIntentData(const JsonData_PlayQueryIntentData& other)
        {
            Add(_T("query"), &Query);
            Query = other.Query;
            Add(_T("options"), &Options);
            Options = other.Options;
        }

        JsonData_PlayQueryIntentData& operator=(const JsonData_PlayQueryIntentData& other)
        {
            Add(_T("query"), &Query);
            Query = other.Query;
            Add(_T("options"), &Options);
            Options = other.Options;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Query;
        Firebolt::Intents::JsonData_PlayQueryIntentDataOptions Options;
    };

    class JsonData_TuneIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_TuneIntent() override = default;
  
    public:
        JsonData_TuneIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("data"), &Data);
            Add(_T("context"), &Context);
        }

        JsonData_TuneIntent(const JsonData_TuneIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_TuneIntent& operator=(const JsonData_TuneIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_TuneIntentData Data;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_PlayEntityIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlayEntityIntent() override = default;
  
    public:
        JsonData_PlayEntityIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("data"), &Data);
            Add(_T("context"), &Context);
        }

        JsonData_PlayEntityIntent(const JsonData_PlayEntityIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_PlayEntityIntent& operator=(const JsonData_PlayEntityIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_PlayEntityIntentData Data;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    class JsonData_PlayQueryIntent: public WPEFramework::Core::JSON::Container {
    public:
        ~JsonData_PlayQueryIntent() override = default;
  
    public:
        JsonData_PlayQueryIntent()
            : WPEFramework::Core::JSON::Container()
        {
            Add(_T("action"), &Action);
            Add(_T("data"), &Data);
            Add(_T("context"), &Context);
        }

        JsonData_PlayQueryIntent(const JsonData_PlayQueryIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
        }

        JsonData_PlayQueryIntent& operator=(const JsonData_PlayQueryIntent& other)
        {
            Add(_T("action"), &Action);
            Action = other.Action;
            Add(_T("data"), &Data);
            Data = other.Data;
            Add(_T("context"), &Context);
            Context = other.Context;
            return (*this);
        }

    public:
        FireboltSDK::JSON::String Action;
        Firebolt::Intents::JsonData_PlayQueryIntentData Data;
        Firebolt::Intents::JsonData_IntentContext Context;
    };

    /* anyOf schema shape is not supported right now */
}
}
