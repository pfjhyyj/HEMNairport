#include "runway_field.h"
#include "field/single_runway.h"
#include "field/double_flexible_runway.h"
#include "field/double_fixed_runway.h"
#include "field/triple_runway.h"

XXYY::RunwayField::Pointer
XXYY::RunwayField::NewField(XXYY::RunwayField::Scenery scenery) {
    if (scenery == Scenery::_1) {
        return Pointer(new SingleRunway());
    }
    if (scenery == Scenery::_2) {
        return Pointer(new DoubleFixedRunway());
    }
    if (scenery == Scenery::_3) {
        return Pointer(new DoubleFlexibleRunway());
    }
    if (scenery == Scenery::_4) {
        return Pointer(new TripleRunway());
    }
    return nullptr;
}
