#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mu;

void write(int param)
{
    std::lock_guard<std::mutex> lock(mu);
    std::cout<< " Data " << param << std::endl;
}

void method(int param)
{

    while (true)
    {
        write(param);
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

int main()
{
    std::thread th1(method, 1);
    std::thread th2(method, 2);

    th1.join();
    th2.join();
    return 0;
}