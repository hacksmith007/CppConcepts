#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <string>
#include "callbacks.hpp"

// Function pointer for callback function
typedef void (*CallBackFunction)();

struct CallbackData {
    std::string name;
    CallBackFunction callback;
    int interval;
    bool running;

    // Initializing constructor for Struct CallbackData
    CallbackData(const std::string& name, CallBackFunction callback, int interval)
        : name(name), callback(callback), interval(interval), running(true){}
};

// Register callback 
void registerCallback(CallbackData& data)
{
    while(data.running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(data.interval));
        std::cout << "Executing " << data.name << " :" ;
        data.callback();
    }
}


int main()
{
    std::vector<CallbackData> callbacks;
    callbacks.emplace_back("Callback 1", myCallback1, 1);
    callbacks.emplace_back("Callback 2", myCallback2, 1);
    callbacks.emplace_back("Callback 3", myCallback3, 1);

    std::vector<std::thread> callBackThread;

    for(auto& data : callbacks)
    {
        callBackThread.emplace_back(registerCallback, std::ref(data));
    }

    std::cout << "callbacks started" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "slept " << std::endl;

    for(auto& t : callBackThread)
    {
        std::cout << "Joined" << std::endl;
        if(t.joinable())
        {
            t.join();
        }
    }

    for(auto& data : callbacks)
    {
        std::cout << "Changing running to false" << std::endl;
        data.running = false;
    }



    std::cout << "All callbacks stopped" << std::endl;
    return 0;
}