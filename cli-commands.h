#pragma once
#pragma once
#ifndef CLI_COMMANDS_H
#define CLI_COMMANDS_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include "cli-constants.h"

typedef struct CLICommand {
	std::string(*executable)();
	std::string name;
	std::string description;
};

typedef std::map<std::string, CLICommand> CLICommandMap;

std::string commandUnknown(std::string command);
std::string commandExit();
std::string commandHelp();
std::string commandClean();

std::map<std::string, CLICommand> getCLICommands();


#endif
