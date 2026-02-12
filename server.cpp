// server.cpp
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <cstring>

#include <sstream>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <cstring>
#include <sstream>
#include <fstream>
#include <mutex>

std::mutex log_mutex; 

void handle_client(int client_fd) {
    char buffer[1024];

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = read(client_fd, buffer, sizeof(buffer) - 1);
        if (bytes <= 0) break;

        std::string data(buffer);
        std::stringstream ss(data);

        std::string device, tempStr, humStr;
        getline(ss, device, ',');
        getline(ss, tempStr, ',');
        getline(ss, humStr, ',');

        float temperature = std::stof(tempStr);
        float humidity = std::stof(humStr);

        {
          std::lock_guard<std::mutex> lock(log_mutex);
          std::ofstream logfile("sensor_log.txt", std::ios::app);
          logfile << device << "," << temperature << "," << humidity << "\n";
        }
        // 👉 LOGGING GOES HERE
        std::ofstream logfile("sensor_log.txt", std::ios::app);
        logfile << device << "," << temperature << "," << humidity << "\n";
        logfile.close();

        std::cout << "[" << device << "] "
                  << "Temp=" << temperature
                  << " Humidity=" << humidity;

        if (temperature > 35) {
            std::cout << "  ALERT: High temperature!";
            std::string alert = "ALERT: High temperature detected!\n";
            send(client_fd, alert.c_str(), alert.size(), 0);
        } else {
            std::string ok = "OK\n";
            send(client_fd, ok.c_str(), ok.size(), 0);
        }

        std::cout << std::endl;
    }

    close(client_fd);
}



int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 10);

    std::cout << "IoT Server running on port 8080...\n";

    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);
        std::thread(handle_client, client_fd).detach();
    }
}

