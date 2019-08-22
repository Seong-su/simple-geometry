cmake_minimum_required(VERSION 3.0.0)
project(lbt-info VERSION 0.1.0)

set(LBT_SOURCE_FILES lbt-info.cpp StepReader.cpp)

add_library(lbt-info STATIC ${LBT_SOURCE_FILES})
#target_include_directories(lbt-info PUBLIC ${LBT_INFO_INCLUDE_DIR})

add_executable(lbt-main main.cpp)
target_link_libraries(lbt-main lbt-info)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)