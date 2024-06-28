#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <thread>

//  Global variable to be accessed
int serverSocket;
sockaddr_in serverAddr;

// Structure containing sockert parameters
struct socketParam
{
    int __domain;
    int __type;
    int __protocol;
    int __port;
    socketParam(int d_val, int t_val, int prot_val, int p_val) : __domain(d_val), __type(t_val), __protocol(prot_val), __port(p_val){} 
};

// Function to create and bind  socket to specific port and with given parameters
int createBindSocket(socketParam s)
{
    serverSocket = socket(s.__domain, s.__type, s.__protocol);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Bind socket to IP and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(s.__port); // Port 8080
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error binding socket\n";
        return 1;
    }
    return 0;
}

int main() {
    socketParam  sp(AF_INET,SOCK_STREAM,0,8080);
    // Create socket
    if(createBindSocket(sp))
        std::cerr << "Something Really bad Happened\n";

    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Error listening\n";
        return 1;
    }
    int clientSocket;
    std::cout << "Server listening on port 8080...\n";
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for 1 second
        // Here, you can check for incoming messages and handle them
        // For demonstration purposes, we print a message every second
        std::cout << "Server is waiting for messages..." << std::endl;

            // Accept incoming connection
        sockaddr_in clientAddr;
        socklen_t clientAddrSize = sizeof(clientAddr);
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrSize);
        if (clientSocket < 0) {
            std::cerr << "Error accepting connection\n";
            return 1;
        }
        else
        {
            std::cout << "Client " << clientSocket - 3 << "Connected !!" << std::endl;
        }

        // Send message to client
        const char* message = "Hello from server!";
        send(clientSocket, message, strlen(message), 0);
        std::cout << "Response Sent successfully"<< std::endl;

    }


    close(clientSocket);
    close(serverSocket);

    return 0;
}
