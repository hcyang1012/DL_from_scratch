#pragma once

#include <cmath>
// Framework
#include <function/function.hpp>

namespace dl_framework {
template <typename T>
class Exp : public Function<T> {
 private:
  Variable<T> forward(const T& x) const override {
    return Variable<T>(std::exp(x));
  }
};
}  // namespace dl_framework