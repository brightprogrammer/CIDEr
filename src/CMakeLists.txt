add_library(cider-editor Editor/MainFrame.cpp)
target_link_libraries(cider-editor ${wxWidgets_LIBRARIES})
target_include_directories(cider-editor PUBLIC ${wxWidgets_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/src)