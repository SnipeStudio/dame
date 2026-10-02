#include "header.hpp"

char ver[6] = "2.3";
char name[35] = "Disk Drive and Memory Eater(dame)";
char vermod[25] = " on Linux";

int man()
{
    char line[81] = "+-----------------------------------------------------------------------------+";
    std::cout << line << std::endl;
    std::cout << "|                " << name << " v" << ver << " Manual                |" << std::endl;
    std::cout << line << std::endl;
    std::cout << "| dame man   -           shows this manual                                    |" << std::endl;
    std::cout << "| dame ver   -           shows version of program                             |" << std::endl;
    std::cout << "| dame ed    -           start to eat disk drive space in a specific folder   |" << std::endl;
    std::cout << "| USAGE: dame ed /path/to/eat                                                 |" << std::endl;
    std::cout << "| dame edl    -          start to eat disk drive space with limits            |" << std::endl;
    std::cout << "| USAGE: dame edl /path/to/eat spacetoeat {b|k|m|g}                           |" << std::endl;
    std::cout << "| dame em    -           start to eat memory without limits                   |" << std::endl;
    std::cout << "| dame eml   -           start to eat memory with limits                      |" << std::endl;
    std::cout << "| USAGE: dame eml memorytoeat {b|k|m|g}                                       |" << std::endl;
    std::cout << "| dame edlr - start to eat ddspace with limits,time options and rate          |" << std::endl;
    std::cout << "| USAGE: dame edlr path spacetoeat {b|k|m|g} timeopt ratepertime {b|k|m|g}    |" << std::endl;
    std::cout << line << std::endl;
    return 0;
}

int main(volatile int argc, char** argv)
{
    const char* mods[] = {
        "ed",
        "edl",
        "em",
        "ver",
        "man",
        "eml",
        "edlr"
    };

    if(argc < 2)
    {
        man();
        return 0;
    }

    double start = std::clock();
    char* mode = new char[32];
    std::snprintf(mode, 32, "%s", argv[1]);
    bool flag = false;
    for(const char* s : mods)
    {
        if(!std::strcmp(mode, s))
            flag = true;
    }
    if(!flag)
    {
        std::cout << "Not valid mode : " << mode << std::endl;
        delete[] mode;
        return 1;
    }

    int rc = 0;

    if(!std::strcmp(mode, "-v"))
    {
        if(argc < 2)
        {
            man();
            delete[] mode;
            return 0;
        }
        std::cout << "Hehey-Off we go!" << std::endl;
    }
    if(!std::strcmp(mode, "ed"))
    {
        if(argc < 3)
        {
            man();
            delete[] mode;
            return 0;
        }
        rc = ed(argv[2]);
    }
    if(!std::strcmp(mode, "man"))
        man();
    if(!std::strcmp(mode, "ver"))
        std::cout << "You are using " << name << " version " << ver << vermod << std::endl;
    if(!std::strcmp(mode, "em"))
        rc = em();
    if(!std::strcmp(mode, "eml"))
    {
        if(argc < 4)
        {
            man();
            delete[] mode;
            return 0;
        }
        rc = eMl(argv[2], argv[3]);
    }
    if(!std::strcmp(mode, "edl"))
    {
        if(argc < 5)
        {
            man();
            delete[] mode;
            return 0;
        }
        rc = edl(argv[2], argv[3], argv[4]);
    }
    if(!std::strcmp(mode, "edlr"))
    {
        if(argc < 8)
        {
            man();
            delete[] mode;
            return 0;
        }
        rc = eDLR(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    }

    if(rc != 0)
    {
        delete[] mode;
        return rc;
    }

    double stop = std::clock();
    double total = (stop - start) / CLOCKS_PER_SEC;
    std::cout << "Done for " << total << " sec" << std::endl;
    delete[] mode;
    return 0;
}
