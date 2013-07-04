#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>


long int getFileSize(const char * fileName)
{
    struct stat file_stat;
    stat(fileName, &file_stat);
    return file_stat.st_size;
}
using namespace std;
int main(int argc,char* argv[])
{
char* path=new char[1000];
char* mode=new char[20];
char mult='b';
long int limit=0,size=0;
cout<<"Enter mode: (d|m|b|dl|bl)"<<endl;
cin>>mode;
if(strcmp(mode,"d")&&strcmp(mode,"m")&&strcmp(mode,"b")&&strcmp(mode,"dl")&&strcmp(mode,"bl"))//d-disk eat only; m - memory eat only; b - disk and memory eat
{
cout<<"Not valid mode :"<<*mode<<endl;
return 1;
}
if(!strcmp(mode,"d")||!strcmp(mode,"b"))
{
if(argc<2)
{
cout<<"Enter path to spammed file"<<endl;
cin>>path;
}
else
strcpy(path,argv[1]);
}
if(strcmp(mode,"dl")||strcmp(mode,"bl"))
{
if(argc<2)
{
cout<<"Enter path to spammed file"<<endl;
cin>>path;
cout<<"Enter limit in bytes"<<endl;
cin>>limit>>mult;
if(mult=='b')
limit*=1;
if(mult=='k')
limit*=1024;
if(mult=='m')
limit*=1024*1024;
if(mult=='g')
limit*=1024*1024*1024;
cout<<limit;
}
else
strcpy(path,argv[1]);

}
ofstream ofs;
ofs.open(path,ios::app|ios::out);
if(ofs||!strcmp(mode,"m"))
{
void *m;
while(true)
{
if(!strcmp(mode,"dl")||!strcmp(mode,"bl"))
{
size=getFileSize(path);
if(size>limit)
break;
}
if(!strcmp(mode,"m")||!strcmp(mode,"b"))
{
m = malloc(1024*1024);
memset(m,0,1024*1024);
}
if(!strcmp(mode,"d")||!strcmp(mode,"b")||!strcmp(mode,"dl")||!strcmp(mode,"bl"))
{
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913 Paris season of Sergei Dighilev's Ballets Russes company, with choreography by Vaslav Nijinsky and staeesigns and costumes by Nicholas Roerich"<<endl;
}

};
ofs.close();
}

cout<<"<<endl;
delete[] path;
delete mode;
return 0;
}

