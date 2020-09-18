cmake_minimum_required(VERSION 3.0.2)
project(integrationTest)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  geometry_msgs
)

add_message_files(
  FILES
  triangle_point.msg
)

add_service_files(
   FILES
   triangle_area_resolver.srv
)

generate_messages(
  DEPENDENCIES
  geometry_msgs
)


catkin_package(
   CATKIN_DEPENDS geometry_msgs roscpp std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(pointPublisher src/pointPublisher.cpp)
target_link_libraries(pointPublisher ${catkin_LIBRARIES})
add_dependencies(pointPublisher integrationTest_generate_messages_cpp)

add_executable(triangleAreaResolver src/triangleAreaResolver.cpp)
target_link_libraries(triangleAreaResolver ${catkin_LIBRARIES})
add_dependencies(triangleAreaResolver integrationTest_generate_messages_cpp)