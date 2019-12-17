#pragma once

/**
 * @file
 * @brief Модуль вывода команд в стандартный поток
 */

#include <iostream>

#include "command.h"

/**
 * @brief Класс вывода команд в стандартный поток
 */
class ConsoleListener : public CommandListener {
public:
    void update(const std::time_t&, const Commands &commands) override {
        std::cout << "bulk: " << commands.front().name;
        for (size_t i = 1; i < commands.size(); ++i)
            std::cout << ", " << commands.at(i).name;
        std::cout << std::endl;
    }
};
