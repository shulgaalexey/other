#include "application_context.h"
#include "bean_not_found_exception.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>

static std::vector<std::string> tokenize(const std::string &str) {
	std::istringstream iss(str);
	std::vector<std::string> tokens{
		std::istream_iterator<std::string>{iss},
			std::istream_iterator<std::string>{}};
	return tokens;
}

ApplicationContext::ApplicationContext(
		const std::string &config_file) : config_file{config_file} {

	// Open file
	std::ifstream is {config_file};

	std::vector<std::string> beans{
		std::istream_iterator<std::string>{is},
		std::istream_iterator<std::string>{}};

	// Construct beans
	std::for_each(std::begin(beans), std::end(beans),
		[](const std::string &str) {
			if (str.substr(0, 6) != "*bean*")
				return;

			std::vector<std::string> tokens = tokenize(str);

			if (tokens.size() < 3)
				return;

			std::string klass = tokens[1];
			std::string obj_name = tokens[2];

			for (int i = 3; i < tokens.size(); i++) {
				std::string param_name = tokens[i];
				// procede params
			}

			// Add beand to the map
	});
}

void *ApplicationContext::get_bean(const std::string &class_name) {
	if (beans_by_class.find(class_name) == beans_by_class.end()) {
		throw BeanNotFoundException(class_name);
	}
	return nullptr;
}
