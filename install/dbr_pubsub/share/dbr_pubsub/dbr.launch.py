from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld= LaunchDescription()

    dbr_pub_node = Node(
        package ="dbr_pubsub",
        executable = "dbr_pub",
        parameters = [
            {'ip_address': '195.0.1.1'},
            {'frequency': 10},
            {'port': 2000}
        ]
    )

    dbr_emu_node = Node(
        package ="dbr_pubsub",
        executable = "rc_emu",
        parameters = [
            {'ip_address': '195.0.1.1'},
            {'ushm_file':  r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'}
        ]
    )



    ld.add_action(dbr_pub_node)
    ld.add_action(dbr_emu_node)

    return ld
