#include <iostream>
#include <mqueue.h>
#include <cstring>
#include <cstdlib>

int main() {
    mqd_t mq;
    struct mq_attr attr;
    const char* queue_name = "/test_queue";

    // Define the message queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 256;
    attr.mq_curmsgs = 0;

    // Open the message queue for writing
    mq = mq_open(queue_name, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    // The message to send
    const char* message = "Hello, World!";
    
    // Send the message
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        exit(EXIT_FAILURE);
    }

    std::cout << "Message sent: " << message << std::endl;

    // Close the message queue
    mq_close(mq);

    return 0;
}
