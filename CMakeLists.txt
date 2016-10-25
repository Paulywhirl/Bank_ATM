cmake_minimum_required(VERSION 3.6)
project(Bank_ATM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES build/res)

set(SOURCE_FILES build/src/main.cpp "build/src/User confirmation.cpp" build/src/User.cpp build/src/User.h build/src/UserFunctions.cpp build/src/UserFunctions.h build/src/Activity.cpp build/src/Activity.h build/src/Account.cpp build/src/Account.h)
add_executable(Bank_ATM ${SOURCE_FILES})