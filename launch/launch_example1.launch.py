from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='bal_f4w_kisbeadando',
            executable='gen_node',
        ),
        Node(
            package='bal_f4w_kisbeadando',
            executable='sum_node',
        ),
    ])