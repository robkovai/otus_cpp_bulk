#include "bulk.h"

/**
 * @file
 * @brief Реализация главного модуля для работы с командами
 */

#include <algorithm>

#include "command_reader.h"

Bulk::Bulk(std::size_t countCommands): countCommands(countCommands) { }

void Bulk::subscribe(std::shared_ptr<CommandListener> listener) {
    this->listeners.push_back(listener);
}

void Bulk::unsubscribe(std::shared_ptr<CommandListener> listener) {
    this->listeners.erase(std::find(this->listeners.begin(), this->listeners.end(), listener));
}

void Bulk::start() {
    CommandReader reader;
    Command currentCommand;

    while (currentCommand.type != CommandType::End) {
        currentCommand = reader.read();
        switch (currentCommand.type) {
            case CommandType::StartBracket:  this->readStartBracket(); break;
            case CommandType::FinishBracket: this->readFinishBracket(); break;
            case CommandType::Command:       this->readCommand(currentCommand); break;
            case CommandType::End:           this->readEnd(); break;
        }
    }
}

void Bulk::readStartBracket() {
    if (!this->nestingBrackets)
        notify();
    this->nestingBrackets++;
}

void Bulk::readFinishBracket() {
    this->nestingBrackets--;
    if (!this->nestingBrackets)
        notify();
}

void Bulk::readCommand(Command command) {
    if (!this->currentCommands.size())
        this->currentTime = std::time(nullptr);

    this->currentCommands.push_back(command);
    if (!this->nestingBrackets && this->countCommands == this->currentCommands.size())
        notify();
}

void Bulk::readEnd() {
    if (!this->nestingBrackets)
        notify();
}

void Bulk::notify() {
    if (this->currentCommands.empty())
        return;

    for (auto listener : this->listeners)
        listener->update(this->currentTime, this->currentCommands);

    this->currentCommands.clear();
}
