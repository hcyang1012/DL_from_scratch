#pragma once
#include <functional>
#include <vector>
// DL
#include <function/function.hpp>
#include <variable.hpp>
namespace dl_framework {

template <typename T>
float numerical_diff(const Function<T>& f, const Variable<T>& x,
                     const float eps = 1e-4) {
  auto x0 = Variable<float>((x.Data()) - eps);
  auto x1 = Variable<float>((x.Data()) + eps);
  auto y0 = f(x0);
  auto y1 = f(x1);

  return (y1.Data() - y0.Data()) / (2.0f * eps);
}

template <typename T>
float numeral_diff(
    const std::function<std::unique_ptr<Function<T>>()>& composed,
    const Variable<T>& x) {
  auto func = composed();
  return numeral_diff(*func, x);
}
}  // namespace dl_framework