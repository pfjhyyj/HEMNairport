#include "green_queue.h"

using XXYY::GreenQueue;
using XXYY::WaitingQueue;

GreenQueue::GreenQueue(
    double comming_rate, double leaving_rate, size_t queue_max_size)
    : WaitingQueue(comming_rate, leaving_rate, queue_max_size) {}

WaitingQueue::Pointer GreenQueue::NewQueue(
    double comming_rate, double leaving_rate, size_t queue_max_size) {
    return Pointer(new GreenQueue(comming_rate, leaving_rate, queue_max_size));
}

bool GreenQueue::Land() {
    if (comming_queue_.empty()) {
        return false;
    }
    auto cur_plane = comming_queue_.front();
    logger.Land(cur_plane, Clock());
    comming_queue_.pop();
    return true;
}

void GreenQueue::PrepareComing() {
    auto coming_num = random_helper_.GetComming();
    for (; coming_num--;) {
        if (comming_queue_.size() == QueueMaxSize()) {
            logger.Reject(PlaneFactory::NewBasicPlane(Clock()));
        } else {
            auto new_plane = PlaneFactory::NewBasicPlane(Clock());
            comming_queue_.push(new_plane);
            logger.ReadyToLand(new_plane);
        }
    }
}
