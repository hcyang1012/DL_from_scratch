#pragma once
#include <stdexcept>
#include <variable.hpp>
namespace dl_framework {

template <typename T>
class Function {
 public:
  Variable<T> operator()(const Variable<T>& x) const {
    return forward(x.Data());
  }

 protected:
  virtual Variable<T> forward(const T& x) const {
    throw std::runtime_error("Not implemented");
  }
};
}  // namespace dl_framework