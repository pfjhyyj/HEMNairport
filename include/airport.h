#ifndef XXYY_AIRPORT_H_
#define XXYY_AIRPORT_H_

#include "runway_field.h"
#include "waiting_queue.h"

namespace XXYY {

class Airport {
  public:

    /**
     * run the airport for time units of time
     * @param time the time airport run
     */
    void run(uint64_t time);
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
