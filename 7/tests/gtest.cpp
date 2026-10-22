#include <gtest/gtest.h>
#include "temp_tracker.h"

TEST(TempTrackerDefaultConstructor, TestDefaults) {
    TempTracker a;
    EXPECT_EQ(a.getId(), 0);
    EXPECT_EQ(a.getFactoryId(), 1);
    EXPECT_DOUBLE_EQ(a.getTemp(), 0.0);
    EXPECT_EQ(a.getLast10Vals().size(), 10u);
}

TEST(TempTrackerInitConstructor, TestFields) {
    TempTracker b(7, 42, 25.5, {1, 2, 3});
    EXPECT_EQ(b.getId(), 7);
    EXPECT_EQ(b.getFactoryId(), 42);
    EXPECT_DOUBLE_EQ(b.getTemp(), 25.5);
    ASSERT_EQ(b.getLast10Vals().size(), 10u);
    EXPECT_DOUBLE_EQ(b.getLast10Vals()[0], 1.0);
}

TEST(TempTrackerCopyConstructor, TestCopyEqualsOriginal) {
    TempTracker b(7, 42, 25.5, {1, 2, 3});
    TempTracker d(b);
    EXPECT_EQ(d.getId(), b.getId());
    EXPECT_EQ(d.getFactoryId(), b.getFactoryId());
    EXPECT_DOUBLE_EQ(d.getTemp(), b.getTemp());
    EXPECT_EQ(d.getLast10Vals(), b.getLast10Vals());
}

TEST(TempTrackerAssignment, TestAssignCopiesAllFields) {
    TempTracker b(7, 42, 25.5, {1, 2, 3});
    TempTracker e;
    e = b;
    EXPECT_EQ(e.getId(), 7);
    EXPECT_EQ(e.getFactoryId(), 42);
    EXPECT_DOUBLE_EQ(e.getTemp(), 25.5);
}

TEST(TempTrackerAssignment, TestSelfAssignmentKeepsData) {
    TempTracker b(7, 42, 25.5, {1, 2, 3});
    b = b;
    EXPECT_EQ(b.getId(), 7);
    EXPECT_DOUBLE_EQ(b.getTemp(), 25.5);
}

TEST(Normalize, TestTooHighTemp) {
    TempTracker x(1, 1, 5000.0, {});
    EXPECT_DOUBLE_EQ(x.getTemp(), 1000.0);
}

TEST(Normalize, TestTooLowTemp) {
    TempTracker x(1, 1, -5000.0, {});
    EXPECT_DOUBLE_EQ(x.getTemp(), -273.0);
}

TEST(Normalize, TestEmptyFactoryId) {
    TempTracker x(1, 0, 20.0, {});
    EXPECT_EQ(x.getFactoryId(), 1);
}

TEST(Normalize, TestValuesOutOfRangeAreClamped) {
    TempTracker x(1, 1, 20.0, {5000.0, -5000.0});
    EXPECT_DOUBLE_EQ(x.getLast10Vals()[0], 1000.0);
    EXPECT_DOUBLE_EQ(x.getLast10Vals()[1], -273.0);
}

TEST(Setters, TestSetTempIsNormalized) {
    TempTracker b(7, 42, 25.5, {1, 2, 3});
    b.setTemp(-1000.0);
    EXPECT_DOUBLE_EQ(b.getTemp(), -273.0);
}

TEST(Setters, TestSetIdAndValues) {
    TempTracker a;
    a.setId(9);
    a.setLast10Vals({5, 6});
    EXPECT_EQ(a.getId(), 9);
    EXPECT_EQ(a.getLast10Vals().size(), 10u);
    EXPECT_DOUBLE_EQ(a.getLast10Vals()[1], 6.0);
}

TEST(TempTrackerCopyConstructor, TestCopyHasItsOwnMemory) {
    TempTracker b(7, 42, 25.5, {1, 2, 3});
    TempTracker d(b);
    d.setLast10Vals({9, 9, 9});
    EXPECT_DOUBLE_EQ(b.getLast10Vals()[0], 1.0);
    EXPECT_DOUBLE_EQ(d.getLast10Vals()[0], 9.0);
}

TEST(TempTrackerDestructor, TestManyAssignmentsDieCleanly) {
    TempTracker b(7, 42, 25.5, {1, 2, 3});
    {
        TempTracker copies[50];
        for (int i = 0; i < 50; i++) {
            copies[i] = b;
        }
    }
    SUCCEED();
}