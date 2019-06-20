SET(PROJECT_NAME cpp-timing-analysis)

cmake_minimum_required(VERSION 3.14)
project(${PROJECT_NAME})

set(CONFIG_FOLDER "config_files")

set(CMAKE_CXX_STANDARD 20)

if(WIN32)
	set(CMAKE_CXX_FLAGS "/O2 /W4 /EHa")
endif(WIN32)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-fconcepts -Wall -Wextra -Wshadow -Wfloat-conversion -Wsign-conversion -Wsign-compare -Wmissing-field-initializers -fno-threadsafe-statics")
endif(UNIX)

find_package(Poco COMPONENTS JSON XML CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp src/StateMachine/FiniteStateMachine.h src/StateMachine/BaseState.h src/StateMachine/States/Demo.cpp src/StateMachine/States/Demo.h src/StateMachine/States/Demo2.cpp src/StateMachine/States/Demo2.h)
target_link_libraries(${PROJECT_NAME} Poco::JSON Poco::XML)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/${CONFIG_FOLDER})

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${CONFIG_FOLDER} $<TARGET_FILE_DIR:${PROJECT_NAME}>)


add_executable(test_cases test/main.cpp)
target_link_libraries(test_cases Poco::JSON Poco::XML)