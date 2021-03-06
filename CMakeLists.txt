###############################################################################
#
# you can pass some options to cmake via -D<option>[=<value>]
#
#   name            default             description
#
# global options:
#   BRANDING        branding_default    The branding to use for Desura.
#                                       possible values: branding_default, branding_desura
#   DEBUG           OFF                 will add debug symbols and other debugging stuff
#
# unix-only options:
#   WITH_ARES       ON                  build CURL with ares support (c-ares REQUIRED)
#
# windows-only options:
#
###############################################################################

# TODO: silent output for externel dependencies
# TODO: get libs automatically for externel builds, maybe make desura a external build itself?

project(Desura)
cmake_minimum_required(VERSION 2.8)

###############################################################################
# some globale variables
###############################################################################

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
set(CMAKE_PLATFORM_PATH "${CMAKE_SOURCE_DIR}/cmake/platform")
set(CMAKE_EXTERNAL_BINARY_DIR "${CMAKE_BINARY_DIR}/external")
set(CMAKE_THIRD_PARTY_DIR "${CMAKE_SOURCE_DIR}/third_party")
set(CMAKE_SCRIPT_PATH "${CMAKE_SOURCE_DIR}/cmake/scripts")

if(DEBUG)
  set(CMAKE_BUILD_TYPE Debug)
else()
  set(CMAKE_BUILD_TYPE Release)
endif()

###############################################################################
# some includes
###############################################################################

include(ExternalProject)
include(CheckOptions)
include(compilerflags)
include(parsearguments)
include(CheckCompiler)
include(SetInstallPaths)

###############################################################################
# find all packages which are needed
###############################################################################

if(NOT WIN32)
  set(REQUIRED_ON_UNIX REQUIRED)
endif()

if(NOT WIN32)
  find_package(Boost COMPONENTS date_time filesystem thread system REQUIRED)
endif()
find_package(BZip2)

if(NOT WITH_ARES)
  find_package(CURL)
endif()

# we patch google breakpad, so we will build it on our own
# find_package(GoogleBreakpad REQUIRED)
if(NOT WIN32)
  find_package(GTK2 REQUIRED)
endif()
if(NOT WIN32)
  find_package(OpenSSL REQUIRED)
endif()
find_package(Sqlite)
find_package(TinyXML)
find_package(v8 ${REQUIRED_ON_UNIX})
# we patch wxWidgets so we will build it on our own
# find_package(wxWidgets 2.9 REQUIRED)

if(WIN32)
  find_package(PythonInterp REQUIRED)
  find_package(PythonLibs REQUIRED)
endif()

###############################################################################
# build some externel projects
###############################################################################

if(NOT wxWidgets_FOUND)
  include(BuildwxWidgets)
endif()

if(NOT Boost_FOUND)
  include(BuildBoost)
endif()

if(NOT BREAKPAD_EXCEPTION_HANDLER_FOUND)
  include(BuildGoogleBreakpad)
endif()

if(NOT CURL_FOUND)
  include(BuildCURL)  
endif()

if(NOT V8_FOUND)
  include(Buildv8)
endif()

#include(BuildChromium)
#include(BuildCEF)
#include(BuildCourgette)

###############################################################################
# build third_party
###############################################################################

if(NOT BZIP2_FOUND)
  add_subdirectory(third_party/bzip2)
endif()

add_subdirectory(third_party/cef) # for headers only, build via ExternalProject
add_subdirectory(third_party/courgette) # for headers only, build via ExternalProject

if(NOT TINYXML_FOUND)
  add_subdirectory(third_party/tinyxml)
endif()

if(NOT SQLITE_FOUND)
  add_subdirectory(third_party/sqlite)
endif()
add_subdirectory(third_party/sqlite3x)

if(NOT Boost_FOUND)
  add_dependencies(sqlite3x boost)
endif()

###############################################################################
# build desura
###############################################################################
add_subdirectory(src)
add_subdirectory(build_out)
