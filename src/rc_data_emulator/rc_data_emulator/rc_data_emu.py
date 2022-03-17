# -*- coding: utf-8 -*-

import rclpy
from std_msgs.msg import String
from std_msgs.msg import Bool
from std_msgs.msg import Float32
from rc_data_emulator.rc_emu_module import *
#from abds_core_common.msg import VehicleCommand
g_node = None

ip_address='195.0.1.1'
ushmfile = r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'
dpr = DPRclient(ip_address, ushmfile)


# pylint: enable=attribute-defined-outside-init




def vcmd_callback(msg):
    global g_node
    g_node.get_logger().info(
        'Received new desired speed percentage: "%d"' % msg.data)
    dpr.set_var('pmSetOverrideSpeed', 1)
    dpr.set_var('pmDesiredOverrideSpeed', msg.data)
    pmDesiredOverrideSpeed = dpr.get_var('pmDesiredOverrideSpeed')
    print(pmDesiredOverrideSpeed)

def abort_cmd_callback(msg):
    global g_node
    print("Current abort command received", msg.data)
    g_node.get_logger().info(
        'Current abort command received: "%d"' % msg.data)
    autonomousCommand= dpr.get_var('autonomousCommand')

    if msg.data:
        dpr.set_var('autonomousCommand', 4)
        autonomousCommand= dpr.get_var('autonomousCommand')
        print(autonomousCommand)
    else:
        if (autonomousCommand != 0):
            dpr.set_var('autonomousCommand', 0)


def main(args=None):

    global g_node
    rclpy.init(args=args)
    g_node = rclpy.create_node('vcmd_subscriber')

    vcmd_sub = g_node.create_subscription(Float32, 'vcmd', vcmd_callback, 10)
    vcmd_sub # prevent unused variable warning
    abort_cmd_sub = g_node.create_subscription(Bool, 'abort_cmd', abort_cmd_callback, 10)
    abort_cmd_sub # prevent unused variable warning

    #test_dpr()

    while rclpy.ok():
        rclpy.spin_once(g_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    g_node.destroy_node()
    rclpy.shutdown()




if __name__ == "__main__":
    main()
    # test_dpr(sys.argv[1], sys.argv[2])
