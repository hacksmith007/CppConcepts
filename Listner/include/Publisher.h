#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <vector>
#include <string>
#include "Listener.h"

class Publisher {
private:
    std::vector<Listener*> listeners;

public:
    void addListener(Listener* listener) {
        listeners.push_back(listener);
    }

    void notifyListeners(const std::string& topic, const std::string& event) {
        for (Listener* listener : listeners) {
            if (listener->getTopic() == topic) {
                listener->onEvent(topic, event);
            }
        }
    }

    void generateEvent(const std::string& topic, const std::string& event) {
        notifyListeners(topic, event);
    }
};

#endif // PUBLISHER_H
