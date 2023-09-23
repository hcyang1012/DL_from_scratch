#pragma once
#include <memory>
#include <stdexcept>
// DL
#include <variable.hpp>
namespace dl_framework {

template <typename T>
class Function {
 public:
  Variable<T> operator()(const Variable<T>& x) {
    input_ = std::make_unique<Variable<T>>(x);
    return Forward(x.Data());
  }
  virtual Variable<T> Forward(const T& x) const {
    throw std::runtime_error("Not implemented");
  }

  virtual Variable<T> Backward(const T& gy) const {
    throw std::runtime_error("Not implemented");
  }

 protected:
  std::unique_ptr<Variable<T>> input_;
};
}  // namespace dl_framework