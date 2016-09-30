#include "field/triple_runway.h"

using XXYY::TripleRunway;

void TripleRunway::Run(XXYY::WaitingQueue::Pointer queue) {
    queue->TakeOff();
    queue->Land();
    if (not queue->Land()) {
        queue->TakeOff();
    }
}
