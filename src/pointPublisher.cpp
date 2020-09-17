#include "ros/ros.h"

#include "geometry_msgs/Point.h"
#include <string>

#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "point_publisher");
    ros::NodeHandle n("~");

    ros::Publisher threePointPublisher = n.advertise<geometry_msgs::Point>("three_point", 1000);
    //ros::Rate loop_rate(10);

    while(ros::ok())
    {
        

        //ROS_INFO("%s", msg.data.c_str());
        std::cout << "give 3 3D point :" << std::endl;

        std::string param;
        std::cin >> param;

        geometry_msgs::Point point;

        threePointPublisher.publish(point);
    }

    return 0;
}