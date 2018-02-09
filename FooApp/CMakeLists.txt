project(FooApp VERSION 1.0.0 LANGUAGES CXX)

file(GLOB _SRCS "src/*.[hc]pp")

if(TARGET cpu_features)
	message(STATUS "Found Target: cpu_features")
else()
	message(FATAL_ERROR "Target cpu_features not found")
endif()

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE ${_SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
target_link_libraries(${PROJECT_NAME} PRIVATE cpu_features)
add_executable(CMakeCpuFeatures::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Test
include(CTest)
if(BUILD_TESTING)
	add_test(NAME FooApp_UT COMMAND FooApp)
endif()

# Install
install(TARGETS	${PROJECT_NAME}
	EXPORT CMakeCpuFeaturesTargets
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	)
