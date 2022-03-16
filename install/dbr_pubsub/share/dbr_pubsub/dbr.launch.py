from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld= LaunchDescription()

    dbr_pub_node = Node(
        package ="dbr_pubsub",
        executable = "dbr_pub",
        parameters = [
            {'ip_address': '195.0.1.1'},
            {'frequency': 50},
            {'port': 2000}
        ]
    )

    ld.add_action(dbr_pub_node)

    return ld
