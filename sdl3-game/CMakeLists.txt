cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(SDL3Game VERSION 1.0 LANGUAGES C)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add SDL3 as subdirectory (our submodule)
add_subdirectory(lib/SDL3)

# Include directories
include_directories(include)
include_directories(lib/SDL3/include)

# Source files
set(SOURCES
    src/main.c
    src/GAM_DL_window.c
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SDL3 library
target_link_libraries(${PROJECT_NAME} SDL3::SDL3)

# Compiler specific options
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -std=c11)
endif()

# Set output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Add support for WebAssembly
if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "-s WASM=1"
    )
endif()