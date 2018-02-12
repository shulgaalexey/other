#ifndef __TEMPLATE_IN_CPP_INCLUDED__
#define __TEMPLATE_IN_CPP_INCLUDED__

template <typename T>
class myclass {
	T a;
public:
	T get_value() const;
	void set_value(const T& val);
};

#endif /*__TEMPLATE_IN_CPP_INCLUDED__*/
