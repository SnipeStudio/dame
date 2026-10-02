#include "header.hpp"
#include <string>

static std::string disk_base_name(const char* path)
{
    std::string base(path);
    if(!base.empty() && base.back() == '/')
    {
        base += "eater";
    }
    return base;
}

int ed(char* path) // Eat all available disk space
{
    /*
    Function returns:
    0 - if everything ok
    1 - file open error
    */     
        std::string base = disk_base_name(path);
        std::string file1 = base;
        std::string file2 = base + "2";
        std::string file3 = base + "3";
        FILE* fp1 = std::fopen(file1.c_str(), "ab");
        FILE* fp2 = std::fopen(file2.c_str(), "ab");
        FILE* fp3 = std::fopen(file3.c_str(), "ab");
        bool error = false;
        long long debug = 0;
        if(fp1 && fp2 && fp3)
        {
            while(true)
            {
                std::fseek(fp1, 0, SEEK_END);
                std::fseek(fp2, 0, SEEK_END);
                std::fseek(fp3, 0, SEEK_END);
                char* buffer = static_cast<char*>(std::calloc(1024, 1));
                if(!buffer)
                {
                    std::cout << "Could not allocate disk write buffer" << std::endl;
                    error = true;
                    break;
                }
                if(std::fwrite(buffer, 1024, 1, fp1) != 1)
                {
                    std::cout << "There are some errors during eating your disk drive. Failed to write first file" << std::endl;
                    error = true;
                    std::free(buffer);
                    break;
                }
                debug += 1024;
                if(std::fwrite(buffer, 1024, 1, fp2) != 1)
                {
                    std::cout << "There are some errors during eating your disk drive. Failed to write second file" << std::endl;
                    error = true;
                    std::free(buffer);
                    break;
                }
                debug += 1024;
                if(std::fwrite(buffer, 1024, 1, fp3) != 1)
                {
                    std::cout << "There are some errors during eating your disk drive. Failed to write third file" << std::endl;
                    error = true;
                    std::free(buffer);
                    break;
                }
                debug += 1024;
                std::cout << debug << "\r";
                std::free(buffer);
            }
            std::fclose(fp1);
            std::fclose(fp2);
            std::fclose(fp3);
        }
        else
        {
            return 1;
        }
        return 0;
}

int edl(char* path, char* limit, char* mult) // Eat disk with limits
{
    /*
    Function returns:
    0 - if everything ok
    1 - size multiplier error
    2 - file open error
    3 - error in file write
    */
    long long limit_long = std::atol(limit);
    std::cout << mult << std::endl;
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
        std::cout << "Wrong input data" << std::endl;
        return 1;
    }

    std::string base = disk_base_name(path);
    std::string file1 = base;
    std::string file2 = base + "_1";
    std::string file3 = base + "_2";
    bool error = false;
    FILE* fp1 = std::fopen(file1.c_str(), "ab");
    FILE* fp2 = std::fopen(file2.c_str(), "ab");
    FILE* fp3 = std::fopen(file3.c_str(), "ab");
    long long debug = 0;
    if(fp1 && fp2 && fp3)
    {
        while(true)
        {
            std::fseek(fp1, 0, SEEK_END);
            std::fseek(fp2, 0, SEEK_END);
            std::fseek(fp3, 0, SEEK_END);
            char* buffer = static_cast<char*>(std::calloc(1024, 1));
            if(!buffer)
            {
                std::cout << "Could not allocate disk write buffer" << std::endl;
                error = true;
                break;
            }
            if(std::fwrite(buffer, 1024, 1, fp1) != 1)
            {
                std::cout << "There are some errors during eating your disk drive. Failed to write first file" << std::endl;
                error = true;
                std::free(buffer);
                break;
            }
            debug += 1024;
            if(std::fwrite(buffer, 1024, 1, fp2) != 1)
            {
                std::cout << "There are some errors during eating your disk drive. Failed to write second file" << std::endl;
                error = true;
                std::free(buffer);
                break;
            }
            debug += 1024;
            if(std::fwrite(buffer, 1024, 1, fp3) != 1)
            {
                std::cout << "There are some errors during eating your disk drive. Failed to write third file" << std::endl;
                error = true;
                std::free(buffer);
                break;
            }
            debug += 1024;
            std::free(buffer);
            if(debug >= limit_long)
                break;
            std::cout << debug << "/" << limit_long << "\r";
        }
        std::cout << "Bytes written: " << debug << "/" << limit_long << "(" << debug / limit_long * 100 << "%)" << std::endl;
        std::fclose(fp1);
        std::fclose(fp2);
        std::fclose(fp3);
    }
    else
    {
        std::cout << "Could not open file from the set" << std::endl;
        return 2;
    }
    if(error)
    {
        return 3;
    }
    return 0;
}

int eDLR(char* path, char* limit, char* multSpace, char* timeopt, char* rate, char* multRate) // Eat disk with limits and write rate
{
    std::string base = disk_base_name(path);
    long long limit_long = std::atol(limit), memory_used = 0;
    if(!std::strcmp(multSpace, "b"))
        limit_long *= 1;
    else if(!std::strcmp(multSpace, "k"))
        limit_long *= 1024;
    else if(!std::strcmp(multSpace, "m"))
        limit_long *= 1024 * 1024;
    else if(!std::strcmp(multSpace, "g"))
        limit_long *= 1024 * 1024 * 1024;
    else
    {
        std::cout << "Wrong input data" << std::endl;
        return 1;
    }

    long long rate_long = std::atol(rate);
    if(!std::strcmp(multRate, "b"))
        rate_long *= 1;
    else if(!std::strcmp(multRate, "k"))
        rate_long *= 1024;
    else if(!std::strcmp(multRate, "m"))
        rate_long *= 1024 * 1024;
    else if(!std::strcmp(multRate, "g"))
        rate_long *= 1024 * 1024 * 1024;
    else
    {
        std::cout << "Wrong input data\n";
        return 1;
    }

    // Counter of disk drive consume
    double start = std::clock();
    FILE* fpCounter = std::fopen(path, "ab");
    if(!fpCounter)
    {
        std::cout << "Could not open file for disk drive counter" << std::endl;
        return 2;
    }
    while(memory_used < 1024 * 1024)
    {
        std::fseek(fpCounter, 0, SEEK_END);
        char* buffer = static_cast<char*>(std::calloc(1024, 1));
        if(!buffer)
        {
            std::fclose(fpCounter);
            std::cout << "Could not allocate buffer for disk drive counter" << std::endl;
            return 2;
        }
        std::fwrite(buffer, 1024, 1, fpCounter);
        std::free(buffer);
        memory_used += 1024;
    }
    std::fclose(fpCounter);

    double stop = std::clock();
    double time = (stop / CLOCKS_PER_SEC) - (start / CLOCKS_PER_SEC);
    if(time <= 0.0)
        time = 1.0;

    double memoryPerSec = (double)memory_used / time;
    memoryPerSec = (long long)memoryPerSec;
    if(memoryPerSec == 0)
        memoryPerSec = 1024;

    // End of counter
    long long memoryPerTimeopt = 0;
    long long timeopt_v = 1;
    if(!std::strcmp(timeopt, "s"))
        memoryPerTimeopt = rate_long / memoryPerSec;
    else if(!std::strcmp(timeopt, "m"))
    {
        memoryPerTimeopt = rate_long / memoryPerSec;
        timeopt_v *= 60;
    }
    else if(!std::strcmp(timeopt, "h"))
    {
        memoryPerTimeopt = rate_long / memoryPerSec;
        timeopt_v *= 3600;
    }
    else if(!std::strcmp(timeopt, "d"))
    {
        memoryPerTimeopt = rate_long / memoryPerSec;
        timeopt_v *= 86400;
    }
    else
    {
        std::cout << "Wrong input data\n";
        return 1;
    }

    if(memoryPerTimeopt == 0)
        memoryPerTimeopt = rate_long;
    start = 0;

    std::string file1 = base;
    std::string file2_name = base + "1";
    std::string file3_name = base + "2";
    FILE* fp1 = std::fopen(file1.c_str(), "wb");
    FILE* fp2 = std::fopen(file2_name.c_str(), "wb");
    FILE* fp3 = std::fopen(file3_name.c_str(), "wb");
    if(!fp1 || !fp2 || !fp3)
    {
        std::cout << "Could not create filestream" << std::endl;
        if(fp1) std::fclose(fp1);
        if(fp2) std::fclose(fp2);
        if(fp3) std::fclose(fp3);
        return 2;
    }

    bool error = false;
    while(memory_used < limit_long)
    {
        start = std::clock();
        std::fseek(fp1, 0, SEEK_END);
        std::fseek(fp2, 0, SEEK_END);
        std::fseek(fp3, 0, SEEK_END);
        char* buffer = static_cast<char*>(std::calloc(memoryPerTimeopt, 1));
        if(!buffer)
        {
            std::cout << "Could not allocate disk write buffer" << std::endl;
            error = true;
            break;
        }
        if(std::fwrite(buffer, memoryPerTimeopt, 1, fp1) != 1)
        {
            std::cout << "There are some errors during eating your disk drive. Failed to write first file" << std::endl;
            error = true;
            std::free(buffer);
            break;
        }
        if(std::fwrite(buffer, memoryPerTimeopt, 1, fp2) != 1)
        {
            std::cout << "There are some errors during eating your disk drive. Failed to write second file" << std::endl;
            error = true;
            std::free(buffer);
            break;
        }
        if(std::fwrite(buffer, memoryPerTimeopt, 1, fp3) != 1)
        {
            std::cout << "There are some errors during eating your disk drive. Failed to write third file" << std::endl;
            error = true;
            std::free(buffer);
            break;
        }
        std::free(buffer);
        memory_used += memoryPerTimeopt * 3;

        while((std::clock() / CLOCKS_PER_SEC - start / CLOCKS_PER_SEC) < timeopt_v)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    std::fclose(fp1);
    std::fclose(fp2);
    std::fclose(fp3);
    if(error)
    {
        return 3;
    }
    return 0;
}