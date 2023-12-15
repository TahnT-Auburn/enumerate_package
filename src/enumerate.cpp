//C++
#include <algorithm>

//ROS2
#include "rmw/types.h"
#include "enumerate.h"

//Update timeout
    /*
    Timeout for updating the list of devices (in milliseconds).
    This sets a time to detect all possible devices, not returning
    early as devices are found
    */
#define SYSTEM_TIMEOUT 100

void Enumerate::enumerateDevices()
//Enumerate Devices
    /*
    (1) Opens system
    (2) Updates and gets device list
    (3) Prints device information and saves device serial number
    (4) Create device with serial number and destroy device
    */
{   
    //Log current function
    RCLCPP_INFO(this->get_logger(), "Enumerating Devices ...");

    //Open system
    Arena::ISystem* pSystem = Arena::OpenSystem();
    RCLCPP_INFO(this->get_logger(), "System opened");

    //Update and retrieve device list
    pSystem->UpdateDevices(SYSTEM_TIMEOUT);
    std::vector<Arena::DeviceInfo> deviceInfos = pSystem->GetDevices();
    RCLCPP_INFO(this->get_logger(), "Devices retrieved");

    //Get info on connected devices (save serial for device search)
    GenICam::gcstring serialToFind = "00000";

    for (size_t i = 0; i < deviceInfos.size(); i++)
    {
        //Save first serial number
        if (i == 0)
        {
            serialToFind = deviceInfos[i].SerialNumber();
        }

        //Display device information
        GenICam::gcstring vendor = deviceInfos[i].VendorName();
        GenICam::gcstring model = deviceInfos[i].ModelName();
        GenICam::gcstring serial = deviceInfos[i].SerialNumber();
        GenICam::gcstring macStr = deviceInfos[i].MacAddressStr();
        GenICam::gcstring ipStr = deviceInfos[i].IpAddressStr();
        RCLCPP_INFO(this->get_logger(), "\nDevice %d:\n %s\n Model: %s\n Serial: %s\n Mac: %s\n IP: %s\n",
            i+1,
            vendor.c_str(),
            model.c_str(),
            serial.c_str(),
            macStr.c_str(),
            ipStr.c_str());
    }
    RCLCPP_INFO(this->get_logger(), "All devices completed");

    //Close system
    Arena::CloseSystem(pSystem);
    RCLCPP_INFO(this->get_logger(), "System Closed");
    
}