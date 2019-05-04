cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(main)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cpp-curses-db main.cpp)
target_link_libraries(cpp-curses-db ${CURSES_LIBRARIES})

#Test
#include(ExternalProject)
#ExternalProject_Add(googletest
	#URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
	#URL_HASH SHA1=f85f6d2481e2c6c4a18539e391aa4ea8ab0394af
	#INSTALL_COMMAND ""
	#)

#ExternalProject_Get_Property(googletest binary_dir)
#add_library(gtest UNKNOWN IMPORTED)
#add_library(gtest_main UNKNOWN IMPORTED)
#set_target_properties(gtest PROPERTIES IMPORTED_LOCATION ${binary_dir}/libgtest.a)
#set_target_properties(gtest_main PROPERTIES IMPORTED_LOCATION ${binary_dir}/libgtest_main.a)
#add_dependencies(gtest googletest)
#add_dependencies(gtest_main googletest)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
	WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
	WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
	"${CMAKE_BINARY_DIR}/googletest-build")

enable_testing()
#find_package(GTest MODULE REQUIRED)
#target_link_libraries(main PRIVATE GTest::GTest GTest::Main)
#add_test(AllTestsInMain main)

