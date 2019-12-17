cmake_minimum_required(VERSION 3.2)

project(otus_cpp_bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(bulk "main.cpp" "bulk.h" "bulk.cpp" "command.h" "command_reader.h" "console_listener.h" "file_listener.h")

set_target_properties(bulk PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_NAME "bulk")
set(CPACK_PACKAGE_CONTACT "dedi4@mail.ru")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
include(CPack)
