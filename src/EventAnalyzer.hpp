#ifndef EVENT_ANALYZER_HPP
#define EVENT_ANALYZER_HPP

#include <metavision/sdk/stream/camera.h>
#include <metavision/sdk/base/events/event_cd.h>
#include <metavision/sdk/core/algorithms/periodic_frame_generation_algorithm.h>
#include "metavision/sdk/ui/utils/window.h"
#include "metavision/sdk/core/utils/cd_frame_generator.h"
#include <metavision/sdk/ui/utils/event_loop.h>

// this class will be used to analyze the events
class EventAnalyzer {
public:
    // class variables to store global information
    int callback_counter               = 0; // this will track the number of callbacks
    int global_counter                 = 0; // this will track how many events we processed
    Metavision::timestamp global_max_t = 0; // this will track the highest timestamp we processed

    void analyze_events(const Metavision::EventCD *begin, const Metavision::EventCD *end);
};

#endif // EVENT_ANALYZER_HPP