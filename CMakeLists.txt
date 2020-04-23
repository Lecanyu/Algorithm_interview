cmake_minimum_required (VERSION 3.8)
 
project ("Algorithm_organized")


add_subdirectory(dynamic_programming)			
add_subdirectory(misc)	
add_subdirectory(binary_search)
add_subdirectory(computation_geometry)
add_subdirectory(hash)
add_subdirectory(graph)
add_subdirectory(tree)


# Install as library
# we want to differentiate libraries in different modes
#SET(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "add a postfix, usually d on windows")		# set 'd' as debug mode suffix/postfix
#SET(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")

# we want to differentiate binaries in different modes
#set(TARGET_NAME test_example1 test_example2 test_example3)
#set_target_properties(${TARGET_NAME} PROPERTIES DEBUG_POSTFIX "_d")    
#set_target_properties(${TARGET_NAME} PROPERTIES RELEASE_POSTFIX "")


#install(TARGETS test_example1 test_example2 test_example3 add 
#	ARCHIVE DESTINATION lib
#	LIBRARY DESTINATION lib
#	RUNTIME DESTINATION bin
#)

#install(FILES test_example2_func.h DESTINATION include)



# print all variables 
#[[
get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()
]]
