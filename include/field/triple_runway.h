#ifndef XXYY_FIELD_TRIPLE_RUNWAY_H_
#define XXYY_FIELD_TRIPLE_RUNWAY_H_

#include "runway_field.h"

namespace XXYY {

class TripleRunway : public RunwayField {
  public:
    virtual void Run(WaitingQueue::Pointer queue) override;
};

} // XXYY

#endif // XXYY_FIELD_TRIPLE_RUNWAY_H_
