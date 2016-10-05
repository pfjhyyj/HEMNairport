#include "airport.h"

using XXYY::Airport;

void Airport::run(uint64_t time) {
    for (; time--;) {
        waiting_queue_->Prepare();
        runway_field_->Run(waiting_queue_);
    }
}
