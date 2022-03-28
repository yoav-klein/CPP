
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

int g_data = 0;
std::atomic<bool> g_flag(false);

void produce()
{
    g_data = 1;
    g_flag.store(true, std::memory_order_relaxed);    
}

void consume()
{    
    int count = 0;    
    while(g_flag.load(std::memory_order_relaxed) == false)
    {
        ++count;
    }
    
    if(g_data == 0)
    {
        std::cout << "0" << std::endl;
    }
    else
    {
        std::cout << "1" << std::endl;
    } 
}

int main()
{
    std::thread consumer(consume);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread producer(produce);
    
    producer.join();
    consumer.join();

    return 0;
}
