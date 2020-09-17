#include "ros/ros.h"

#include "geometry_msgs/Point.h"
#include "integrationTest/triangle_point.h"

#include <string>

#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "point_publisher");
    ros::NodeHandle n("~");

    //three_point topic publisher
    ros::Publisher threePointPublisher = n.advertise<integrationTest::triangle_point>("three_point", 1000);

    while(ros::ok())
    {
        //ROS_INFO("%s", msg.data.c_str());
        std::cout << "give three 3D point : [ 0.0 , 0.0, 0.0 ] , [ 1.0, 1.0, 1.0 ] , [ 2.0, 2.0, 2.0 ]" << std::endl;

        std::string input;
        std::cin >> input;

        integrationTest::triangle_point points;

        threePointPublisher.publish(points);
    }

    return 0;
}