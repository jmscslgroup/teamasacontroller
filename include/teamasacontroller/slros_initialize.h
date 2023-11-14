#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "teamasacontroller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block teamasacontroller/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamasacontroller_std_msgs_Float64> Sub_teamasacontroller_33;

// For Block teamasacontroller/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamasacontroller_std_msgs_Float64> Sub_teamasacontroller_34;

// For Block teamasacontroller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_teamasacontroller_std_msgs_Float64> Pub_teamasacontroller_31;

void slros_node_init(int argc, char** argv);

#endif
