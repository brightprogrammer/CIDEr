cmake_minimum_required(VERSION 3.0)

#project settings
project(CIDER VERSION 0.0.0 LANGUAGES CXX C)

#include wxWidgets in project
find_package(wxWidgets core base)
include(${wxWidgets_USE_FILE})


