#include "header.hpp"

int eMl(char* limit, char* mult) // Eat memory with certain limit
{
    unsigned long long limit_long = std::atol(limit), memory_used = 0;
    if(!std::strcmp(mult, "b"))
        limit_long *= 1;
    else if(!std::strcmp(mult, "k"))
        limit_long *= 1024;
    else if(!std::strcmp(mult, "m"))
        limit_long *= 1024 * 1024;
    else if(!std::strcmp(mult, "g"))
        limit_long *= 1024 * 1024 * 1024;
    else
    {
        std::cout << "Invalid multiplier" << std::endl;
        return 1;
    }

    if(limit_long == 0)
    {
        std::cout << "Limit is zero; nothing to allocate" << std::endl;
        return 1;
    }

    void* m = nullptr;
    while(memory_used + 1024 <= limit_long)
    {
        m = std::malloc(1024);
        if(!m)
        {
            std::cout << "Couldn't allocate more memory" << std::endl;
            break;
        }

        std::memset(m, 0, 1024);
        memory_used += 1024;
    }

    std::cout << "Memory allocated. Waiting for interruption" << std::endl;
    while(true) {}
    return 0;
}

int em() // Eat memory without limits
{
    void* m = nullptr;
    while((m = std::malloc(1024)) != nullptr)
    {
        std::memset(m, 0, 1024);
    }

    if(m == nullptr)
    {
        std::cout << "Couldn't allocate more memory" << std::endl;
    }

    while(true) {}
    return 0;
}