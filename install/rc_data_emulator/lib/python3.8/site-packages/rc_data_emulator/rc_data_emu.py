# -*- coding: utf-8 -*-

import rclpy
from std_msgs.msg import String
from std_msgs.msg import Float32
from rc_data_emulator.rc_emu_module import *
#from abds_core_common.msg import VehicleCommand
g_node = None

ip_address='195.0.1.1'
ushmfile = r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'
dpr = DPRclient(ip_address, ushmfile)


# pylint: enable=attribute-defined-outside-init

def test_dpr():
    """Test function for DPRclient class."""
    # ip_address='195.0.1.1'
    # ushmfile = r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'
    #
    # dpr = DPRclient(ip_address, ushmfile)
    print(dpr.endianness)
    print(dpr['iDigTrigCAN15'])
    dpr['iDigTrigCAN15'] = True
    print(dpr['iDigTrigCAN15'])

    print(dpr.system('ls -l'))
    dpr.get_var('pmC_SerialNo')
    dpr.set_var('pmC_SerialNo', 1245)
    dpr.get_var('pmC_SerialNo')

    print('pmPMACbuildVersion = ' + str(dpr['pmPMACbuildVersion']))
    print('pmPMACisDevVersion = ' + str(dpr['pmPMACisDevVersion']))
    print('pmC_SerialNo = ' + str(dpr['pmC_SerialNo']))
    print('pmC_ADC8Sensitivity = ' + str(dpr['pmC_ADC8Sensitivity']))
    print('pmC_DAC1Offset = ' + str(dpr['pmC_DAC1Offset']))
    print('pmXnode = ' + str(dpr['pmXnode']))
    print('pmXnode = ' + str(dpr['pmXnode(1)']))
    dpr['pmXnode(1)'] = 123.456
    print('pmXnode = ' + str(dpr['pmXnode']))

    pmLatitudeInt = dpr.get_var('pmLatitudeInt')
    pmLatitudeFract = dpr.get_var('pmLatitudeFract')
    pmLongitudeInt = dpr.get_var('pmLongitudeInt')
    pmLongitudeFract = dpr.get_var('pmLongitudeFract')
    pmXaxisDatumBearing = dpr.get_var('pmXaxisDatumBearing')
    pmSetOverrideSpeed = dpr.get_var('pmSetOverrideSpeed')
    pmDesiredOverrideSpeed= dpr.get_var('pmDesiredOverrideSpeed')

    datumLat = pmLatitudeInt * 0.001 + pmLatitudeFract * 0.001
    datumLong = pmLongitudeInt * 0.001 + pmLongitudeFract * 0.001
    print('Datum at: ' + str(datumLat) + ':' + str(datumLong) + ' Aligned: ' + str(pmXaxisDatumBearing))


    print("The overide speed var was set to:",pmSetOverrideSpeed)
    dpr.set_var('pmSetOverrideSpeed', 1)
    pmSetOverrideSpeed = dpr.get_var('pmSetOverrideSpeed')
    print("The overide speed var is now set to:", pmSetOverrideSpeed)

    print(pmDesiredOverrideSpeed)
    dpr.set_var('pmDesiredOverrideSpeed', 30)
    pmDesiredOverrideSpeed = dpr.get_var('pmDesiredOverrideSpeed')
    print(pmDesiredOverrideSpeed)

    while True:
        serial_no = dpr['pmC_SerialNo']
        print('pmC_SerialNo = ' + str(serial_no))
        dpr['pmC_SerialNo'] = serial_no - 1
        break



def vcmd_callback(msg):
    global g_node
    g_node.get_logger().info(
        'Received new desired speed percentage: "%d"' % msg.data)

    # 
    # ip_address='195.0.1.1'
    # ushmfile = r'/home/nayab/python_programs/rc_global_def/ushm definitions.pmh'
    #
    # dpr = DPRclient(ip_address, ushmfile)
    dpr.set_var('pmSetOverrideSpeed', 1)
    dpr.set_var('pmDesiredOverrideSpeed', msg.data)
    pmDesiredOverrideSpeed = dpr.get_var('pmDesiredOverrideSpeed')
    print(pmDesiredOverrideSpeed)



def main(args=None):

    global g_node
    rclpy.init(args=args)
    g_node = rclpy.create_node('vcmd_subscriber')

    subscription = g_node.create_subscription(Float32, 'vcmd', vcmd_callback, 10)
    subscription  # prevent unused variable warning

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
