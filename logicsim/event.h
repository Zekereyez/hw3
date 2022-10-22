#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    //write the operator() required to make this a functor that compares Events by time
    bool operator()(Event* event1, Event* event2) {
        // events are sorted by time and we need to check if the 
        // times of the events are less than ie min heap
        if (event1->time < event2->time) {
            return true;
        }
        // if times are equal doesnt matter which order 
        // if greater time then returns false
        return false;
    }
} EventLess;
	
#endif
