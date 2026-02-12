# Real-Time IoT Sensor Data Aggregation System (C++ | Linux | TCP/IP)

## Overview
This project implements a real-time, multithreaded client–server system in C++ on Linux that simulates multiple IoT devices streaming sensor data (temperature and humidity) to a central server. The server aggregates incoming data, performs basic real-time processing, generates alerts based on predefined thresholds, and logs sensor readings for monitoring and analysis. The system demonstrates core concepts of Linux system programming, socket-based network communication, multithreading, and synchronization.

## Key Features
- TCP/IP socket-based client–server communication  
- Multithreaded server to handle multiple concurrent clients  
- Real-time streaming of sensor data from simulated IoT devices  
- Threshold-based alert generation for abnormal sensor readings  
- Thread-safe logging using mutex to prevent race conditions  
- Built and tested on Linux/UNIX environments  

## Architecture
Sensor Clients periodically send temperature and humidity readings to the Central Server over TCP sockets. The Central Server listens for incoming connections, spawns a dedicated thread for each client, parses incoming sensor data, generates real-time alerts, and logs data to persistent storage.

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

Compile the server and client:

```bash
g++ server.cpp -o server -pthread
g++ sensor_client.cpp -o sensor_client

Running the Application

Start the Server:

./server

Start one or more Sensor Clients (in separate terminals):

./sensor_client device01
./sensor_client device02

The server will display incoming sensor readings and generate alerts when threshold conditions are met. Logged data will be stored in sensor_log.txt.

Configuration

Server Port: Default port is 8080 (can be changed in both server.cpp and sensor_client.cpp).

Alert Thresholds: Adjust temperature threshold values in server logic.

Logging: Sensor readings are appended to sensor_log.txt with thread-safe writes using mutex.

Learning Outcomes

TCP/IP socket programming on Linux

Multithreaded server design and concurrency handling

Operating system concepts such as synchronization and mutual exclusion

Real-time data processing and distributed system basics

Client–server architecture for system-level software

Possible Enhancements

Authentication for sensor clients

Support for UDP-based lightweight sensors

Real-time dashboard for visualization

Containerization using Docker

Deployment on embedded Linux devices

License

This project is intended for educational purposes.
