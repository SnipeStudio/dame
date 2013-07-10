#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
using namespace std;
char ver[6]="2.2";
char name[35]="Disk Drive and Memory Eater(dame)";

int man()
{
char line[81]="+------------------------------------------------------------------------------+";
cout<<line<<endl;
cout<<"|                "<<name<<" v"<<ver<<" Manual                 |"<<endl;
cout<<line<<endl;
cout<<"| dame man   -           shows this manual                                     |"<<endl;
cout<<"| dame ver   -           shows version of program                              |"<<endl;
cout<<"| dame ed    -           start to eat disk drive space in a specific folder    |"<<endl;
cout<<"| USAGE: dame ed /path/to/eat                                                  |"<<endl;
cout<<"| dame edl    -          start to eat disk drive space with limits             |"<<endl;
cout<<"| USAGE: dame edl /path/to/eat spacetoeat {b|k|m|g}                            |"<<endl;
cout<<"| dame em    -           start to eat memory                                   |"<<endl;
cout<<"| dame emd    -          start to eat memory and disk drive space              |"<<endl;
cout<<"| dame emdl    -         start to eat memory and disk drive space with limits  |"<<endl;
cout<<line<<endl;
return 0;
}

int main(int argc,char** argv)
{
        if(argc<2)
        {
                man();
                return 0;
        }
        char* path=new char[1000];
        char* mode=new char[20];
        strcpy(mode,argv[1]);
        char* mult=new char[10];
        char* buf=new char[3000];
        long int limit=0,size=0;
        if(strcmp(mode,"ed")&&strcmp(mode,"edl")&&strcmp(mode,"emd")&&strcmp(mode,"emdl")&&strcmp(mode,"edl")&&strcmp(mode,"ver")&&strcmp(mode,"man"))
        {
                cout<<"Not valid mode :"<<*mode<<endl;
                return 1;
        }
        if(!strcmp(mode,"ed")||!strcmp(mode,"edm"))
        {
                        strcpy(path,argv[2]);
        }
        if(!strcmp(mode,"edl")||!strcmp(mode,"edml"))
        {
                strcpy(path,argv[2]);
                //strcpy(buf,argv[3]);
                limit=atol(argv[3]);
		cout<<limit<<endl;
		long back=limit;
                delete[] buf;
                strcpy(mult,argv[4]);
       		 if(!strcmp(mult,"b"))
                	limit*=1;
       		if(!strcmp(mult,"k"))
                	limit*=1024;
       		if(!strcmp(mult,"m"))
	                limit*=1024*1024;
		 if(!strcmp(mult,"g"))
	                limit*=1024*1024*1024;
		limit=limit-back;
	}
	double start = clock ();
	FILE *fp1 = fopen(path,"ab");
	FILE *fp2 = fopen(strcat(path,"2"),"ab");
	FILE *fp3 = fopen(strcat(path,"3"),"ab");
	cout<<limit<<endl;
        if((fp1&&fp2&&fp3)||!strcmp(mode,"em"))
        {
                void *m;
                while(true)
                {
                        if(!strcmp(mode,"em")||strcmp(mode,"emd")||strcmp(mode,"emdl"))
                        {
                                m = malloc(1024*1024);
                                memset(m,0,1024*1024);
                        }
                        if(!strcmp(mode,"ed")||strcmp(mode,"emd")||!strcmp(mode,"edl")||strcmp(mode,"emdl"))
                        {
                                long fSizeS=ftell(fp1)+ftell(fp2)+ftell(fp2);
                                cout<<fSizeS<<" "<<limit<<endl;
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
                                        fwrite(buffer,limit/3-size1,1,fp1);
                                        delete[] buffer;
                                        buffer = (char*)calloc(limit/3-size2,1);
                                        fwrite(buffer,limit/3-size2,1,fp2);
                                        delete[] buffer;
                                        buffer = (char*)calloc(limit/3-size3,1);
                                        fwrite(buffer,limit/3-size3,1,fp3);
                                        delete[] buffer;
                                        }                                    
					if(limit>1073741824)
                                        {
                                        long int count=limit/1073741824;
					count++;
                                        limit/=count;
                                        cout<<limit<<" "<<count<<endl;
                                        for(int i=0;i<count;i++)
                                        {
                                        char *buffer = (char*)calloc(limit/3-size1,1);
                                        fwrite(buffer,limit/3-size1,1,fp1);
                                        delete[] buffer;
                                        buffer = (char*)calloc(limit/3-size2,1);
                                        fwrite(buffer,limit/3-size2,1,fp2);
                                        delete[] buffer;
                                        buffer = (char*)calloc(limit/3-size3,1);
                                        fwrite(buffer,limit/3-size3,1,fp3);
                                        delete[] buffer;
                                        }
                                        }
                                	long fSizeF=ftell(fp1)+ftell(fp2)+ftell(fp2);
                                	cout<<fSizeS<<" "<<limit<<endl;
					if(fSizeF<fSizeS&&fSizeF<limit)
					{
						cerr<<"Error: Could now write file"<<endl;
						return 0;
					}
                              		}
                                	else
                                	{
                                        	break;
                                	}
                        	}
               		};
                	if(!strcmp(mode,"ed")||!strcmp(mode,"edl")||strcmp(mode,"emdl"))
                      { 
			fclose(fp1);
			fclose(fp2);
			fclose(fp3);
			}
        }
	double stop = clock();
	double total = (stop - start) / CLOCKS_PER_SEC;
        cout<<"Done for "<<total<<" sec"<<endl;
        delete[] path;
        delete mode;
        return 0;
}



