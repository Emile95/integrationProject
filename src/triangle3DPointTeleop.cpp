#include "ros/ros.h"

#include "geometry_msgs/Point.h"
#include "integrationTest/triangle_point.h"
#include "integrationTest/triangle_area.h"

#include "integrationTest/triangle_area_resolver.h"

bool consoleAskDimensionValue(const std::string& coutStr, double& number)
{
    std::cout << coutStr;
    std::string input;
    std::cin >> input;

    number = atof(input.c_str());

    return ros::ok();
}

bool consoleAsk3dDPoint(const std::string& pointName, geometry_msgs::Point& point) 
{
    std::string consoleOut = "Point " + pointName +  ", dimension ";
    if(!consoleAskDimensionValue(consoleOut + "x = ", point.x)) return false;
    if(!consoleAskDimensionValue(consoleOut + "y = ", point.y)) return false;
    if(!consoleAskDimensionValue(consoleOut + "z = ", point.z)) return false;
    return true;
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

        //Ask for 3 3D points
        //Handle ctrl+c between dimension of each points
        if(!consoleAsk3dDPoint("A", trianglePointMsg.a)) break;
        if(!consoleAsk3dDPoint("B", trianglePointMsg.b)) break;
        if(!consoleAsk3dDPoint("C", trianglePointMsg.c)) break;

        threePointPublisher.publish(trianglePointMsg);
        std::cout << "publish triangle 3d points on /triangle_3d_points topic" << std::endl;
        
        //Create triangle_area_resolver srv with triangle_3d_points msg
        integrationTest::triangle_area_resolver srv;
        srv.request.a = trianglePointMsg.a;
        srv.request.b = trianglePointMsg.b;
        srv.request.c = trianglePointMsg.c;
        
        if (triangleAreaResolverclient.call(srv))
        {
            std::cout << "publish triangle area on /triangle_area topic" << std::endl;
            integrationTest::triangle_area triangleAreaMsg;
            triangleAreaMsg.area = srv.response.area;
            triangleAreaPublisher.publish(triangleAreaMsg);
        }
        std::cout << "---------------------------" << std::endl;
    }

    return 0;
}