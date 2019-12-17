#pragma once

/**
 * @file
 * @brief Вспомогательные структуры для работы с командами
 */

#include <string>
#include <ctime>
#include <vector>

/**
 * @brief Тип команды
 */
enum class CommandType {
    Command,
    StartBracket,
    FinishBracket,
    End
};

/**
 * @brief Контейнер для команды
 */
struct Command {
    CommandType type;
    std::string name;
    Command(CommandType type = CommandType::Command, std::string name = std::string()): type(type), name(name) {}
};

using Commands = std::vector<Command>;

/**
 * @brief Интерфейс для классов принимающих список команд
 */
struct CommandListener {
    virtual ~CommandListener() = default;
    virtual void update(const std::time_t &time, const Commands &commands) = 0;
};
