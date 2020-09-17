#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include <string>

#include <sstream>
#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "point_publisher");
    ros::NodeHandle n;

    ros::Publisher treePointPublisher = n.advertise<geometry_msgs::Point>("three_point", 1000);
    ros::Rate loop_rate(10);

    int count = 0;
    while(ros::ok())
    {
        geometry_msgs::Point point;

        //ROS_INFO("%s", msg.data.c_str());

        treePointPublisher.publish(point);
        ros::spinOnce();

        loop_rate.sleep();

        ++count;
    }

    return 0;
}