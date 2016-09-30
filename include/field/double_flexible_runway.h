#ifndef XXYY_FIELD_DOUBLE_FLEXIBLE_RUNWAY_H_
#define XXYY_FIELD_DOUBLE_FLEXIBLE_RUNWAY_H_

#include "runway_field.h"

namespace XXYY {

class DoubleFlexibleRunway : public RunwayField {
  public:
    virtual void Run(WaitingQueue::Pointer queue) override;
};

} // XXYY

#endif // XXYY_FIELD_DOUBLE_FLEXIBLE_RUNWAY_H_
