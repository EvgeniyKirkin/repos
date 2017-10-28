#include "ArgumentsController.h"
#include <fstream>
#include <iostream>

using namespace std;

	typedef std::pair <std::string, std::string> Argument;
	typedef std::vector <Argument> Arguments;
	typedef std::pair <std::string, ArgumentsController> Section;

std::string ArgumentsController::noValue = string();
std::string ArgumentsController::noArgument = string();
ArgumentsController ConfigController::noSection = ArgumentsController();

ArgumentsController::ArgumentsController() {}

ArgumentsController::ArgumentsController(int argc, const char **argv)
{
	string arg;
	for(int i(0); i<argc; i++)
	{
		arg = argv[i];
		size_t equalPos = arg.find('=', 0);
		Argument argument;
		if(equalPos != string::npos) 
		{
			argument.first = string(arg, 0, equalPos);
			argument.second = string(arg, equalPos + 1, arg.size() - equalPos - 1);
		} else {
			argument.first = arg;
		}
		arguments.push_back(argument);
	}
}

std::string &ArgumentsController::operator[] (const std::string &key)
{
	for(unsigned int i(0); i<arguments.size(); i++)
	{
		if(arguments.at(i).first == key)
		{
			return arguments.at(i).second;
		}
	}
	return noArgument;
}


size_t ArgumentsController::size()
{
	return arguments.size();
}


Argument& ArgumentsController::at(unsigned int i)
{
	return  arguments.at(i);
}

ConfigController::ConfigController(const std::string &name)
{
	string str;
	string nameSection, newNameSection;
	ifstream file(name, ios::in);
	if(!file)
	{
		cout<<"Can't open file "<<name<<endl;
		return;
	}
	while(getline(file, str))
	{
		if(str.at(0) == '[')
		{
			newNameSection = str.substr(1, str.size()-2);
			continue;
		}
		nameSection = newNameSection;
		vector<string> argumentValue;

		do {
			if(str.at(0) == '[')
			{
				newNameSection = str.substr(1, str.size()-2);
				break;
			}
			argumentValue.push_back(str);
		} while(getline(file, str));

		const char **argValue;
		argValue = new const char*[argumentValue.size()];
		for(size_t i(0); i<argumentValue.size(); i++)
			argValue[i] = argumentValue.at(i).data();

		ArgumentsController argument(argumentValue.size() ,argValue);
		delete [] argValue;
		sections.push_back(Section(nameSection, argument));
	}
}

ArgumentsController& ConfigController::operator[] (const std::string &nameSection)
{
	for(unsigned int i(0); i<sections.size(); i++)
	{
		if(sections.at(i).first == nameSection)
		{
			return sections.at(i).second;
		}
	}
	return noSection;
}

void ConfigController::writefile(const std::string &name)
{
	ofstream file(name, ios::out);
	if(!file)
	{
		cout<<"can't make file "<<name<<endl;
		return;
	}
	for(unsigned int i(0); i<sections.size(); i++)
	{
		file<<"["<<sections.at(i).first<<"]"<<endl;
		for(unsigned int j(0); j<sections.at(i).second.size(); j++)
			file<<sections.at(i).second.at(j).first<<"="<<sections.at(i).second.at(j).second<<endl;
	}
}

size_t ConfigController::size()
{
	return sections.size();
}

Section& ConfigController::at(unsigned int i)
{
	return sections.at(i);
}
