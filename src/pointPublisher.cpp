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

        integrationTest::triangle_point msg;

        //msg.triangle_point_ = new geometry_msgs::Point[] { { 1.0, 1.0, 1.0 }, { 2.0, 2.0, 2.0 }, { 3.0, 3.0, 3.0 } };

        geometry_msgs::Point p1;
        p1.x = 1.0;
        p1.y = 1.0;
        p1.z = 1.0;
        msg.a = p1;

        geometry_msgs::Point p2;
        p2.x = 1.0;
        p2.y = 1.0;
        p2.z = 1.0;
        msg.b = p2;

        geometry_msgs::Point p3;
        p3.x = 1.0;
        p3.y = 1.0;
        p3.z = 1.0;
        msg.c = p3;

        threePointPublisher.publish(msg);
    }

    return 0;
}