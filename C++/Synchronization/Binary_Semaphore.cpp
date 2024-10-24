#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

std::binary_semaphore main_to_thread{0};
std::binary_semaphore thread_to_main{0};

void process()
{

    std::cout << "new thread started" << std::endl;

    std::cout << "waiting for signal..." << std::endl;

    main_to_thread.acquire();

    std::cout << "signal 1 received" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "signal 2 sent" << std::endl;

    thread_to_main.release();
}

int main()
{
    std::cout << "main thread started" << std::endl;

    std::thread th(process);

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "signal 1 sent" << std::endl;

    main_to_thread.release();

    std::cout << "waiting for signal..." << std::endl;

    thread_to_main.acquire();

    std::cout << "signal 2 received" << std::endl;

    th.join();

    return 0;
}
