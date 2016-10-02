#include "waiting_queue.h"

using XXYY::WaitingQueue;

WaitingQueue::WaitingQueue(
    double comming_rate, double leaving_rate, size_t queue_max_size)
    : random_helper_(comming_rate, leaving_rate), clock_(0),
      queue_max_size_(queue_max_size) {}

double WaitingQueue::CommingRate() const {
    return random_helper_.CommingRate();
}

bool WaitingQueue::CommingRate(double comming_rate) {
    return random_helper_.CommingRate(comming_rate);
}

double WaitingQueue::LeavingRate() const {
    return random_helper_.LeavingRate();
}

bool WaitingQueue::LeavingRate(double leaving_rate) {
    return random_helper_.LeavingRate(leaving_rate);
}

bool WaitingQueue::TakeOff() {
    if (leaving_queue_.empty())
        return false;
    auto cur_plane = leaving_queue_.front();
    logger.TakeOff(cur_plane, Clock()-cur_plane.arrive_time);
    leaving_queue_.pop();
}

void WaitingQueue::prepare() {
    ++clock_;
    PrepareLeaving();
    PrepareComing();
}

void WaitingQueue::PrepareLeaving() {
    auto leaving_num = random_helper_.GetLeaving();
    for (; leaving_num--; ) {
        if (leaving_queue_.size() == queue_max_size_) {
            logger.Reject(PlaneFactory::NewBasicPlane(clock_));
        } else {
        	auto new_plane = PlaneFactory::NewBasicPlane(clock_);
            leaving_queue_.push(new_plane);
            logger.ReadyToTakeOff(new_plane);
        }
    }
}

uint64_t WaitingQueue::Clock() const {
    return clock_;
}

uint64_t WaitingQueue::QueueMaxSize() const {
    return queue_max_size_;
}





