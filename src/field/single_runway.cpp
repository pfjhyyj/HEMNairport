#include "field/single_runway.h"

using XXYY::SingleRunway;

void SingleRunway::Run(WaitingQueue::Pointer queue) {
    if (not queue->Land()) {
        queue->TakeOff();
    }
}
