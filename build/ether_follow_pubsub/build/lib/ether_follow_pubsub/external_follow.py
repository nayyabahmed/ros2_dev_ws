import rclpy
from ether_follow_interfaces.msg import EtherMessage
from ether_follow_pubsub.external_follow_module import *


def efollow_callback(data):
    ref = ExternalFollowing(data.ip_address)
    start = False
    ref.send(steer   =data.steering_cmd,
             throttle=data.accel_cmd,
             brake   =data.brake_cmd,
             gear   =data.gear_cmd,
             start_test=start)
    print("Message received")

def main(args=None):
    rclpy.init(args=args)
    g_node = rclpy.create_node('ext_follow')
    print("Waiting for publisher to 'external_follow' topic with ip address and message info ...")
    print("Please remember to publish at more than 10 hz")

    subscription = g_node.create_subscription(EtherMessage, 'ether_follow', efollow_callback, 10)
    subscription  # prevent unused variable warning

    while rclpy.ok():
        rclpy.spin_once(g_node)



if __name__ == "__main__":
    main()
