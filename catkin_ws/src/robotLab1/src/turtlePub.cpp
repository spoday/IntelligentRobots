#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include "ros/console.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlePub");
  ros::NodeHandle n;
 // ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
 //  ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
  ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 1);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    geometry_msgs::Twist velPara;

    velPara.angular.z = -10;
    velPara.linear.x = 10;

    ROS_INFO("Sending command...\n");

    vel_pub.publish(velPara);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}

