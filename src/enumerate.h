#pragma once

//ROS2
#include <rclcpp/rclcpp.hpp>
//ArenaSDK
#include "ArenaApi.h"

class Enumerate : public rclcpp::Node
{
public:
    Enumerate()
    : Node("enumerate")
    {
        enumerateDevices();
    }
private:
    void enumerateDevices();
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    {
        auto node = std::make_shared<Enumerate>();
        rclcpp::spin(node);        
    }
    rclcpp::shutdown();
    return 0;
}
