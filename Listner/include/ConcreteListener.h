#ifndef CONCRETELISTENER_H
#define CONCRETELISTENER_H

#include <iostream>
#include "Listener.h"

class ConcreteListener : public Listener {
private:
    std::string topic;

public:
    ConcreteListener(const std::string& topic) : topic(topic) {}

    void onEvent(const std::string& topic, const std::string& event) override {
        std::cout << "Received event on topic '" << topic << "': " << event << std::endl;
    }

    std::string getTopic() const override {
        return topic;
    }
};

#endif // CONCRETELISTENER_H
