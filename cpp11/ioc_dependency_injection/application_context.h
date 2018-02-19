#ifndef __APLICATION_CONTEXT_H_INCLUDED__
#define __APLICATION_CONTEXT_H_INCLUDED__

#include <string>
#include <unordered_map>

class ApplicationContext {
	std::string config_file;
	std::unordered_map<std::string, void *> beans_by_name;
	std::unordered_map<std::string, void *> beans_by_class;
public:
	ApplicationContext(const std::string &config_file);
	void *get_bean(const std::string &class_name);
};


#endif /*__APLICATION_CONTEXT_H_INCLUDED__*/
