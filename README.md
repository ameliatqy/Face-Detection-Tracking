# Face-Detection-Tracking

🏆**Winner of Georgia Tech's Mechatronic Expo 2017**

This repository contains the software code for the final project ofGeorgia Tech's Introduction to Mechatronics Class (ME 4405), which took place in Fall 2017. The objective of this project was to design and build a device that detects and tracks a person's face in two dimensions (up/down, left/right). The main purpose of the system is to move the camera so that the person's face is centered in the camera's frame.

The Raspberry Pi is used as the 'observer', which is a camera that is able to detect and localize faces using OpenCV's Haar Cascade algorithm. The TI MSP432 is initialized as the controller and is in charge of moving the camera depending on the data collected by the camera.
