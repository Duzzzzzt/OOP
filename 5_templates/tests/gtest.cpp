#include <gtest/gtest.h>
#include "add.h"

TEST(DefAddSuite, TestIntToInt) {
    EXPECT_EQ(def::Add(2, 3), 5);
    EXPECT_EQ(def::Add(-2, -3), -5);
}

TEST(ExtendedAddSuite, TestIntToDouble) {
    double r = def::Add<int, double>(2, 3);
    EXPECT_DOUBLE_EQ(r, 5.0);
}

TEST(ExtendedAddSuite, TestDoubleToInt) {
    int r = def::Add<double, int>(2.5, 3.5);
    EXPECT_EQ(r, 6);
}

TEST(ExtendedAddSuite, TestRandomNotLess) {
    EXPECT_GE(extended::Add(1, 1), def::Add(1, 1));
}