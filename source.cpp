#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
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
double start = clock ();
FILE *fp1 = fopen(path,"ab");
FILE *fp2 = fopen(strcat(path,"2"),"ab");
FILE *fp3 = fopen(strcat(path,"3"),"ab");
        if((fp1&&fp2&&fp3)||!strcmp(mode,"m"))
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
                                if((ftell(fp1)+ftell(fp2)+ftell(fp2))<limit)
                                {
                                        fseek(fp1,0,SEEK_END);
                                        long size1 = ftell(fp1);
    				 fseek(fp2,0,SEEK_END);
                                        long size2 = ftell(fp2);
					 fseek(fp3,0,SEEK_END);
                                        long size3 = ftell(fp3);
                                        if(limit<=1073741824)
                                        {
                                        char *buffer = (char*)calloc(limit/3-size1,1);
                                        fwrite(buffer,limit-size,1,fp1);
					delete[] buffer;
					buffer = (char*)calloc(limit/3-size2,1);
                                        fwrite(buffer,limit-size,1,fp2);
					delete[] buffer;
					buffer = (char*)calloc(limit/3-size3,1);
                                        fwrite(buffer,limit-size,1,fp3);
					delete[] buffer;
                                        }
                                        if(limit>1073741824)
                                        {
                                         long int count=limit/1073741824;
                                        limit/=count;
                                        for(int i=0;i<count;i++)
                                        {
                                        char *buffer = (char*)calloc(limit/3-size1,1);
                                        fwrite(buffer,limit-size,1,fp1);
					delete[] buffer;
					buffer = (char*)calloc(limit/3-size2,1);
                                        fwrite(buffer,limit-size,1,fp2);
					delete[] buffer;
					buffer = (char*)calloc(limit/3-size3,1);
                                        fwrite(buffer,limit-size,1,fp3);
					delete[] buffer;
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
                      {  fclose(fp1);
fclose(fp2);
fclose(fp3);}
        }
double stop = clock();
double total = (stop - start) / CLOCKS_PER_SEC;
        cout<<"Done for "<<total<<" sec"<<endl;
        delete[] path;
        delete mode;
        return 0;
}
