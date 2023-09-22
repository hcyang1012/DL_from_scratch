#include <gtest/gtest.h>

// Framework
#include <function/exp.hpp>
#include <function/square.hpp>

TEST(FunctionTest, SquareTest) {
  dl_framework::Square<float> square;
  dl_framework::Variable<float> x(2.0f);
  EXPECT_EQ(square(x).Data(), 4.0f);
}

TEST(FunctionTest, FunctionConcat) {
  dl_framework::Square<float> square;
  dl_framework::Exp<float> exp;
  dl_framework::Variable<float> x(2.0f);
  EXPECT_EQ(exp(square(x)).Data(), 54.59815f);
}