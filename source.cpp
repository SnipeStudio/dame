#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main(int argc,char* argv[])

{
char* path=new char[1000];
char* mode=new char[20];
cout<<"Enter mode: (d|m|b)"<<endl;
cin>>mode;
if(*mode!='d'&&*mode!='m'&&*mode!='b')
{
cout<<"Not valid mode :"<<*mode<<endl;
return 1;
}
if(*mode=='d'||*mode=='b')
{
if(argc<2)
{
cout<<"Enter path to spammed file"<<endl;
cin>>path;
}
else
strcpy(path,argv[1]);
}
ofstream ofs;
ofs.open(path,ios::app|ios::out);

if(ofs||*mode=='m')
{
void *m;
while(true)
{
if(*mode=='m'||*mode=='b')
{
m = malloc(1024*1024);
memset(m,0,1024*1024);
m = malloc(1024*1024);
memset(m,0,1024*1024);
}
if(*mode=='d'||*mode=='b')
{
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913 Paris season of Sergei Dighilev's Ballets Russes company, with choreography by Vaslav Nijinsky and staeesigns and costumes by Nicholas Roerich"<<endl;
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913 Paris season of Sergei Dighilev's Ballets Russes company, with choreography by Vaslav Nijinsky and staeesigns and costumes by Nicholas Roerich"<<endl;
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913 Paris season of Sergei Dighilev's Ballets Russes company, with choreography by Vaslav Nijinsky and staeesigns and costumes by Nicholas Roerich"<<endl;
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913 Paris season of Sergei Dighilev's Ballets Russes company, with choreography by Vaslav Nijinsky and staeesigns and costumes by Nicholas Roerich"<<endl;
}
};
ofs.close();
}

cout<<path<<endl;
delete[] path;
delete mode;
return 0;
}
