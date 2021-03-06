cmake_minimum_required(VERSION 3.8.2)

if(POLICY CMP0022)
	cmake_policy(SET CMP0022 NEW)
endif()

# Set default build type to Release if empty.
set(CMAKE_BUILD_TYPE "Release" CACHE STRING
	"Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel.")

project(meta VERSION 1.0 LANGUAGES NONE)

include(CTest)
include(GNUInstallDirs)

# building in static will require to export abseil also wich doesn't provide export rule...
# cf https://gitlab.kitware.com/cmake/cmake/issues/17357
option(BUILD_SHARED_LIBS "Build shared libraries(.so)." ON)

# Build Dependencies
add_subdirectory(cmake)

add_subdirectory(Foo)
add_subdirectory(FooApp)

# Install
install(EXPORT CMakeCpuFeaturesTargets
	NAMESPACE CMakeCpuFeatures::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CMakeCpuFeatures
	COMPONENT Devel)
include(CMakePackageConfigHelpers)
configure_package_config_file(cmake/CMakeCpuFeaturesConfig.cmake.in
	"${PROJECT_BINARY_DIR}/CMakeCpuFeaturesConfig.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/CMakeCpuFeatures"
	NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(
	"${PROJECT_BINARY_DIR}/CMakeCpuFeaturesConfigVersion.cmake"
	COMPATIBILITY SameMajorVersion)
install(
	FILES
	"${PROJECT_BINARY_DIR}/CMakeCpuFeaturesConfig.cmake"
	"${PROJECT_BINARY_DIR}/CMakeCpuFeaturesConfigVersion.cmake"
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/CMakeCpuFeatures"
	COMPONENT Devel)
