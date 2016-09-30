#include "field/double_fixed_runway.h"

using XXYY::DoubleFixedRunway;

void DoubleFixedRunway::Run(XXYY::WaitingQueue::Pointer queue) {
    queue->Land();
    queue->TakeOff();
}
