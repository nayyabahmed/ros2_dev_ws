import rclpy
import math
from time import sleep
from ether_follow_interfaces.msg import EtherMessage

def main(args=None):
    rclpy.init(args=args)

    node = rclpy.create_node('efollow_pub')
    ether_pub = node.create_publisher(EtherMessage, 'ether_follow', 10)

    counter=1

    msg = EtherMessage()
    msg.ip_address = '195.0.1.1'   #Ip address of the Robot controller used
    msg.version = 2
    msg.brake_cmd = 0.0
    msg.accel_cmd = 10.0
    msg.gear_cmd = 0

    while rclpy.ok():
        st= 100*( math.sin( (counter/100) * 2 * (math.pi) ) )
        counter+=1
        msg.steering_cmd = st

        ether_pub.publish(msg)
        print("Publishing to version:{} message number{}".format(msg.version,counter) )
        sleep(.05)  # seconds

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
