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



