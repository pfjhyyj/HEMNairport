#include "green_queue.h"

using XXYY::GreenQueue;
using XXYY::WaitingQueue;

GreenQueue::GreenQueue(
    double comming_rate, double leaving_rate, size_t queue_max_size)
    : WaitingQueue(comming_rate, leaving_rate, queue_max_size) {}

XXYY::WaitingQueue::Pointer GreenQueue::NewQueue(
    double comming_rate, double leaving_rate, size_t queue_max_size) {
    return Pointer(new GreenQueue(comming_rate, leaving_rate, queue_max_size));
}

bool GreenQueue::Land() {
    if (comming_queue_.empty())
        return false;
    // TODO: log landing
    comming_queue_.pop();
}

void GreenQueue::PrepareComing() {
    auto coming_num = random_helper_.GetComming();
    for (; coming_num--; ) {
        if (comming_queue_.size() == QueueMaxSize()) {
            // TODO: log rejection
        } else {
            comming_queue_.push(PlaneFactory::NewBasicPlane(Clock()));
            // TODO: log ready
        }
    }
}
