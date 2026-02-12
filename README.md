# Real-Time IoT Sensor Data Aggregation System (C++ | Linux | TCP/IP)

## Overview
This project implements a real-time, multithreaded client–server system in C++ on Linux that simulates multiple IoT devices streaming sensor data (temperature and humidity) to a central server. The server aggregates incoming data, performs real-time processing, generates alerts based on predefined thresholds, and logs sensor readings for monitoring and analysis. The system demonstrates Linux system programming, socket-based network communication, multithreading, and synchronization.

## Project Structure
realtime-iot-cpp/
├── server.cpp
├── sensor_client.cpp
├── README.md
├── .gitignore

## Prerequisites
- Linux/UNIX environment
- g++ (C++17 or later recommended)
- Basic familiarity with terminal and Git

## Build Instructions
g++ server.cpp -o server -pthread  
g++ sensor_client.cpp -o sensor_client

## Running the Application
./server  
./sensor_client device01  
./sensor_client device02  

## Features
- TCP/IP socket-based client–server communication
- Multithreaded server to handle multiple concurrent clients
- Real-time streaming of sensor data from simulated IoT devices
- Threshold-based alert generation
- Thread-safe logging using mutex
- Built and tested on Linux/UNIX

## Configuration
- Server Port: Default port is 8080 (can be changed in both server.cpp and sensor_client.cpp).
- Alert Thresholds: Adjust temperature threshold values in server logic.
- Logging: Sensor readings are appended to sensor_log.txt with thread-safe writes using mutex.

## Learning Outcomes
- TCP/IP socket programming on Linux
- Multithreaded server design and concurrency handling
- Operating system concepts such as synchronization and mutual exclusion
- Real-time data processing and basic distributed systems concepts
- Client–server architecture for system-level software development

## Possible Enhancements
- Authentication for sensor clients
- UDP-based lightweight sensors
- Real-time dashboard visualization
- Docker containerization
- Deployment on embedded Linux devices

## License
Educational use.
