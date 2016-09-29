#ifndef XXYY_AIRPORT_H_
#define XXYY_AIRPORT_H_

#include "runway_field.h"
#include "waiting_queue.h"

namespace XXYY {

class Airport {
  public:
  private:
    /**
     * the strategy taken by the runway each turn
     */
    RunwayField::Pointer runway_field_;

    /**
     * the waiting queue in the air and on the land
     */
    WaitingQueue::Pointer waiting_queue_;
};

} // XXYY

#endif // XXYY_AIRPORT_H_
