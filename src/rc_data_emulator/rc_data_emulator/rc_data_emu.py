# -*- coding: utf-8 -*-
import rclpy
from time import sleep
from rclpy.node import Node
# from std_msgs.msg import String
from std_msgs.msg import Bool
from std_msgs.msg import Float32
from rc_interfaces.msg import RcStatus

from rc_data_emulator.rc_emu_module import *

#from abds_core_common.msg import VehicleCommand
# ip_address='195.0.1.1'
# ushmfile = r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'
# dpr = DPRclient(ip_address, ushmfile)

# pylint: enable=attribute-defined-outside-init




class DataEmu(Node):
    def __init__(self):
        super().__init__('data_emu_node')
        self.vcmd_sub_      =self.create_subscription(Float32, 'vcmd', self.vcmd_callback, 10)
        self.abort_cmd_sub_ =self.create_subscription(Bool, 'abort_cmd', self.abort_cmd_callback, 10)
        self.rc_status_sub_ =self.create_subscription(RcStatus, 'rc_status', self.rc_status_callback, 10)

        self.declare_parameter('ip_address')
        self.declare_parameter('ushm_file')
        self.abort_flag =False

        # self.s_data= struct.Struct('<3fI') #structure object for packed data
        #
        # self.ip_address='195.0.1.1'
        self.ip_address =self.get_parameter('ip_address').get_parameter_value().string_value
        self.ushmfile   = self.get_parameter('ushm_file').get_parameter_value().string_value
        # self.ushmfile = r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'
        self.dpre = DPRclient(self.ip_address, self.ushmfile)

    def rc_status_callback(self,msg):
        test_state= int.from_bytes(msg.dl_test_procedure_state,"big")
        test_phase = msg.mpf_phase
        # print("Test state is:",int.from_bytes(test_state,"big"))
        # print("Test phase is:",test_phase)
        #condions
        rapid_stopping=8
        e_stopping =9
        not_active =0

        br_doing_abort_stop= -16
        br_abort_from_cs = -15
        inactive= -99

        if (test_state==rapid_stopping):
            self.abort_flag =False
        elif (test_state==e_stopping):
            self.abort_flag =False
        elif (test_state==not_active):
            self.abort_flag =False
        elif (test_phase==br_doing_abort_stop):
            self.abort_flag =False
        elif (test_phase==br_abort_from_cs):
            self.abort_flag =False
        elif(test_phase==inactive):
            self.abort_flag =False
        else:
            self.abort_flag =True

    def vcmd_callback(self,msg):
        self.get_logger().info(
            'Received desired speed percentage: "%d"' % msg.data)

        current_override_speed = self.dpre.get_var('pmDesiredOverrideSpeed')
        print("Current overide speed:",current_override_speed)

        if ((msg.data>=0) and  (msg.data<=100)):  #check if given overide speed is within the range
            if (current_override_speed!=msg.data):
                self.dpre.set_var('pmDesiredOverrideSpeed', msg.data)
                current_override_speed=self.dpre.get_var('pmDesiredOverrideSpeed')
                self.get_logger().info("Current overide speed after setting is %d" % current_override_speed)
                self.dpre.set_var('pmSetOverrideSpeed', 1)




    def abort_cmd_callback(self,msg):
        # print("Current abort command received", msg.data)
        self.get_logger().info(
            'Current abort command received: "%d"' % msg.data)

        autonomousCommand= self.dpre.get_var('autonomousCommand')

        # if (self.abort_flag):
        #     print("abort flag is true")
        # else:
        #     print("abort flag is false")
        if (autonomousCommand!=4):
            if (msg.data and self.abort_flag): # cehck if both conditions are true
                # print("setting autonomousCommand to:",4)
                self.get_logger().info(
                    'Setting autonomousCommand to: "%d"' % 4)
                self.dpre.set_var('autonomousCommand', 4)

                # autonomousCommand=self.dpre.get_var('autonomousCommand')
                # print(autonomousCommand)
            # else:
            #     if (autonomousCommand != 0):
            #         self.dpre.set_var('autonomousCommand', 0)





def main(args=None):
    rclpy.init(args=args)
    node= DataEmu()
    rclpy.spin(node)

    g_node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
    # test_dpr(sys.argv[1], sys.argv[2])
