#include "ros/ros.h"
#include "topic_tutorial/MsgTutorial.h"

int main(int argc, char** argv) {
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh;

  // topic name = ros_tutorial_msg
  // queue size = 100
  ros::Publisher pub = nh.advertise<topic_tutorial::MsgTutorial>("ros_tutorial_msg", 100);

  // scale_of_hz = 1
  // 1초 간격으로 처리가 반복된다
  ros::Rate loop_rate(1);
  topic_tutorial::MsgTutorial msg;
  int count = 0;

  while (ros::ok()) {
    msg.stamp = ros::Time::now();
    msg.data = count;

    ROS_INFO("send msg = %d", msg.stamp.sec);
    ROS_INFO("send msg = %d", msg.stamp.nsec);
    ROS_INFO("send msg = %d", msg.data);

    pub.publish(msg);
    loop_rate.sleep();
    count++;
  }
  return 0;
}