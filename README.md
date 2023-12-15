# enumerate_package

## Description:

ROS2 package to enumerate a LUCID Vision camera(s).

This package uses the Arena SDK to detect a device(s) and displays its information (e.g., vendor, model, serial, MAC, and IP)

## Requirements:

* Ubuntu Focal Fossa
* ROS2 Foxy Fitzroy
* Arena SDK for Linux
* C++17 or higher

## To Use:
**_Before Use:_** 
* **These steps assume you have already created a workspace folder and a `/src` directory within it!**

**_Steps:_**
1. Navigate into the `\src` directory of your workspace and clone the repo using `git clone`
2. Navigate back into the workspace directory and source `$ source /opt/ros/foxy/setup.bash`
3. Build package `$ colcon build` or `$ colcon build --packages-select <package_name>`
4. Open a new terminal and source it `$ . install/setup.bash`
5. Run executable `$ ros2 run <package_name> <executable_name>` in this case, it is `$ ros2 run enumerate_package enumerate`