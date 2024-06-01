#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

// Function to be executed by each thread
void worker(int id) {
    std::cout << "Thread " << id << " is starting." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " is finishing." << std::endl;
}

int main() {
    const int num_threads = 5; // Number of threads to create
    std::vector<std::thread> threads;
    std::cout << "main thread running" << std::endl;
    std::thread t1(worker,1);
    std::cout << "main thread stopped" << std::endl;
    t1.join();
    // Create and start the threads
    // for (int i = 0; i < num_threads; ++i) {
    //     threads.push_back(std::thread(worker, i));
    // }

    // // Wait for all threads to finish
    // for (auto& th : threads) {
    //     th.join();
    // }

    std::cout << "All threads have finished." << std::endl;

    return 0;
}
