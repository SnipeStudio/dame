#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
using namespace std;

long int getFileSize(const char * fileName)
{
    struct stat file_stat;
    stat(fileName, &file_stat);
    return file_stat.st_size;
}

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
        if(!strcmp(mode,"dl")||!strcmp(mode,"bl"))
        {
                if(argc<2)
                {
                        cout<<"Enter path to spammed file"<<endl;
                        cin>>path;
                }
                else
                        strcpy(path,argv[1]);
        cout<<"Enter limit:"<<endl;
        cin>>limit>>mult;
        if(mult=='b')
                limit*=1;
        if(mult=='k')
                limit*=1024;
        if(mult=='m')
                limit*=1024*1024;
        if(mult=='g')
                limit*=1024*1024*1024;
        cout<<limit<<endl;
        }
        else
                strcpy(path,argv[1]);
                //ofstream ofs;
//if(!strcmp(mode,"d")||!strcmp(mode,"dl")||!strcmp(mode,"bl"))
        //      ofs.open(path,ios::app|ios::out|ios::binary);
double start = clock ();
FILE *fp = fopen(path,"ab");


        if(fp||!strcmp(mode,"m"))
        {
                void *m;
                
                while(true)
                {
                        if(!strcmp(mode,"m")||!strcmp(mode,"b")||!strcmp(mode,"bl"))
                        {
                                m = malloc(1024*1024);
                                memset(m,0,1024*1024);
                        }
                        if(!strcmp(mode,"d")||!strcmp(mode,"b")||!strcmp(mode,"dl")||!strcmp(mode,"bl"))
                        {
                                if(getFileSize(path)<limit)
                                {
                                        fseek(fp,0,SEEK_END);
                                        long size = ftell(fp);
                                        if(limit<=1073741824)
                                        {
                                        char *buffer = (char*)calloc(limit-size,1);
                                        fwrite(buffer,limit-size,1,fp);
                                        }
                                        if(limit>1073741824)
                                        {
                                         long int count=limit/1073741824;
                                        limit/=count;
                                        for(int i=0;i<count;i++)
                                        {
                                        char *buffer = (char*)calloc(limit-size,1);
                                        fwrite(buffer,limit-size,1,fp);
                                        }
                                        }
                                }
                                else
                                {       
                                        break;
                                }
                        }
                };
                if(!strcmp(mode,"d")||!strcmp(mode,"dl")||!strcmp(mode,"bl"))
                        fclose(fp);
        }
double stop = clock();
double total = (stop - start) / CLOCKS_PER_SEC;
        cout<<"Done for "<<total<<" sec"<<endl;
        delete[] path;
        delete mode;
        return 0;
}
