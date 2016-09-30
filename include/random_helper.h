#ifndef XXYY_RANDOM_HELPER_H_
#define XXYY_RANDOM_HELPER_H_

#include <cstdint>
#include <random>
#include <ctime>

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
    RandomHelper(
        double comming_rate, double leaving_rate, int64_t seed = std::time(
        nullptr));

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

    /**
     * getter for comming rate
     * @return the mean of the comming poisson distribution
     */
    double CommingRate() const;

    /**
     * getter for leaving rate
     * @return the mean of the leaving poisson distribution
     */
    double LeavingRate() const;

    /**
     * setter for comming rate
     * @param comming_rate_ the comming rate to set
     * @return true if set successfully, false otherwise
     */
    bool CommingRate(double comming_rate_);

    /**
     * setter for leaving rate
     * @param leaving_rate_ the leaving rate to set
     * @return true if set successfully, false otherwise
     */
    bool LeavingRate(double leaving_rate_);

  private:
    /**
     * the random generator for comming
     */
    std::poisson_distribution<uint64_t> comming_;

    /**
     * the random generator for leaving
     */
    std::poisson_distribution<uint64_t> leaving_;

    /**
     * pseudo random engine for poisson distribution
     */
    std::default_random_engine random_engine_;
};

} // XXYY

#endif // XXYY_RANDOM_HELPER_H_
