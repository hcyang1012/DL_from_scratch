#include <gtest/gtest.h>

#include <derivative.hpp>
#include <function/square.hpp>
TEST(Derivative_Test, basic_test01) {
  auto f = dl_framework::Square<float>();
  auto x = dl_framework::Variable<float>(2.0f);
  auto dy = dl_framework::numerical_diff(f, x);
  EXPECT_NEAR(dy, 4.0f, 0.01);
}