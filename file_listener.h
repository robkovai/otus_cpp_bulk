#pragma once

/**
 * @file
 * @brief Модуль для записи команд в файл
 */

#include <fstream>
#include <string>

#include "command.h"

/**
 * @brief Класс записи команд в файл
 */
class FileListener : public CommandListener {
public:
    void update(const std::time_t &time, const Commands &commands) override {
        std::ofstream file("bulk" + std::to_string(time) + ".log");
        if (!file.is_open())
            return;
        for (auto command : commands)
            file << command.name << std::endl;
        file.close();
    }
};
