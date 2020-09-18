#include "ros/ros.h"

#include "geometry_msgs/Point.h"
#include "integrationTest/triangle_area_resolver.h"

bool resolveArea(
    integrationTest::triangle_area_resolver::Request  &req,
    integrationTest::triangle_area_resolver::Response &res
)
{
    res.area = 0.0;
    return true;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "triangle_area_resolver");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("triangle_area_resolver", resolveArea);

    ros::spin();

    return 0;
}