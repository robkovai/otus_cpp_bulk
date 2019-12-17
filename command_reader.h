#pragma once

/**
 * @file
 * @brief Модуль для чтения команд из стандартного потока ввода
 */

#include <iostream>

#include "command.h"

/**
 * @brief Класс чтения команд из стандартного потока ввода
 */
class CommandReader {
public:
    Command read() {
        std::string command_name;
        if (std::getline(std::cin, command_name)) {
            if (command_name == "{")
                return Command(CommandType::StartBracket);
            if (command_name == "}")
                return Command(CommandType::FinishBracket);
            return Command(CommandType::Command, command_name);
        }
        return Command(CommandType::End);
    }
};
