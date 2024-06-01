#ifndef LISTENER_H
#define LISTENER_H

#include <string>

class Listener {
public:
    virtual void onEvent(const std::string& topic, const std::string& event) = 0;
    virtual std::string getTopic() const = 0;
};

#endif // LISTENER_H
