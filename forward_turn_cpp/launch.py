# Copyright 2024 Intelligent Robotics Lab
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    forward_turn_cmd = Node(
        package='forward_turn_cpp',
        executable='forward',
        output='screen',
        parameters=[{'use_sim_time': True}],
        remappings=[
            ('l_vel_', '/cmd_vel'),
            ('a_vel_', '/cmd_vel'),
        ]
    )

    ld = LaunchDescription()
    ld.add_action(forward_turn_cmd)

    return ld