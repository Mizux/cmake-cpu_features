set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_TESTING OFF)

####################
##  CPU_FEATURES  ##
####################
message(STATUS "Subproject: CPU_FEATURES...")
# Download and unpack cpu_features at configure time
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cpu_features.CMakeLists.txt
	${CMAKE_BINARY_DIR}/cpu_features-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cpu_features-download)
if(result)
  message(FATAL_ERROR "CMake step for cpu_features failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cpu_features-download)
if(result)
  message(FATAL_ERROR "Build step for cpu_features failed: ${result}")
endif()

add_subdirectory(
	${CMAKE_BINARY_DIR}/cpu_features-src
	${CMAKE_BINARY_DIR}/cpu_features-build)
message(STATUS "Subproject: CPU_FEATURES...DONE")
