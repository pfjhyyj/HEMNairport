#include "plane.h"

using XXYY::BasicPlane;
using XXYY::PlaneFactory;

uint64_t PlaneFactory::id_count_ = 0;

BasicPlane PlaneFactory::NewBasicPlane(uint64_t arrive_time) {
    return BasicPlane(arrive_time, id_count_++);
}

BasicPlane::BasicPlane(uint64_t the_arrive_time, uint64_t the_id)
    : arrive_time(the_arrive_time), id(the_id) {}
