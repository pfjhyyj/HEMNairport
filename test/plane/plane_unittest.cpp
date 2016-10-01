#include "plane.h"
#include "gtest/gtest.h"
#include <vector>

using std::vector;
using XXYY::BasicPlane;
using XXYY::PlaneFactory;

class PlaneTest : public testing::Test {
  protected:
    virtual void SetUp() {
        planes.push_back(PlaneFactory::NewBasicPlane(1));
        planes.push_back(PlaneFactory::NewBasicPlane(5));
        planes.push_back(PlaneFactory::NewBasicPlane(10));
        planes.push_back(PlaneFactory::NewBasicPlane(20));
    }

    std::vector<BasicPlane> planes;
};

TEST_F(PlaneTest, IdTest) {
    EXPECT_EQ(planes[0].id, 0);
    EXPECT_EQ(planes[1].id, 1);
    EXPECT_EQ(planes[2].id, 2);
    EXPECT_EQ(planes[3].id, 3);
}

TEST_F(PlaneTest, ArriveTimeTest) {
    EXPECT_EQ(planes[0].arrive_time, 1);
    EXPECT_EQ(planes[1].arrive_time, 5);
    EXPECT_EQ(planes[2].arrive_time, 10);
    EXPECT_EQ(planes[3].arrive_time, 20);
}
