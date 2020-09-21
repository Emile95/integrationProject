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
  triangle_area.msg
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


add_executable(triangle_3d_points_teleop src/triangle3DPointTeleop.cpp)
target_link_libraries(triangle_3d_points_teleop ${catkin_LIBRARIES})
add_dependencies(triangle_3d_points_teleop integrationTest_generate_messages_cpp)

add_executable(triangle_area_resolver src/triangleAreaResolver.cpp)
target_link_libraries(triangle_area_resolver ${catkin_LIBRARIES})
add_dependencies(triangle_area_resolver integrationTest_generate_messages_cpp)