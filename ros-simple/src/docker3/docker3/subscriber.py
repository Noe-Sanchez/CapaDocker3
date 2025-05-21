#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import time
import math

class SimpleSubscriber(Node):
  def __init__(self) -> None:
    super().__init__('SimpleSubscriber')
    
    self.string_subscriber = self.create_subscription(String, '/docker3', self.listener_callback, 10)

  def listener_callback(self, msg):
    self.get_logger().info('Received message: "%s"' % msg.data)

def main(args=None) -> None:
    print('Starting simple subscriber node...')
    rclpy.init(args=args)
    simple_subscriber = SimpleSubscriber()
    rclpy.spin(simple_subscriber)
    simple_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        print(e)
