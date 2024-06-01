#include <iostream>
#include "Publisher.h"
#include "ConcreteListener.h"

int main() {
    Publisher publisher;

    ConcreteListener listener1("topic1");
    ConcreteListener listener2("topic2");

    publisher.addListener(&listener1);
    publisher.addListener(&listener2);

    publisher.generateEvent("topic1", "Event 1 on topic 1");
    publisher.generateEvent("topic2", "Event 1 on topic 2");
    publisher.generateEvent("topic1", "Event 2 on topic 1");

    return 0;
}
