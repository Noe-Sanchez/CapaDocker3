#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class simple_publisher : public rclcpp::Node{
  public:
    simple_publisher(): Node("publisher_node"){

      string_publisher = this->create_publisher<std_msgs::msg::String>("/docker3", 10);
      control_timer = this->create_wall_timer(1s, std::bind(&simple_publisher::control_callback, this));

    }

    void control_callback(){

      msg.data = "Hello World " + std::to_string(counter);
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
      string_publisher->publish(msg);
      counter++;

    }

  private:
    int counter = 0;
    std_msgs::msg::String msg;

    rclcpp::TimerBase::SharedPtr control_timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr string_publisher; 

};

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<simple_publisher>());
  rclcpp::shutdown();
  return 0;
}
