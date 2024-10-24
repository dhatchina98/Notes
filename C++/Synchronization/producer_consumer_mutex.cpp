#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

std::mutex mtx;
std::condition_variable cv;
const unsigned int max_size = 50;
std::deque<int> buffer;

void produce(int val)
{
    while (val)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
                { return buffer.size() < max_size; });
        buffer.push_back(val);
        std::cout << "produced : " << val << std::endl;
        val--;
        lock.unlock();
        cv.notify_one();
    }
}

void consume()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
                { return buffer.size() > 0; });
        int val = buffer.back();
        buffer.pop_back();
        std::cout << "consumed : " << val << std::endl;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
    std::thread t1(produce, 100);
    std::thread t2(consume);

    t1.join();
    t2.join();
    return 0;
}