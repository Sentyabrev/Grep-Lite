cmake_minimum_required(VERSION 3.20)

project("Grep-Lite" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "Компилятор ${CMAKE_CXX_COMPILER_ID}: ${CMAKE_CXX_COMPILER} v${CMAKE_CXX_COMPILER_VERSION}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    message(STATUS "Тип сборки не задан, используется Debug")
else()
    message(STATUS "Тип сборки: ${CMAKE_BUILD_TYPE}")
endif()

message(STATUS "Конфигурация lib")
add_subdirectory(lib)
message(STATUS "Конфигурация app")
add_subdirectory(app)
message(STATUS "Готово")