#include "gtest/gtest.h"
#include "vector.h"

TEST(Vec3, add) {
    Vec3 a = Vec3(0.0f, 0.0f, 0.0f);
    Vec3 b = Vec3(1.0f, 0.0f, 0.0f);

    a+=b;

    EXPECT_EQ(a.X(), b.X()) << "Should be equal to one";
}