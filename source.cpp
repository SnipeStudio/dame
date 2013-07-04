#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main(int argc,char* argv[])
{
char* path=new char[1000];
if(argc<2)
{
cout<<"Enter path to spammed directory"<<endl;
cin>>path;
}
else
strcpy(path,argv[1]);
ofstream ofs;
ofs.open(path,ios::app|ios::out);
if(ofs)
{
void *m;
while(true)
{
m = malloc(1024*1024);
memset(m,0,1024*1024);
m = malloc(1024*1024);
memset(m,0,1024*1024);
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913Â Paris season of Sergei Dighilev's Ballets Russes company, with choreography by Vaslav Nijinsky and staeesigns and costumes by Nicholas Roerich";
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913Â Paris season of Sergei Dihilev's Ballets Russes company, with choreography by Vaslav Nijinsky and stag signs and costumes by Nicholas Roerich";
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913Â Paris season of Sergei Dihilev's Ballets Russes company, with choreography by Vaslav Nijinsky and stag signs and costumes by Nicholas Roerich";
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913Â Paris season of Sergei ihilev's Ballets Russes company, with choreography by Vaslav Nijinsky and stag esigns and costumes by Nicholas Roerich";
ofs<<"The Rite of Spring is a ballet and orchestral concert work by the Russian composer Igor Stravinsky. It was written for the 1913Â Paris season of Sergei iaghilev's Ballets Russes company, with choreography by Vaslav Nijinsky and stg designs and costumes by Nicholas Roerich";
};

ofs.close();
}

cout<<path<<endl;
delete[] path;
return 0;
}
