#include <iostream>

/**
 * @file
 * @brief Основной файл программы
 */

#include "bulk.h"
#include "console_listener.h"
#include "file_listener.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Argument not found!" << std::endl;
        return 0;
    }
    std::size_t bulkCount = 0;
    try {
        bulkCount = std::stoul(argv[1]);
    } catch (const std::exception &) {
        std::cout << "Argument not a number!" << std::endl;
        return 0;
    }
    Bulk bulk(bulkCount);
    bulk.subscribe(std::make_shared<ConsoleListener>());
    bulk.subscribe(std::make_shared<FileListener>());
    bulk.start();
    return 0;
}
