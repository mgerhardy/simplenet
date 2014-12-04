if (SIMPLENET_TEST)
	include_directories(${SIMPLENET_SOURCE_DIR}/src/include/simpleeventbus ${SIMPLENET_SOURCE_DIR}/src/test/gtest ${SIMPLENET_SOURCE_DIR}/src/test/gtest/include)
	file(GLOB_RECURSE SRC ${SIMPLENET_SOURCE_DIR}/src/test/*.cc ${SIMPLENET_SOURCE_DIR}/src/test/*.cpp ${SIMPLENET_SOURCE_DIR}/src/test/*.h)
	add_executable(tests ${SRC})

	if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
	elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
		target_link_libraries(tests pthread)
	endif()
endif()

