add_library(searcher STATIC searcher.cpp)

target_include_directories(searcher PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(searcher PRIVATE -Wall -Wextra)
endif()