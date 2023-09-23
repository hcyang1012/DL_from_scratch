#include <gtest/gtest.h>

#include <derivative.hpp>
#include <function/exp.hpp>
#include <function/square.hpp>
#include <variable.hpp>

TEST(Derivative_Test, BasicTest01) {
  auto f = dl_framework::Square<float>();
  auto x = dl_framework::Variable<float>(2.0f);
  auto dy = dl_framework::numerical_diff(f, x);
  EXPECT_NEAR(dy, 4.0f, 0.01);
}

template <typename T>
class ComposedFunc : public dl_framework::Function<T> {
 public:
 private:
  dl_framework::Variable<T> Forward(const T& x) const override {
    auto A = dl_framework::Square<float>();
    auto B = dl_framework::Exp<float>();
    auto C = dl_framework::Square<float>();

    return C(B(A(x)));
  }
};
TEST(Derivative_Test, BasicTest02) {
  auto composed = ComposedFunc<float>();
  auto x = dl_framework::Variable<float>(0.5);
  auto dy = dl_framework::numerical_diff(composed, x);
  EXPECT_NEAR(dy, 3.29744f, 0.01);
}