#include <fstream> 
#include <iostream>
#include <cstring> 
#include <stdlib.h>
#include <time.h>
//#include <//syslog.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//Disk eater part
int ed(char* path);
int edl(char* path,char* limit,char* mult);
int eDLR(char* path,char* limit, char* multSpace, char* timeopt, char* rate,  char* multRate);
//Memory eater part
int em();
int eMl(char* limit,char* mult);
//Manual
int man();
