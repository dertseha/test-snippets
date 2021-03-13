cmake_minimum_required (VERSION 3.11)
project (test-snippets)

## Enable testing and add google test helpers
enable_testing()
include(${PROJECT_SOURCE_DIR}/cmake/AddGoogleTest.cmake)

## Adapt pthread for static/dynamic linking
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG FALSE)
find_package(Threads)
if(TARGET Threads::Threads AND NOT BUILD_SHARED_LIBS)
    set_target_properties(Threads::Threads PROPERTIES INTERFACE_LINK_LIBRARIES "-Wl,--whole-archive ${CMAKE_THREAD_LIBS_INIT} -Wl,--no-whole-archive")
endif()

## General settings
add_library(project-settings INTERFACE)
target_compile_features(project-settings INTERFACE cxx_std_17)

macro(apply_settings TARGET_NAME)
    target_link_libraries(${TARGET_NAME} PUBLIC project-settings)
    target_compile_options(${TARGET_NAME} PRIVATE
            $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall>
            $<$<CXX_COMPILER_ID:MSVC>:-W4>
            )
endmacro()

## Main library
add_library(${PROJECT_NAME} STATIC)
apply_settings(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC "src/main")
file(GLOB_RECURSE PROJECT_SOURCES "src/main/*.cpp" "src/main/*.h")
target_sources(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCES})

## Tests
SET(TEST_NAME "${PROJECT_NAME}-tests")

file(GLOB_RECURSE TEST_SOURCES "src/test/*.cpp" "src/test/*.h")
add_executable(${TEST_NAME} ${TEST_SOURCES})
apply_settings(${TEST_NAME})

target_include_directories(${TEST_NAME} PRIVATE "src/test")
target_link_libraries(${TEST_NAME} PRIVATE ${PROJECT_NAME})
add_gtest(${TEST_NAME})
