#include "template_in_cpp.h"

template<typename T>
T myclass<T>::get_value() const {
	return a;
}

template <typename T>
void myclass<T>::set_value(const T& val) {
	a = val;
}

// This makes things link, because for C++ it is indiferent where
// the class is declared and implemented
template class myclass<int>;
