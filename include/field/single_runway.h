#ifndef XYYY_FIELD_SINGLE_RUNWAY_H_
#define XYYY_FIELD_SINGLE_RUNWAY_H_

#include "runway_field.h"

namespace XXYY {

class SingleRunway : public RunwayField {
  public:
    virtual void Run(WaitingQueue::Pointer queue) override;
};

} // XXYY

#endif // XYYY_FIELD_SINGLE_RUNWAY_H_
