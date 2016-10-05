#ifndef XXYY_WAITING_QUEUE_H_
#define XXYY_WAITING_QUEUE_H_

#include "logger.h"
#include "plane.h"
#include "random_helper.h"
#include <cstdint>
#include <memory>
#include <queue>

namespace XXYY {

/**
 * base class for queue.
 */
class WaitingQueue {
  public:
    /**
     * both queue use the same leaving queue
     */
    using LeavingQueue = std::queue<BasicPlane>;

    /**
     * pointer for polymorphism
     */
    using Pointer = std::shared_ptr<WaitingQueue>;

    /**
     * private
     * @param comming_rate the initial comming rate
     * @param leaving_rate the initial leaving rate
     * @param queue_max_size the max planes two queues can contain respectively
     */
    WaitingQueue(
        double comming_rate, double leaving_rate, size_t queue_max_size);

    /**
     * instruct a plane to take off
     * @return true if a plane take off, false if the queue is empty
     */
    virtual bool TakeOff();

    /**
     * instruct a plane to land
     * @return true if a plane land successfully, false if queue is empty
     */
    virtual bool Land() = 0;

    /**
     * preperation for the queue, including pushing random planes to the queue,
     * update time etc.
     */
    void Prepare();

    /**
     * getter for comming rate
     * @return the current comming rate
     */
    double CommingRate() const;

    /**
     * setter for commint rate
     * @param  comming_rate the comming_rate to set
     * @return              true if set successfully, false if fail
     */
    bool CommingRate(double comming_rate);

    /**
     * getter for leaving rate
     * @return the current leaving rate
     */
    double LeavingRate() const;

    /**
     * setter for leaving rate
     * @param  leaving_rate the leaving rate to set
     * @return              true if set successfully, false if fail
     */
    bool LeavingRate(double leaving_rate);

    /**
     * get current time
     * @return the current time since the queue is created
     */
    uint64_t Clock() const;

    /**
     * getter for max size for queue
     * @return the maximum planes allowed in each queue
     */
    uint64_t QueueMaxSize() const;

  protected:
    /**
     * logger for recording message when order's taken
     */
    Logger logger;

    /**
     * the helper to generate the comming planes and leaving planes every turn
     */
    RandomHelper random_helper_;

    /**
     * push random planes to the comming queue
     */
    virtual void PrepareComing() = 0;

  private:
    /**
     * max size of the queue on the land and the queue in the air
     */
    size_t queue_max_size_;

    /**
     * push random planes to the leaving queue
     */
    void PrepareLeaving();

    /**
     * the time pass since start
     */
    uint64_t clock_;

    /**
     * the queue for the plane that are ready to take off
     */
    LeavingQueue leaving_queue_;
};

} // XXYY

#endif // XXYY_WAITING_QUEUE_H_