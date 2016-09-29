#ifndef XXYY_RANDOM_HELPER_H_
#define XXYY_RANDOM_HELPER_H_

#include <cstdint>

namespace XXYY {

/**
 * helper class generating random number
 */
class RandomHelper {
  public:
    /**
     * specify the comming rate and leaving rate
     * @param comming_rate the comming rate
     * @param leaving_rate the leaving rate
     */
    RandomHelper(double comming_rate, double leaving_rate);

    /**
     * get a random number according to comming rate
     * @return the random number
     */
    uint64_t GetComming();

    /**
     * get a random number according to leaving rate
     * @return the random number
     */
    uint64_t GetLeaving();

  private:
    /**
     * the expectation of the number of planes ready to land each unit of time
     */
    double comming_rate_;

    /**
     * the expectation of the number of planes ready to take off each unit of
     * time
     */
    double leaving_rate_;
};

} // XXYY

#endif // XXYY_RANDOM_HELPER_H_
