#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>

#define BUFFER_SIZE 5

int buff[BUFFER_SIZE];

// semaphore for produce data with initial permission
std::binary_semaphore signal_to_producer{1};
// semaphore for consume data without initial permission
std::binary_semaphore signal_to_consumer{0};

void produce()
{
    while (1)
    {
        // initially it can acquire
        signal_to_producer.acquire();

        // produce data
        std::cout << "Producer = ";

        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            buff[i] = i * i;
            std::cout << buff[i] << " " << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        std::cout << std::endl;

        // signalling to consumer
        signal_to_consumer.release();
    }
}

void consume()
{
    while (1)
    {
        // waiting for signal from producer
        signal_to_consumer.acquire();

        // consume data
        std::cout << "Consumer = ";

        for (int i = BUFFER_SIZE - 1; i >= 0; i--)
        {
            std::cout << buff[i] << " " << std::flush;
            buff[i] = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        std::cout << std::endl;
        std::cout << std::endl;

        // signallig to producer
        signal_to_producer.release();
    }
}

int main()
{
    std::cout << "producer and consumer started .." << std::endl;

    std::thread producer(produce);
    std::thread consumer(consume);

    producer.join();
    consumer.join();
    return 0;
}