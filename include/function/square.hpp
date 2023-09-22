#include <function/function.hpp>

namespace dl_framework {
template <typename T>
class Square : public Function<T> {
 private:
  Variable<T> forward(const T& x) const override { return Variable<T>(x * x); }
};
}  // namespace dl_framework