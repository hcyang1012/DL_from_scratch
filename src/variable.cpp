#include <variable.hpp>

namespace dl_framework {
template <typename T>
Variable<T>::Variable(const T& data) : data_(data) {}

template <typename T>
const T& Variable<T>::Data() const {
  return data_;
}

template <typename T>
T& Variable<T>::MutableData() {
  return data_;
}

template <typename T>
void Variable<T>::SetData(const T& data) {
  data_ = data;
}

template class Variable<float>;

}  // namespace dl_framework
