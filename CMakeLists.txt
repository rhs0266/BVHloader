cmake_minimum_required(VERSION 3.0)
project(BVH_exe)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

file(GLOB srcs "*.h" "*.cpp")
add_executable(BVH_exe ${srcs})
target_link_libraries (BVH_exe ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES} Eigen3::Eigen)

#cmake_minimum_required(VERSION 2.80)
#project(CartPole)
#add_compile_options(-std=gnu++11)
#add_compile_options(-Wdeprecated-declarations)
#
#set(CMAKE_CXX_STANDARD 11)
#
#add_subdirectory( engine )
#
#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#find_package(PythonInterp)
#find_package(PythonLibs)
#find_package(Boost 1.45.0 COMPONENTS filesystem regex python)
#find_package(DART REQUIRED COMPONENTS gui optimizer-ipopt CONFIG)
#
#include_directories(${CMAKE_SOURCE_DIR})
#include_directories(${OPENGL_INCLUDE_DIR})
#include_directories(${GLUT_INCLUDE_DIR})
#include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${PYTHON_INCLUDE_DIRS})
#include_directories(${DART_INCLUDE_DIRS})
#
#link_directories(./engine/)
#add_executable(CartPole main.cpp)
#target_link_libraries(CartPole ${DART_LIBRARIES} ${Boost_LIBRARIES} engine)
#
######################################
#project(render)
#file(GLOB render_srcs "render/*.h" "render/*.cpp")
#add_executable(render ${render_srcs})
#target_link_libraries(render ${DART_LIBRARIES} ${Boost_LIBRARIES} engine)
#
######################################
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/py_code)
#project(cp)
#file(GLOB vpc_srcs "vpc/*.h" "vpc/*.cpp")
#add_library(cp SHARED ${vpc_srcs})
#target_link_libraries(cp ${DART_LIBRARIES} ${Boost_LIBRARIES} engine)
#set_target_properties(cp PROPERTIES PREFIX "" )
