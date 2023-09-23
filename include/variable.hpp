#pragma once
#include <memory>

// DL
namespace dl_framework {
template <typename T>
class Variable {
 public:
  Variable(const T& data) : data_(data) {}
  Variable(const Variable<T>& other) : data_(other.Data()) {
    if (other.grad_ != nullptr) {
      grad_ = std::make_unique<T>(*(other.grad_));
    }
  }
  const T& Data() const { return data_; }
  T& MutableData() { return data_; }
  void SetData(const T& data) { data_ = data; }

  const T& Gradient() const { return (*grad_); }
  void SetGradient(const T& value) { grad_ = std::make_unique<T>(value); }

 private:
  T data_;
  std::unique_ptr<T> grad_;
};
}  // namespace dl_framework
