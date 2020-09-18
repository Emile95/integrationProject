#include "ros/ros.h"

#include "geometry_msgs/Point.h"
#include "integrationTest/triangle_point.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "point_publisher");
    ros::NodeHandle n;

    ros::Publisher threePointPublisher = n.advertise<integrationTest::triangle_point>("three_point", 1000);

    while(ros::ok())
    {
        std::cout << "type 'send' to publish triangle 3D point" << std::endl;
        std::string input;
        std::cin >> input;

        if(input != "send") continue;

        integrationTest::triangle_point msg;
        
        geometry_msgs::Point p1;
        p1.x = 5.23;
        p1.y = 7.678;
        p1.z = 8.689;
        msg.a = p1;

        geometry_msgs::Point p2;
        p2.x = 1.4567;
        p2.y = 10.23;
        p2.z = 23.5;
        msg.b = p2;

        geometry_msgs::Point p3;
        p3.x = 5.78;
        p3.y = 3.23;
        p3.z = 7.67;
        msg.c = p3;

        threePointPublisher.publish(msg);
    }

    return 0;
}