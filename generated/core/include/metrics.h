#pragma once

#include "error.h"
#include "common/types.h"
#include "common/types.h"

namespace Firebolt {
namespace Metrics {


// Enums
/* ErrorType  */
enum class ErrorType {
    NETWORK,
    MEDIA,
    RESTRICTION,
    ENTITLEMENT,
    OTHER
};

/* Category  */
enum class Category {
    USER,
    APP
};


// Types
using MediaPosition = std::string;
/* anyOf schema shape is not supported right now */


struct IMetrics {

    virtual ~IMetrics() = default;
    virtual bool ready( Firebolt::Error *err = nullptr ) = 0 ;
    virtual bool signIn( Firebolt::Error *err = nullptr ) = 0 ;
    virtual bool signOut( Firebolt::Error *err = nullptr ) = 0 ;

    // Methods & Events
    /*
     action
     Inform the platform of something not covered by other Metrics APIs.
     
     */
    virtual bool action( const Category& category, const std::string& type, const std::optional<Types::FlatMap>& parameters, Firebolt::Error *err = nullptr ) = 0;
    /*
     error
     Inform the platform of an error that has occured in your app.
     
     */
    virtual bool error( const ErrorType& type, const std::string& code, const std::string& description, const bool visible, const std::optional<Types::FlatMap>& parameters, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaEnded
     Called when playback has stopped because the end of the media was reached.
     
     */
    virtual bool mediaEnded( const std::string& entityId, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaLoadStart
     Called when setting the URL of a media asset to play, in order to infer load time.
     
     */
    virtual bool mediaLoadStart( const std::string& entityId, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaPause
     Called when media playback will pause due to an intentional pause operation.
     
     */
    virtual bool mediaPause( const std::string& entityId, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaPlay
     Called when media playback should start due to autoplay, user-initiated play, or unpausing.
     
     */
    virtual bool mediaPlay( const std::string& entityId, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaPlaying
     Called when media playback actually starts due to autoplay, user-initiated play, unpausing, or recovering from a buffering interuption.
     
     */
    virtual bool mediaPlaying( const std::string& entityId, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaProgress
     Called every 60 seconds as media playback progresses.
     
     */
    virtual bool mediaProgress( const std::string& entityId, const std::string& progress, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaRateChange
     Called when the playback rate of media is changed.
     
     */
    virtual bool mediaRateChange( const std::string& entityId, const float rate, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaRenditionChange
     Called when the playback rendition (e.g. bitrate, dimensions, profile, etc) is changed.
     
     */
    virtual bool mediaRenditionChange( const std::string& entityId, const float bitrate, const float width, const float height, const std::optional<std::string>& profile, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaSeeked
     Called when a seek is completed during media playback.
     
     */
    virtual bool mediaSeeked( const std::string& entityId, const std::string& position, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaSeeking
     Called when a seek is initiated during media playback.
     
     */
    virtual bool mediaSeeking( const std::string& entityId, const std::string& target, Firebolt::Error *err = nullptr ) = 0;
    /*
     mediaWaiting
     Called when media playback will halt due to a network, buffer, or other unintentional constraint.
     
     */
    virtual bool mediaWaiting( const std::string& entityId, Firebolt::Error *err = nullptr ) = 0;
    /*
     page
     Inform the platform that your user has navigated to a page or view.
     
     */
    virtual bool page( const std::string& pageId, Firebolt::Error *err = nullptr ) = 0;
    /*
     startContent
     Inform the platform that your user has started content.
     
     */
    virtual bool startContent( const std::optional<std::string>& entityId, Firebolt::Error *err = nullptr ) = 0;
    /*
     stopContent
     Inform the platform that your user has stopped content.
     
     */
    virtual bool stopContent( const std::optional<std::string>& entityId, Firebolt::Error *err = nullptr ) = 0;
};

} //namespace Metrics
}





    
   

