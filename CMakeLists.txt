cmake_minimum_required(VERSION 3.15)
project(PowerModeManager CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Make statically linked executable if MSVC is used
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Fetch FTXUI
include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG main
)
FetchContent_Populate(ftxui)

file(GLOB_RECURSE FTXUI_SRCS 
    "${ftxui_SOURCE_DIR}/src/ftxui/screen/*.cpp"
    "${ftxui_SOURCE_DIR}/src/ftxui/dom/*.cpp"
    "${ftxui_SOURCE_DIR}/src/ftxui/component/*.cpp"
)
list(FILTER FTXUI_SRCS EXCLUDE REGEX ".*_(test|fuzzer|benchmark)\\.cpp$")
list(FILTER FTXUI_SRCS EXCLUDE REGEX "loop\\.cpp$")
list(FILTER FTXUI_SRCS EXCLUDE REGEX "screen_interactive\\.cpp$")

add_executable(PowerModeManager
    src/main.cpp
    src/PowerManager.cpp
    src/UI.cpp
    src/NotificationManager.cpp
    src/ThemeManager.cpp
    ${FTXUI_SRCS}
)

target_include_directories(PowerModeManager PRIVATE
    ${ftxui_SOURCE_DIR}/include
    ${ftxui_SOURCE_DIR}/src
)

target_link_libraries(PowerModeManager PRIVATE
    powrprof
)
