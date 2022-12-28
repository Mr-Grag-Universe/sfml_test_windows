cmake_minimum_required(VERSION 3.16)
project(sfml_test_windows)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
if(WIN32)
    set(SFML_ROOT "C:/Users/Stephan/CLionProjects/sfml_test_windows/cmake-build-debug-mingw/libs/SFML") # "C:/SFML-2.5.1")
endif(WIN32)
set(CMAKE_BUILD_TYPE Release)

find_package(OpenGL REQUIRED)
# find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED PATHS C:/SFML-2.5.1/)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES main.cpp   )
set(HEADER_FILES            )

include_directories(OpenGL)
include_directories(OpenGL/include) # OpenGL/include has to contain the required OpenGL's .h files
include_directories(OpenGL/lib) # OpenGL/lib has to contain the required OpenGL's .lib files

include_directories(libs/SFML)
add_subdirectory(libs/SFML)

include_directories("libs/SFML/include")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_directories(${PROJECT_NAME} PRIVATE "libs/SFML/include")

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics ${SFML_DEPENDENCIES})
target_link_libraries(${PROJECT_NAME} ${GLFW})
