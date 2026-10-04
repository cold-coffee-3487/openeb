#include "EventAnalyzer.hpp"

// this function will be associated to the camera callback
// it is used to compute statistics on the received events
void EventAnalyzer::analyze_events(const Metavision::EventCD *begin, const Metavision::EventCD *end) {
    // time analysis
    // Note: events are ordered by timestamp in the callback, so the first event will have the lowest timestamp and
    // the last event will have the highest timestamp
    Metavision::timestamp min_t = begin->t;     // get the timestamp of the first event of this callback
    Metavision::timestamp max_t = (end - 1)->t; // get the timestamp of the last event of this callback
    global_max_t = max_t; // events are ordered by timestamp, so the current last event has the highest timestamp

    // counting analysis
    int counter = 0;
    for (const Metavision::EventCD *ev = begin; ev != end; ++ev) {
        ++counter; // increasing local counter
    }
    global_counter += counter; // increase global counter

    // Uncomment next line to display the buffer report in the terminal
    // WARNING : logging in the terminal can drastically decrease the performances of your application, especially
    // on embedded platforms with low computational power
//        std::cout << "Cb n°" << callback_counter << ": " << counter << " events from t=" << min_t << " to t="
//                  << max_t << " us." << std::endl;

    // increment callbacks counter
    callback_counter++;
}