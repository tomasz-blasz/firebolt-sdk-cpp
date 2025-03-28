# Copyright 2023 Comcast Cable Communications Management, LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.3)

project(Firebolt)

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(FIREBOLT_TRANSPORT_WAITTIME 1000 CACHE STRING "Maximum time to wait for Transport layer to get response")
set(FIREBOLT_LOGLEVEL "Info" CACHE STRING  "Log level to be enabled")

set(SDK_TARGET "" CACHE STRING "Target SDK to build: core, manage, discovery")

# Default options
option(FIREBOLT_ENABLE_STATIC_LIB "Create Firebolt library as Static library" OFF)
option(ENABLE_BIDIRECTIONAL "Enable bidirectional communication over WS" ON)
option(ENABLE_TESTS "Build openrpc native test" ON)
option(ENABLE_UNIT_TESTS "Enable unit test" ON)
option(ENABLE_COVERAGE "Enable code coverage build." ON)
option(ENABLE_INTERACTIVE_APP "Enable interactive application" OFF)
option(FIREBOLT_PLAIN_LOG "Disable log coloring" OFF)

if (NOT SDK_TARGET)
    message(FATAL_ERROR "SDK_TARGET is not set [${SDK_TARGET}]")
endif ()

message("Building SDK: ${SDK_TARGET}")
add_compile_definitions(SDK_TARGET=${SDK_TARGET})
add_compile_definitions(JSON_ENGINE_OPENRPC_FILE="${CMAKE_CURRENT_SOURCE_DIR}/../api/${SDK_TARGET}/firebolt-${SDK_TARGET}-open-rpc.json")

file(GLOB APP_SCHEMA "./api/${SDK_TARGET}/firebolt-${SDK_TARGET}-app-open-rpc.json")
if (NOT APP_SCHEMA)
  set(ENABLE_BIDIRECTIONAL OFF)
endif ()

if (ENABLE_BIDIRECTIONAL)
    message("Using bidirectional gateway")
    add_compile_definitions(GATEWAY_BIDIRECTIONAL)
else ()
    message("Using unidirectional gateway")
endif ()

if (ENABLE_INTERACTIVE_APP)
    set(ENABLE_TESTS ON)
    set(ENABLE_UNIT_TESTS OFF)
    set(ENABLE_COVERAGE OFF)
endif ()

if (FIREBOLT_PLAIN_LOG)
    add_compile_definitions(LOGGER_NO_COLOR)
endif ()

if (FIREBOLT_ENABLE_STATIC_LIB)
    set(FIREBOLT_LIBRARY_TYPE STATIC)
else ()
    set(FIREBOLT_LIBRARY_TYPE SHARED)
endif ()

include_directories(
    ${SDK_TARGET}/include
    ${SDK_TARGET}/src
)

include(FetchContent)

set(nlohmann_json_VERSION v3.11.3 CACHE STRING "Referenced by nlohmann_json_schema_validator")
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG 9cca280a4d0ccf0c08f47a99aa71d1b0e52f8d03 # v3.11.3
    FIND_PACKAGE_ARGS
)

FetchContent_Declare(
    nlohmann_json_schema_validator
    GIT_REPOSITORY https://github.com/pboettch/json-schema-validator.git
    GIT_TAG 349cba9f7e3cb423bbc1811bdd9f6770f520b468 # 2.3.0
    FIND_PACKAGE_ARGS
)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59 # v1.15.2
    FIND_PACKAGE_ARGS NAMES GTest
)

message("Fetching external projects... ")

set(BUILD_SHARED_LIBS_OLD ${BUILD_SHARED_LIBS})
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCED)
set(JSON_VALIDATOR_SHARED_LIBS ON CACHE BOOL "")

FetchContent_MakeAvailable(nlohmann_json nlohmann_json_schema_validator googletest)

set(BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS_OLD} CACHE BOOL "" FORCED)

FetchContent_GetProperties(nlohmann_json)
FetchContent_GetProperties(nlohmann_json_schema_validator)
FetchContent_GetProperties(googletest)

include_directories(
    ${nlohmann_json_SOURCE_DIR}/include
    ${nlohmann_json_schema_validator_SOURCE_DIR}/src
    ${googletest_SOURCE_DIR}/googletest/include
    ${googletest_SOURCE_DIR}/googlemock/include
)

# if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${SYSROOT_PATH}/usr CACHE INTERNAL "" FORCE)
    set(CMAKE_PREFIX_PATH ${SYSROOT_PATH}/usr/lib/cmake CACHE INTERNAL "" FORCE)
# endif()

list(APPEND CMAKE_MODULE_PATH
        "${CMAKE_SOURCE_DIR}/cmake"
        "${SYSROOT_PATH}/usr/lib/cmake"
        "${SYSROOT_PATH}/tools/cmake")
include(HelperFunctions)

set(FIREBOLT_NAMESPACE ${PROJECT_NAME} CACHE STRING "Namespace of the project")

message("CMAKE_PREFIX_PATH: " ${CMAKE_PREFIX_PATH})

find_package(WPEFramework CONFIG REQUIRED)

if (ENABLE_UNIT_TESTS AND ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

add_subdirectory(src)

if (ENABLE_TESTS OR ENABLE_UNIT_TESTS)
    enable_testing()
    add_subdirectory(test/${SDK_TARGET})
endif()

# make sure others can make use cmake settings of Firebolt OpenRPC
configure_file( "${CMAKE_SOURCE_DIR}/cmake/project.cmake.in"
        "${CMAKE_BINARY_DIR}/${FIREBOLT_NAMESPACE}Config.cmake"
    @ONLY)

