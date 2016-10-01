#include "random_helper.h"
#include <ctime>

using XXYY::RandomHelper;

RandomHelper::RandomHelper(
    double comming_rate, double leaving_rate, int64_t seed)
    : comming_(comming_rate), leaving_(leaving_rate), random_engine_(seed){}

uint64_t RandomHelper::GetComming() {
    return comming_(random_engine_);
}

uint64_t RandomHelper::GetLeaving() {
    return leaving_(random_engine_);
}

double RandomHelper::CommingRate() const {
    return comming_.mean();
}

double RandomHelper::LeavingRate() const {
    return leaving_.mean();
}

bool RandomHelper::CommingRate(double comming_rate_) {
    if (comming_rate_ < 0)
        return false;
    comming_ = std::poisson_distribution<uint64_t> (comming_rate_);
    return true;
}

bool RandomHelper::LeavingRate(double leaving_rate_) {
    if (leaving_rate_ < 0)
        return false;
    leaving_ = std::poisson_distribution<uint64_t> (leaving_rate_);
}

