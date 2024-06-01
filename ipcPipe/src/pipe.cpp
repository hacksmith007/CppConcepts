#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

int main() {
    int pipefd[2]; // File descriptors for the pipe
    char buffer[50]; // Buffer to hold data read from the pipe

    // Create the pipe
    if (pipe(pipefd) == -1) {
        std::cerr << "Error creating pipe\n";
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Error forking\n";
        return 1;
    } else if (pid == 0) {
        // Child process
        close(pipefd[1]); // Close the write end of the pipe
        std::cout << "Child process reading from pipe...\n";

        // Read data from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        std::cout << "Data read from pipe by child: " << buffer << "\n";

        close(pipefd[0]); // Close the read end of the pipe in the child process
    } else {
        // Parent process
        close(pipefd[0]); // Close the read end of the pipe
        std::cout << "Parent process writing to pipe...\n";

        const char* message = "Hello from parent!";
        // Write data to the pipe
        write(pipefd[1], message, strlen(message));

        close(pipefd[1]); // Close the write end of the pipe in the parent process
        waitpid(pid, NULL, 0); // Wait for the child process to finish
    }

    return 0;
}
