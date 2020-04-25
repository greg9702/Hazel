cmake_minimum_required(VERSION 3.17)
project(Linux-sandbox)

set(CMAKE_CXX_STANDARD 17)

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIRS})
link_directories(${X11_LIBRARY_DIRS})
add_definitions(${X11_DEFINITIONS})
if(NOT X11_FOUND)
    message(ERROR " X11 not found!")
endif(NOT X11_FOUND)

include_directories(
    src
    ${CMAKE_SOURCE_DIR}/../Hazel/vendor/Glad/include
    ${CMAKE_SOURCE_DIR}/../Hazel/vendor/GLFW/include
    ${CMAKE_SOURCE_DIR}/../Hazel/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/vendor/glm/
    ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/vendor
    )

ADD_LIBRARY(glfw STATIC IMPORTED)
SET_TARGET_PROPERTIES(glfw PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/vendor/GLFW/bin/Debug-linux-x86_64/GLFW/libGLFW.a)

ADD_LIBRARY(glad STATIC IMPORTED)
SET_TARGET_PROPERTIES(glad PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/vendor/Glad/bin/Debug-linux-x86_64/Glad/libGlad.a)

ADD_LIBRARY(hazel STATIC IMPORTED)
SET_TARGET_PROPERTIES(hazel PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin/Debug-linux-x86_64/Hazel/libHazel.a)

ADD_LIBRARY(imgui STATIC IMPORTED)
SET_TARGET_PROPERTIES(imgui PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../Hazel/vendor/imgui/bin/Debug-linux-x86_64/ImGui/libImGui.a)

FILE(GLOB SOURCES "src/*.cpp")
add_executable(sandbox ${SOURCES})

SET(GCC_COVERAGE_COMPILE_FLAGS "")

TARGET_LINK_LIBRARIES (sandbox hazel imgui glfw glad pthread ${CMAKE_DL_LIBS} ${X11_LIBRARIES})
