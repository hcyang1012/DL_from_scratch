#pragma once
namespace dl_framework {
template <typename T>
class Variable {
 public:
  Variable(const T& data);
  const T& Data() const;
  T& MutableData();
  void SetData(const T& data);

 private:
  T data_;
};
}  // namespace dl_framework
