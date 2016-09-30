#include "field/double_flexible_runway.h"

using XXYY::DoubleFlexibleRunway;

void DoubleFlexibleRunway::Run(XXYY::WaitingQueue::Pointer queue) {
    if (not queue->TakeOff()) {
        queue->Land();
    }
    if (not queue->Land()) {
        queue->TakeOff();
    }
}
