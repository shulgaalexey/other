#include <stdexcept>
#include <string>

class BeanNotFoundException : public std::logic_error {
	std::string class_name;
public:
	BeanNotFoundException() :
		std::logic_error("Unknown bean class") {}
	BeanNotFoundException(const std::string &class_name) :
		std::logic_error(class_name) {}
};
