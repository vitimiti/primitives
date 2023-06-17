# ==============================================================================
# The MIT License (MIT)
#
# Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the “Software”), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ==============================================================================

cmake_minimum_required(VERSION 3.25)
project(
  vitimiti_primitives
  VERSION 1.0.0
  DESCRIPTION "Templated library with primitive shapes"
  HOMEPAGE_URL "https://github.com/vitimiti/primitives"
  LANGUAGES CXX)

list(APPEND ${PROJECT_NAME}_PUBLIC_HEADERS
     ${PROJECT_SOURCE_DIR}/include/viti/primitives/point.hpp
     ${PROJECT_SOURCE_DIR}/include/viti/primitives/size.hpp)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} INTERFACE FILE_SET HEADERS FILES
                                         ${${PROJECT_NAME}_PUBLIC_HEADERS})

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIRS}>
            ${vitimiti_concepts_SOURCE_DIR}/include)

if(${PROJECT_IS_TOP_LEVEL})
  add_subdirectory(vendor)
  list(APPEND CMAKE_MODULE_PATH ${vitimiti_cmake_modules_SOURCE_DIR}/cmake)
  include(DefaultCompilerOptions REQUIRED)
  target_set_default_compile_options(${PROJECT_NAME} INTERFACE ON)
  set_target_properties(${PROJECT_NAME} PROPERTIES VERIFY_INTERFACE_HEADER_SETS
                                                   ON)
endif()
