#include "ros/ros.h"

#include "geometry_msgs/Point.h"
#include "integrationTest/triangle_point.h"
#include "integrationTest/triangle_area.h"

#include "integrationTest/triangle_area_resolver.h"

bool consoleAskDimensionValue(const std::string& coutStr, double& number)
{
    std::cout << coutStr << std::endl;

    std::string input;
    std::cin >> input;

    number = atof(input.c_str());

    return ros::ok();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "triangle_3d_points_teleop");
    ros::NodeHandle n;

    // triangle_3d_points Publisher
    ros::Publisher threePointPublisher = n.advertise<integrationTest::triangle_point>("triangle_3d_points", 1000);
    // triangle_area Publisher
    ros::Publisher triangleAreaPublisher = n.advertise<integrationTest::triangle_area>("triangle_area", 1000);

    // triangle_area_resolver Service client
    ros::ServiceClient triangleAreaResolverclient = n.serviceClient<integrationTest::triangle_area_resolver>("triangle_area_resolver");

    while(ros::ok())
    {
        //Triangle 3d point message to publish
        integrationTest::triangle_point trianglePointMsg;

        //3d point A
        geometry_msgs::Point a;
        if(!consoleAskDimensionValue("Point A, dimension x = ", a.x)) break;
        if(!consoleAskDimensionValue("Point A, dimension y = ", a.y)) break;
        if(!consoleAskDimensionValue("Point A, dimension z = ", a.z)) break;
        trianglePointMsg.a = a;

        //3d point B
        geometry_msgs::Point b;
        if(!consoleAskDimensionValue("Point B, dimension x = ", b.x)) break;
        if(!consoleAskDimensionValue("Point B, dimension y = ", b.y)) break;
        if(!consoleAskDimensionValue("Point B, dimension z = ", b.z)) break;
        trianglePointMsg.b = b;

        //3d point C
        geometry_msgs::Point c;
        if(!consoleAskDimensionValue("Point C, dimension x = ", c.x)) break;
        if(!consoleAskDimensionValue("Point C, dimension y = ", c.y)) break;
        if(!consoleAskDimensionValue("Point C, dimension z = ", c.z)) break;
        trianglePointMsg.c = c;

        threePointPublisher.publish(trianglePointMsg);
        
        //Create triangle_area_resolver srv with triangle_3d_points msg
        integrationTest::triangle_area_resolver srv;
        srv.request.a = a;
        srv.request.b = b;
        srv.request.c = c;
        
        if (triangleAreaResolverclient.call(srv))
        {
            integrationTest::triangle_area triangleAreaMsg;
            triangleAreaMsg.area = srv.response.area;
            triangleAreaPublisher.publish(triangleAreaMsg);
        }
    }

    return 0;
}