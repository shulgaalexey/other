#include "application_context.h"
#include "bean_not_found_exception.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <functional>
#include "car.h"
#include "truck.h"
#include "gas_engine.h"
#include "diesel_engine.h"
#include "four_wheel_transmission.h"
#include "six_wheel_transmission.h"

static std::vector<std::string> tokenize(const std::string &str) {
	std::istringstream iss(str);
	std::vector<std::string> tokens{
		std::istream_iterator<std::string>{iss},
			std::istream_iterator<std::string>{}};
	return tokens;
}

ApplicationContext::ApplicationContext(
		const std::string &config_file) : config_file{config_file} {

	try {
		std::ifstream is {config_file};
		for (std::string line; getline(is, line); ) {
			add_bean(line);
		}
	} catch (BeanNotFoundException ex) {
		std::cout << ex.what() << std::endl;
	}
}

ApplicationContext::~ApplicationContext() {
	std::cout << "dtor ApplicationContext\n";
	for(auto b = std::begin(beans_by_class); b != std::end(beans_by_class); ++b)
		delete b->second;

	beans_by_class.clear();
	beans_by_name.clear();
}

BaseClass *ApplicationContext::get_bean(const std::string &class_name) {
	if (beans_by_class.find(class_name) == beans_by_class.end()) {
		std::cout << "Cannot get bean of class: " + class_name << std::endl;
		throw BeanNotFoundException("Cannot get bean of class: " + class_name);
	}

	return beans_by_class[class_name];
}

BaseClass *ApplicationContext::construct_bean(const std::string &class_name,
		const std::vector<BaseClass *> &args) {

	// Constructors with 0 args
	std::unordered_map<std::string, std::function<BaseClass*()>> m0 = {
		{"GasEngine", [](){ return new GasEngine(); }},
		{"DieselEngine", [](){ return new DieselEngine(); }},
		{"FourWheelTransmission", [](){ return new FourWheelTransmission(); }},
		{"SixWheelTransmission", [](){ return new SixWheelTransmission(); }}
	};


	// Constructors with 2 args
	std::unordered_map<std::string,
		std::function<BaseClass*(BaseClass *, BaseClass *)>> m2 = {
		{"Car", [](BaseClass *arg1, BaseClass *arg2){
				return new Car(dynamic_cast<Engine *>(arg1),
												dynamic_cast<Transmission *>(arg2)); }},

		{"Truck", [](BaseClass *arg1, BaseClass *arg2){
				return new Truck(dynamic_cast<Engine *>(arg1),
												dynamic_cast<Transmission *>(arg2)); }}
	};

	switch (args.size()) {
		case 0:
			return m0[class_name]();
		case 2:
			return m2[class_name](args[0], args[1]);
		default: {
			std::cout << "Unknown bean param number for" 	+ class_name << std::endl;
			throw BeanNotFoundException("Unknown bean param number for"
				 	+ class_name);
		 }
	}

	return nullptr;
}

void ApplicationContext::add_bean(const std::string &str) {
	std::cout << "Add bean: [" + str << "]\n";

	if (str.substr(0, 6) != "*bean*")
		return;
	std::vector<std::string> tokens = tokenize(str);

	if (tokens.size() < 3)
		return;

	std::string class_name = tokens[1];
	std::string bean_name = tokens[2];

	if (beans_by_name.find(bean_name) != beans_by_name.end())
		return;

	std::vector<BaseClass *> args;
	for (int i = 4; i < tokens.size(); i++) {
		const std::string arg = tokens[i];
		BaseClass *parg = nullptr;
		if(beans_by_name.find(arg) != beans_by_name.end())
			parg = beans_by_name[arg];
		args.push_back(parg);
	}

	BaseClass *bean = construct_bean(class_name, args);

	if (!bean) {
		std::cout << "Can not construct bean by class: " + class_name << std::endl;
		throw BeanNotFoundException("Can not construct bean by class: "
				+ class_name);
	}

	beans_by_name[bean_name] = bean;
	beans_by_class[class_name] = bean;
}
