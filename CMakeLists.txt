cmake_minimum_required(VERSION 2.8)

project(RLTicTac)
set (CMAKE_CXX_STANDARD 14)
add_executable(${PROJECT_NAME} "main.cpp" "rl_tictac.cpp" "agent.cpp" "machine_agent.cpp")
