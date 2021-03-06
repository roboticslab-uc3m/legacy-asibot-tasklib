# Generated by "yarp cmake" & Juan G. Victores 2013

cmake_minimum_required(VERSION 2.6)


set(KEYWORD "TaskLib")

# Find YARP.  Point the YARP_DIR environment variable at your build.
find_package(YARP REQUIRED)

# Search for source code.
file(GLOB folder_source *.cpp *.cc *.c)
file(GLOB folder_header *.hpp)
source_group("Source Files" FILES ${folder_source})
source_group("Header Files" FILES ${folder_header})

# Automatically add include directories if needed.
foreach(header_file ${folder_header})
  get_filename_component(p ${header_file} PATH)
  include_directories(${p})
endforeach(header_file ${folder_header})

# Inclue any directories needed for YARP
include_directories(${YARP_INCLUDE_DIRS} ${ASIBOT_INCLUDE_DIRS})

# Include link directories
link_directories(${ASIBOT_LINK_DIRS})

# Set up our library.
if (folder_source)
  add_library(${KEYWORD} ${folder_source} ${folder_header})
  target_link_libraries(${KEYWORD} ${YARP_LIBRARIES})
else (folder_source)
  message(FATAL_ERROR "No source code files found. Please add something")
endif (folder_source)

# Exporting dependencies for ASIBOTConfig.cmake quite manually for now... 
set(ASIBOT_INCLUDE_DIRS ${ASIBOT_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "appended header dirs")
set(ASIBOT_LIBRARIES ${ASIBOT_LIBRARIES} ${KEYWORD} TinyMath CACHE INTERNAL "appended libraries") # Not for now as it is a header


