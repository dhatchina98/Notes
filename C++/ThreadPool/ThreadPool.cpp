#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <sstream>
#include <string>

class ThreadPool
{
public:
    ThreadPool(int num) : stop(false)
    {
        for (int i = 0; i < num; i++)
        {
            workers.emplace_back([this]
                                 {
            for(;;)
            {
                std::unique_lock<std::mutex> lock(qmutex);
                cv.wait(lock,[this]{ return stop || !tasks.empty();});
                if(stop && tasks.empty())
                return;
                auto task = std::move(tasks.front());
                tasks.pop();
                lock.unlock();
                task();
            } });
        }
    }

    template <class F>
    void enqueue(F &&task)
    {
        std::unique_lock<std::mutex> lock(qmutex);
        tasks.emplace(std::forward<F>(task));
        lock.unlock();
        cv.notify_one();
    }

    ~ThreadPool()
    {
        std::unique_lock<std::mutex> lock(qmutex);
        stop = true;
        lock.unlock();
        cv.notify_all();
        for (std::thread &th : workers)
            th.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex qmutex;
    std::condition_variable cv;
    bool stop;
};

std::string get_thread_id()
{
    auto id = std::this_thread::get_id();
    std::stringstream ss;
    ss << id;
    std::string strr = ss.str();
    return strr;
}

int main()
{
    ThreadPool pool(4);

    std::cout << "Thread Pool created\n";
    std::cout << "Assign Some Tasks\n";

    for (int i = 0; i < 8; i++)
    {
        pool.enqueue([i]
                     {
                        printf("Tasks %d %s executed by thread\n",i,get_thread_id().c_str());
            // std::cout<<"Task " << i <<" executed by this thread "<< get_thread_id().c_str() <<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3)); });
    }
    
    return 0;
}