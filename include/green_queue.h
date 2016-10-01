#ifndef XXYY_GREEN_QUEUE_H_
#define XXYY_GREEN_QUEUE_H_

#include "plane.h"
#include "waiting_queue.h"
#include <queue>

namespace XXYY {

/**
 * the queue for planes that don't consume oil
 */
class GreenQueue : public WaitingQueue {
  public:
    /**
     * planes wait according to the order they come
     */
    using CommingQueue = std::queue<BasicPlane>;

    /**
     * factory method create a green queue according to comming rate and leaving
     * rate
     * @param  comming_rate the initial expectation of the number of planes
     * ready to land each unit of time
     * @param  leaving_rate the initial expectation of the number of planes
     * ready to take off each unit of time
     * @param queue_max_size the max planes two queues can contain respectively
     * @return              the pointer point to the new queue
     */
    static Pointer
    NewQueue(double comming_rate, double leaving_rate, size_t queue_max_size);

    /**
     * instruct a plane to land
     * @return true if a plane land successfully, false if queue is empty
     */
    virtual bool Land() override;

  private:
    /**
     * private constructor used in the factory method
     * @param comming_rate the initial comming rate
     * @param leaving_rate the initial leaving rate
     * @queue_max_size the max planes two queues can contain respectively
     */
    GreenQueue(double comming_rate, double leaving_rate, size_t queue_max_size);

    /**
     * push random planes to the comming queue
     */
    virtual void PrepareComing() override;

    /**
     * the queue for the plane that are ready to land
     */
    CommingQueue comming_queue_;
};

} // XXYY

#endif // XXYY_GREEN_QUEUE_H_
