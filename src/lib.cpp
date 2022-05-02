#include <gtest/gtest.h>

int sum(int a, int b) {
  return a + b;
}

TEST(SUM, onePlusTwo) {
  ASSERT_EQ(sum(1, 2), 3);
}
