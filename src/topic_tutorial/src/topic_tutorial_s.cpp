#include "ros/ros.h"
#include "topic_tutorial/MsgTutorial.h"

void msgCallback(const topic_tutorial::MsgTutorial::ConstPtr& msg) {
  ROS_INFO("receive msg = %d", msg->stamp.sec);
  ROS_INFO("receive msg = %d", msg->stamp.nsec);
  ROS_INFO("receive msg = %d", msg->data);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh;
  // topic name = ros_tutorial_msg <- topic_publisher가 발행한 topic 이름과 같아야 합니다.
  // queue size = 100
  // callback = msgCallback <- 메시지를 받으면 실행됩니다.
  ros::Subscriber sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

  // 메시지를 받을 때까지 대기합니다.
  // 메시지를 받으면 subscriber의 callback을 실행합니다.
  ros::spin();
  return 0;
}