#pragma once
#ifndef CLI_H
#define CLI_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>

std::string commandParser(std::map<std::string, std::string(*)()> commands, std::string command);
std::string runCLI(std::map<std::string, std::string(*)()> commands);
void startCLI();

#endif
