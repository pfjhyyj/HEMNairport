#ifndef XXYY_RUNWAY_FIELD_H_
#define XXYY_RUNWAY_FIELD_H_

#include "waiting_queue.h"
#include <memory>

namespace XXYY {

/**
 * base class for different strategies to manage the queue
 */
class RunwayField {
  public:
    /**
     * pointer for polymorphism
     */
    using Pointer = std::shared_ptr<RunwayField>;

    /**
     * do something with the queue based on the strategy
     * @param queue the waiting queue for planes
     */
    virtual void Run(WaitingQueue::Pointer queue) = 0;
};

} // XXYY

#endif // XXYY_RUNWAY_FIELD_H_
