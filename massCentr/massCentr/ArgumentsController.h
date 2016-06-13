#pragma once
//#include <map>
#include "stdafx.h"

//#include <vector>
//#include <string>

/*

		+manual class


*/


class ArgumentsController
{
	typedef std::pair <std::string, std::string> Argument;
	typedef std::vector <Argument> Arguments;
	//typedef std::map <std::string, std::string> Arguments;
	//typedef std::map <std::string, std::string>::iterator ArgumentsIter;
	Arguments arguments;
	static std::string noValue;
	static std::string noArgument;
public:
	ArgumentsController();
	ArgumentsController(int argc, const char **argv);
	std::string &operator[] (const std::string &key);
	size_t size();
	Argument& at(unsigned int i);
};

class ConfigController
{
	typedef std::pair <std::string, ArgumentsController> Section;
	typedef std::vector <Section> Sections;
	//typedef std::map <std::string, ArgumentsController>::iterator SectionIter;
	//typedef std::pair <std::string, ArgumentsController> Section;
	Sections sections;
	static ArgumentsController noSection;
public:
	ConfigController(const std::string &name);
	ArgumentsController &operator[] (const std::string &nameSection);
	void writefile(const std::string &name);
	size_t size();
	Section& at(unsigned int i);
};