#include <string>
#include "cli-commands.h"

std::string cliCommand;

std::string commandParser(std::string command) {
	CLICommandMap commands = getCLICommands();

	if (commands.find(command) == commands.end()) return commandUnknown(command);
	return commands[command].executable();
}

std::string runCLI() {
	std::cout << "root# ";
	std::cin >> cliCommand;

	return commandParser(cliCommand);
}

void startCLI() {
	system("cls");
	while (runCLI() != CLI_EXIT) runCLI();
}