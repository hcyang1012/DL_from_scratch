#include <function/function.hpp>

namespace dl_framework {
template <typename T>
class Square : public Function<T> {
 public:
  Variable<T> Forward(const T& x) const override { return Variable<T>(x * x); }
  Variable<T> Backward(const T& gy) const override {
    return Variable<T>(2 * (this->input_->Data()) * gy);
  }
};
}  // namespace dl_framework