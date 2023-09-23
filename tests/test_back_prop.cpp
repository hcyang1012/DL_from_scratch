#include <gtest/gtest.h>

// DL
#include <function/exp.hpp>
#include <function/square.hpp>

TEST(BackProp_Test, BasicTest_01) {
  auto A = dl_framework::Square<float>();
  auto B = dl_framework::Exp<float>();
  auto C = dl_framework::Square<float>();

  auto x = dl_framework::Variable<float>(0.5);
  auto a = A(x);
  auto b = B(a);
  auto y = C(b);

  y.SetGradient(1.0);
  b.SetGradient(C.Backward(y.Gradient()).Data());
  a.SetGradient(B.Backward(b.Gradient()).Data());
  x.SetGradient(A.Backward(a.Gradient()).Data());

  EXPECT_NEAR(x.Gradient(), 3.29744, 0.01);
}