import rclpy
from rclpy.node import Node

from std_msgs.msg import String

from ctypes import CDLL, RTLD_GLOBAL, byref, c_char_p, c_int, c_int32, c_uint32, c_ushort, c_void_p, create_string_buffer

CDLL("libftd2xx.so", mode=RTLD_GLOBAL)

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('ocktabot_motor_thread')

        self.declare_parameter('epos_nodes',(1,2,3))
        self.declare_parameter('motor_profile',(500,1000,1000))

        self.epos = CDLL("libEposCmd.so")
        self.epos.VSC_OpenDevice.restype = c_void_p
        self.epos.VSC_OpenDevice.argtypess = [c_char_p, c_char_p, c_char_p, c_char_p, c_void_p]

        self.err - c_uint32()
        
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1

    def motor_check(ok, what):
        if not ok:
            buf = create_string_buffer(256)
            self.epos.VCS_GetErrorInfo(c_uint32())


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()