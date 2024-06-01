#include <iostream>
#include <mqueue.h>
#include <cstring>
#include <cstdlib>

int main() {
    mqd_t mq;
    struct mq_attr attr;
    const char* queue_name = "/test_queue";
    char buffer[256];

    // Open the message queue for reading
    mq = mq_open(queue_name, O_CREAT | O_RDONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    // Receive the message
    ssize_t bytes_read = mq_receive(mq, buffer, 256, nullptr);
    if (bytes_read == -1) {
        perror("mq_receive");
        exit(EXIT_FAILURE);
    }

    std::cout << "Message received: " << buffer << std::endl;

    // Close and unlink the message queue
    mq_close(mq);
    mq_unlink(queue_name);

    return 0;
}
