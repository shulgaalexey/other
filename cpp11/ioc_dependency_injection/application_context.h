#ifndef __APLICATION_CONTEXT_H_INCLUDED__
#define __APLICATION_CONTEXT_H_INCLUDED__

#include <string>
#include <vector>
#include <unordered_map>
#include "base_class.h"

class ApplicationContext {
	std::string config_file;
	std::unordered_map<std::string, BaseClass *> beans_by_name;
	std::unordered_map<std::string, BaseClass *> beans_by_class;
public:
	ApplicationContext(const std::string &config_file);
	~ApplicationContext();
	BaseClass *get_bean(const std::string &class_name);
private:
	void add_bean(const std::string &str);
	BaseClass *construct_bean(const std::string &class_name,
		const std::vector<BaseClass *> &args);
};


#endif /*__APLICATION_CONTEXT_H_INCLUDED__*/
