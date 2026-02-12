// sensor_client.cpp
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./sensor_client <device_id>\n";
        return 1;
    }

    std::string device_id = argv[1];

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serv{};
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);

    connect(sock, (sockaddr*)&serv, sizeof(serv));

    srand(time(nullptr));

while (true) {
    float temp = 20 + rand() % 20;
    float hum  = 40 + rand() % 30;

    std::string msg = device_id + "," +
                      std::to_string(temp) + "," +
                      std::to_string(hum) + "\n";

    // 1️⃣ Send data to server
    send(sock, msg.c_str(), msg.size(), 0);

    // 2️⃣ Read server reply (ALERT or ACK)
    char buffer[1024] = {0};
    int bytes = read(sock, buffer, sizeof(buffer) - 1);

    if (bytes > 0) {
        buffer[bytes] = '\0';
        std::cout << "Server: " << buffer;
    }

    sleep(2);
}
    
}

