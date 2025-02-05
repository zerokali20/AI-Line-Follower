AI-Line-Follower
A Python- based simulation of a line-following robot using openCV and a PID controller
=======
AI Liine - Following Robot Simulation

A simple python-based simulation of a line-following robot using OpenCV 
and PID control.

📌Features

- **Detects a path using image processing.**
- **Simulates a moving robot.**
- **Uses a PID controller for accuracy**

Installation 
1.Clone this repository:
    sh
    git clone
    https://github.com/zerokali20/AI-Line-Follower.git
    cd AI-Line-Follower

============
AI Line Follower Robot with PID Control

🚀 Project Overview
This project implements a **Line-Following Robot** using **Arduino** with a **PID Controller** for smoother movement.

📌 Features

✅ Uses **IR Sensors** for line detection  
✅ **PID Control** for smooth and accurate path tracking  
✅ **Motor Driver** for speed adjustments  

🛠️ Components Used
- **Arduino Uno/Nano**
- **IR Sensor Array**
- **L298N Motor Driver**
- **DC Motors**
- **Power Supply (Li-Ion Battery)**

🎯 How PID Works
The **PID Controller** improves stability by:
- **Proportional (P):** Adjusts speed based on error
- **Integral (I):** Accumulates past errors
- **Derivative (D):** Predicts future errors

🔧 PID Arduino Code
```cpp
// Example snippet
float Kp = 2.5, Ki = 0.0, Kd = 1.2;  
float error = position - 2;  
float correction = (Kp * error) + (Ki * integral) + (Kd * derivative);
