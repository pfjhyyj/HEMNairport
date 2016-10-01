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
    // TODO: do logging
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
            // TODO: log rejection
        } else {
            leaving_queue_.push(PlaneFactory::NewBasicPlane(clock_));
            // TODO: log ready
        }
    }
}

uint64_t WaitingQueue::Clock() const {
    return clock_;
}

uint64_t WaitingQueue::QueueMaxSize() const {
    return queue_max_size_;
}





