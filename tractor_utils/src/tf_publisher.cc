#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

void odomCallback(const nav_msgs::Odometry::ConstPtr &msg) {
  static tf::TransformBroadcaster br;
  tf::Transform transform;

  transform.setOrigin(tf::Vector3(msg->pose.pose.position.x,
                                  msg->pose.pose.position.y,
                                  msg->pose.pose.position.z));
  transform.setRotation(tf::Quaternion(
      msg->pose.pose.orientation.x, msg->pose.pose.orientation.y,
      msg->pose.pose.orientation.z, msg->pose.pose.orientation.w));
  br.sendTransform(
      tf::StampedTransform(transform, ros::Time::now(), "world", "base_link"));
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "baselink_tf_node");
  ROS_INFO("Initializing baselink_tf_node");
  ros::NodeHandle node;
  ros::Subscriber odom_subscriber =
      node.subscribe("base_link/odometry", 10, &odomCallback);

  ros::spin();
  return 0;
};
