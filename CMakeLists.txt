cmake_minimum_required(VERSION 3.12)
project(DataStructures 
        VERSION 0.0.1
        DESCRIPTION "All Data Structures implemented in C"
        LANGUAGES C)

# Author details
set(PROJECT_AUTHOR "Tauseef Hilal Tantary")
set(PROJECT_AUTHOR_EMAIL "tantary.tauseef.atwork@gmail.com")

set(CMAKE_C_STANDARD 11)

# Set the include directories
include_directories(include)

# Source files
set(SRC_DIR src)
set(LIB_SOURCES
        ${SRC_DIR}/linked_list/singly_linked_list.c
        ${SRC_DIR}/utils/common.c)

# Library target
add_library(data_structures ${LIB_SOURCES})

# Examples
set(EXAMPLES_DIR examples)
set(EXAMPLE_SOURCES
        ${EXAMPLES_DIR}/linked_list/singly_linked_list.c)

# Example executables
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} data_structures)
endforeach()
