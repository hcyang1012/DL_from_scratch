#pragma once
namespace dl_framework {
template <typename T>
class Variable {
 public:
  Variable(const T& data) : data_(data) {}
  const T& Data() const { return data_; }
  T& MutableData() { return data_; }
  void SetData(const T& data) { data_ = data; }

 private:
  T data_;
};
}  // namespace dl_framework
