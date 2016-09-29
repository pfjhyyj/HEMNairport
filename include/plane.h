#ifndef XXYY_PLANE_H_
#define XXYY_PLANE_H_

#include <cstdint>

namespace XXYY {

struct BasicPlane {
  public:
    BasicPlane(uint64_t the_arrive_time);
    uint64_t arrive_time;
    uint64_t id;

  private:
    static uint64_t id_count_;
};

// struct OilPlane : public BasicPlane {
//   public:
//     OilPlane(uint64_t the_arrive_time, uint64_t the_oil_left);

//   private:
//     static uint64_t id_count_;
// };

} // XXYY

#endif // XXYY_PLANE_H_
