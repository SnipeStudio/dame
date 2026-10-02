#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <thread>

// Disk eater part
int ed(char* path);
int edl(char* path,char* limit,char* mult);
int eDLR(char* path,char* limit, char* multSpace, char* timeopt, char* rate, char* multRate);

// Memory eater part
int em();
int eMl(char* limit,char* mult);

// Manual
int man();
