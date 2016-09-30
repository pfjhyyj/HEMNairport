#ifndef XXYY_PLANE_H_
#define XXYY_PLANE_H_

#include <cstdint>

namespace XXYY {

struct BasicPlane {
  public:
    /**
     * make constructor available for plane factory
     */
    friend class PlaneFactory;

    /**
     * the time when the plane arrive the airport waiting for taking off or
     * landing
     */
    uint64_t arrive_time;

    /**
     * id specify the plane
     */
    uint64_t id;

  private:
    /**
     * constructor available only for plane factory
     * @param the_arrive_time the time when the plane arrive the airport
     */
    BasicPlane(uint64_t the_arrive_time, uint64_t the_id);
};

struct OilPlane : public BasicPlane {
  public:
    OilPlane(uint64_t the_arrive_time, uint64_t the_oil_left);

  private:
    static uint64_t id_count_;
    uint64_t oil_;
};

class PlaneFactory {
  public:
    /**
     * factory to create the basic plane
     * @param arrive_time the time when the plane arrive the airport
     * @return the plane created
     */
    static BasicPlane NewBasicPlane(uint64_t arrive_time);

  private:
    static uint64_t id_count_;
};

} // XXYY

#endif // XXYY_PLANE_H_
