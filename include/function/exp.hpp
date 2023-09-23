#pragma once

#include <cmath>
// DL
#include <function/function.hpp>

namespace dl_framework {
template <typename T>
class Exp : public Function<T> {
 public:
  Variable<T> Forward(const T& x) const override {
    return Variable<T>(std::exp(x));
  }
  Variable<T> Backward(const T& gy) const override {
    return Variable<T>(std::exp(this->input_->Data()) * gy);
  }
};
}  // namespace dl_framework