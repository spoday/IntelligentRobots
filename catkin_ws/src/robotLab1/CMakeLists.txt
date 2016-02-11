cmake_minimum_required(VERSION 2.8.3)
project(robotLab1)

find_package(catkin REQUIRED COMPONENTS
	roscpp rospy std_msgs genmsg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package()

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtlePub src/turtlePub.cpp)
target_link_libraries(turtlePub ${catkin_LIBRARIES})
add_dependencies(turtlePub robotLab1_generate_messages_cpp)
