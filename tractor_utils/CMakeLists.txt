cmake_minimum_required(VERSION 3.0.2)
project(tractor_utils)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  std_msgs
  tf
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tractor_utils
 CATKIN_DEPENDS nav_msgs roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(baselink_Tf_node src/tf_publisher.cc)
target_link_libraries(baselink_Tf_node ${catkin_LIBRARIES})
add_dependencies(baselink_Tf_node ${catkin_EXPORTED_TARGETS})

