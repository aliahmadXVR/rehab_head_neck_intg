/**
 * @file pan_int.cpp
 * @author Ali Ahmad ali.ahmad@xavor.com)
 * @brief 
 * This file is used to create a two way communication with PAN/TILT
 * mechanism.
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "rehab_head_neck_intg/pan_tilt.h"
#include "rehab_head_neck_intg/pan_tilt_feedback.h"

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "pan_tilt_int");
  ros::NodeHandle n;

  ros::Publisher pan_tilt_cmd_pub = n.advertise<rehab_head_neck_intg::pan_tilt>("pan_tilt_cmd", 1000);
  ros::Publisher pan_tilt_feedback = n.advertise<rehab_head_neck_intg::pan_tilt_feedback>("pan_tilt_feedback", 1000);

  ros::Rate loop_rate(10);

  
  int count = 0;
  while (ros::ok())
  {
    rehab_head_neck_intg::pan_tilt motion_msg;
    rehab_head_neck_intg::pan_tilt_feedback feedback_msg;

    int value;;
    std::cout<<"Enter Value: "<<std::endl;
    std::cin>> value;

    motion_msg.pan_angle = {-30,30};
    motion_msg.tilt_angle= {0, 0};
    
    
    feedback_msg.pan_feedback = true;
    feedback_msg.tilt_feedback = false;

    if (value == 1)
    {
      pan_tilt_cmd_pub.publish(motion_msg);
      pan_tilt_feedback.publish(feedback_msg);
      ros::spinOnce();
    }

    
    loop_rate.sleep();
    ++count;
  }


  return 0;
}