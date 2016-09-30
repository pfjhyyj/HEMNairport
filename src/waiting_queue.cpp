#include "waiting_queue.h"

using XXYY::WaitingQueue;

WaitingQueue::WaitingQueue(
    double comming_rate, double leaving_rate, size_t queue_max_size)
    : random_helper_(comming_rate, leaving_rate), current_time_(0),
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





