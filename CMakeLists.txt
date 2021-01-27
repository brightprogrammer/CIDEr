cmake_minimum_required(VERSION 3.0)

#project settings
project(CIDER VERSION 0.0.0 LANGUAGES CXX C)

#include wxWidgets in project
find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

#main executable
add_executable(cider MainApp.cpp)
target_link_libraries(cider cider-editor ${wxWidgets_LIBRARIES})
target_include_directories(cider PUBLIC ${PROJECT_SOURCE_DIR}/src ${wxWidgets_INCLUDE_DIRS})
