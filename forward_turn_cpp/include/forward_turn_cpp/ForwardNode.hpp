// Copyright 2024 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef FORWARD_TURN_CPP__FORWARDNODE_HPP_
#define FORWARD_TURN_CPP__FORWARDNODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/transform_listener.h"

namespace forward_turn_cpp
{

class ForwardNode : public rclcpp::Node
{
public:
  ForwardNode();

private:
  void transform_callback();
  void linear_move();

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr linear_;

  geometry_msgs::msg::Twist l_vel_;
  
  rclcpp::TimerBase::SharedPtr timer_pos_check_;
  rclcpp::TimerBase::SharedPtr timer_publish_;

  float MOVE_SPEED = 0.3;
  float STOP_SPEED = 0.0;
  
  geometry_msgs::msg::TransformStamped transform_;

  tf2::BufferCore tf_buffer_;
  tf2_ros::TransformListener tf_listener_;

  double dist;
};

}  //  namespace forward_turn_cpp

#endif  // FORWARD_TURN_CPP__FORWARDNODE_HPP_