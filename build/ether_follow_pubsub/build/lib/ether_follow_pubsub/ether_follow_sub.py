import rclpy
import struct
import socket
from ether_follow_interfaces.msg import EtherMessage

data_struct = struct.Struct("< 2B H L 3d 2H L B b H L")
#Creating dictionary for parameter values assignment
param=['Version','Spare1','Spare2','MessageNo','SteeringCommand', 'BrakeCommand',
        'AccelCommand','ExternalComms','Triggering','Spare3','Watchdog','GearCommand','Spare5','Spare6']

values = [0 for x in range( len(param) )]
values_dict= dict(zip(param, values))

sock= socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
port =8000
count = 1


def efollow_callback(data):
    global count
    ip_addr= data.ip_address
    values_dict["Version"]= data.version
    values_dict["SteeringCommand"]= data.steering_cmd
    values_dict["BrakeCommand"]= data.brake_cmd
    values_dict["AccelCommand"]= data.accel_cmd
    values_dict["GearCommand"]= data.gear_cmd
    values_dict["MessageNo"]= count
    count +=1
    # print(values_dict)
    print( *values_dict.values() )

    msg_to_rc = data_struct.pack( *values_dict.values() )

    sock.sendto(msg_to_rc, (ip_addr,port) )

    print("Message number:", count)
    print("Message sent to ip: {}, port number{} of lenght:{}".format( ip_addr, port , len(msg_to_rc) ) )
    #rospy.loginfo("The version number is:%d" %values_dict["Version"] )


def main(args=None):
    rclpy.init(args=args)
    g_node = rclpy.create_node('efollow')


    print("UDP socket created at port",port)
    print("Waiting for publisher to 'ether_follow' topic with ip address and message info ...")
    print("Please remember to publish at more than 10 hz")


    subscription = g_node.create_subscription(EtherMessage, 'ether_follow', efollow_callback, 10)
    subscription  # prevent unused variable warning

    while rclpy.ok():
        rclpy.spin_once(g_node)


if __name__ == '__main__':
    main()
