#include "ros/ros.h"

#include <cmath>

#include "geometry_msgs/Point.h"
#include "integrationTest/triangle_area_resolver.h"

bool resolveArea(
    integrationTest::triangle_area_resolver::Request  &req,
    integrationTest::triangle_area_resolver::Response &res
)
{
    res.area = 0.5 * sqrt(
        pow((req.b.x * req.a.y) - (req.c.x * req.a.y) - (req.a.x * req.b.y) + (req.c.x * req.b.y) + (req.a.x * req.c.y) - (req.b.x * req.c.y), 2) +
        pow((req.b.x * req.a.z) - (req.c.x * req.a.z) - (req.a.x * req.b.z) + (req.c.x * req.b.z) + (req.a.x * req.c.z) - (req.b.x * req.c.z), 2) +
        pow((req.b.y * req.a.z) - (req.c.y * req.a.z) - (req.a.y * req.b.z) + (req.c.y * req.b.z) + (req.a.y * req.c.z) - (req.b.y * req.c.z), 2)
    );

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