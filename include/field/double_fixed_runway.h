#ifndef XXYY_FIELD_DOUBLE_FIXED_RUNWAY_H_
#define XXYY_FIELD_DOUBLE_FIXED_RUNWAY_H_

#include "runway_field.h"

namespace XXYY {

class DoubleFixedRunway : public RunwayField {
  public:
    virtual void Run(WaitingQueue::Pointer queue) override;
};

} // XXYY

#endif // XXYY_FIELD_DOUBLE_FIXED_RUNWAY_H_
