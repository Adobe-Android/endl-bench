#include <iostream>
#include <chrono>

void say_hello_with_flush()
{
    std::cout << "hello" << std::endl;
}

void say_hello()
{
    std::cout << "hello\n";
}

int main()
{
    auto time_start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1'000; i++)
    {
        say_hello();
    }

    auto time_end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count();

    time_start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1'000; i++)
    {
        say_hello_with_flush();
    }

    time_end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count();

    std::cout << "It took say_hello " << duration1 << " ms\n";
    std::cout << "It took say_hello_with_flush " << duration2 << " ms\n";
}