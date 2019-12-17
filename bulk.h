#pragma once

/**
 * @file
 * @brief Главный модуль для работы с командами
 */

#include <memory>

#include "command.h"

/**
 * @brief Главный класс для работы с командами
 */
class Bulk {
public:
    Bulk(std::size_t countCommands);
    void subscribe(std::shared_ptr<CommandListener> listener);
    void unsubscribe(std::shared_ptr<CommandListener> listener);
    void start();

private:
    void readStartBracket();
    void readFinishBracket();
    void readCommand(Command command);
    void readEnd();
    void notify();

    std::size_t countCommands;
    std::vector<std::shared_ptr<CommandListener>> listeners;

    std::size_t nestingBrackets = 0;
    std::time_t currentTime;
    std::vector<Command> currentCommands;
};
