from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld= LaunchDescription()

    dbr_emu_node = Node(
        package ="rc_data_emulator",
        executable = "rc_emu",
        parameters = [
            {'ip_address': '195.0.1.1'},
            {'ushm_file':  r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'}
        ]
    )

    ld.add_action(dbr_emu_node)

    return ld
