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

CLICommandMap getCLICommands();

std::string commandHelp() {
	CLICommandMap commands = getCLICommands();
	CLICommandMap::iterator it = commands.begin();

	std::cout << "Here are currently implemented commands:" << std::endl;
	while (it != commands.end()) {
		std::cout << it->second.name;
		std::cout << " - ";
		std::cout << it->second.description << std::endl;

		it++;
	}

	return CLI_CONTINUE;
}

std::string commandUnknown(std::string command) {
	std::cout << "OS: unknown command " << command << std::endl;
	return CLI_CONTINUE;
}

std::string commandExit() {
	return CLI_EXIT;
}

std::string commandClean() {
	system("cls");
	return CLI_CONTINUE;
}

CLICommand createCommand(std::string name, std::string description, std::string(*executable)()) {
	CLICommand temp;
	temp.name = name;
	temp.description = description;
	temp.executable = executable;

	return temp;
}


CLICommandMap getCLICommands() {
	CLICommandMap commands;

	commands["help"] = createCommand("help", "get CLI help", commandHelp);
	commands["clean"] = createCommand("clean", "clean CLI screen", commandClean);
	commands["exit"] = createCommand("exit", "exit CLI", commandExit);

	return commands;
}

