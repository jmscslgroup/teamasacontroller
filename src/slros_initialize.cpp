#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "teamasacontroller";

// For Block teamasacontroller/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamasacontroller_std_msgs_Float64> Sub_teamasacontroller_33;

// For Block teamasacontroller/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamasacontroller_std_msgs_Float64> Sub_teamasacontroller_34;

// For Block teamasacontroller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_teamasacontroller_std_msgs_Float64> Pub_teamasacontroller_31;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

