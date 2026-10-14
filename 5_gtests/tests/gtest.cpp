#include <gtest/gtest.h>
#include "add.h"

TEST(DefAddSuite, TestPositive) {
    EXPECT_EQ(def::Add(2, 3), 4);
    EXPECT_EQ(1, 1);
    std::cout << "<<< провальный експект" << std::endl;
}

TEST(DefAddSuite, TestNegative) {
    ASSERT_EQ(def::Add(-2, -3), 4);
    std::cout << "провальный ассерт" << std::endl;
}


TEST(ExtendedAddSuite, TestNotLessThanDef) {
    EXPECT_GE(extended::Add(1, 1), def::Add(1, 1));
}