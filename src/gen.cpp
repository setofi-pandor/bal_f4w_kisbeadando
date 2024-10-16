#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>  // Include for the sin() function

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;

class GenSineAndRand : public rclcpp::Node
{
public:
    GenSineAndRand(): Node("gen_node"), count_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Generating reflected sine and random numbers");
        pub1_ = this->create_publisher<std_msgs::msg::Float32>("sine", 10);
        pub2_ = this->create_publisher<std_msgs::msg::Float32>("rand", 10);
        timer_ = this->create_wall_timer(50ms, std::bind(&GenSineAndRand::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message_sin = std_msgs::msg::Float32();
        auto message_rnd = std_msgs::msg::Float32();
        
        // Reflected sine (y-axis mirrored): sin(-x)
        message_sin.data = sin(-2*(count_ / 50.0)) * 100;  // Negate the argument to reflect the sine wave
        message_rnd.data = rand() % 5;

        pub1_->publish(message_sin);
        pub2_->publish(message_rnd);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub1_, pub2_;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GenSineAndRand>());
    rclcpp::shutdown();
    return 0;
}
