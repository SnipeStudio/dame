#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
using namespace std;
char ver[6]="2.3";
char name[35]="Disk Drive and Memory Eater(dame)";
char vermod[20]=".0.4-beta";
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
cout<<"| dame em    -           start to eat memory without limits                    |"<<endl;
cout<<"| dame eml   -           start to eat memory with limits                       |"<<endl;
cout<<"| USAGE: dame eml memorytoeat {b|k|m|g}                                        |"<<endl;
cout<<"| dame emlr - start to eat memory with limits,time options and rate            |"<<endl;
cout<<"| USAGE: dame emlr memorytoeat {b|k|m|g} timeopt ratepertime {b|k|m|g}         |"<<endl;
cout<<line<<endl;
return 0;
}

int eMl(char* limit,char* mult)
{
	unsigned long long limit_long=atol(limit),memory_used=0;
                if(!strcmp(mult,"b"))
                	limit_long*=1;
       		if(!strcmp(mult,"k"))
                	limit_long*=1024;
       		if(!strcmp(mult,"m"))
	                limit_long*=1024*1024;
		 if(!strcmp(mult,"g"))
	                limit_long*=1024*1024*1024;
		void* m;
		while((m = malloc(1024))&&memory_used<limit_long)
		{
               		m = malloc(1024);
			memset(m,0,1024);
			memory_used+=1024;
		};
return 0;
}

int em()
{
	void *m;
	while(m = malloc(1024))
	{
   		memset(m,0,1024*1024);
	}
	while(true){};
	return 0;
}

int edl(char* path,char* limit,char* mult)
{
    	long long limit_long=atol(limit);
        if(!strcmp(mult,"b"))
            limit_long*=1;
        if(!strcmp(mult,"k"))
            limit_long*=1024;
        if(!strcmp(mult,"m"))
            limit_long*=1024*1024;
        if(!strcmp(mult,"g"))
            limit_long*=1024*1024*1024;
        FILE *fp1 = fopen(path,"ab");
        FILE *fp2 = fopen(strcat(path,"2"),"ab");
        FILE *fp3 = fopen(strcat(path,"3"),"ab"); 
        if(fp1&&fp2&&fp3)
        {
            long long fSizeS=0,fSizeF=fSizeS;
            while(true)
            {
                fSizeS=ftell(fp1)+ftell(fp2)+ftell(fp2);
                char *buffer = (char*)calloc(1024,1);
                fwrite(buffer,1024,1,fp1);
                delete[] buffer;
                buffer = (char*)calloc(1024,1);
                fwrite(buffer,1024,1,fp2);
                delete[] buffer;
                buffer = (char*)calloc(1024,1);
                fwrite(buffer,1024,1,fp3);
                delete[] buffer;
                long long fSizeF=ftell(fp1)+ftell(fp2)+ftell(fp2);
                if(fSizeF>=limit_long)
                    break;
                if(fSizeF==fSizeS&&fSizeF<limit_long)
                {
                    cout<<"There are some errors during writing file"<<endl;
                    return -1;
                }
            }
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
        }
        return 0;
}
int ed(char* path)
{
        FILE *fp1 = fopen(path,"ab");
        FILE *fp2 = fopen(strcat(path,"2"),"ab");
        FILE *fp3 = fopen(strcat(path,"3"),"ab");  
        if(fp1&&fp2&&fp3)
       {
            while(true)
            {
                long long fSizeS=ftell(fp1)+ftell(fp2)+ftell(fp2);
                fseek(fp1,0,SEEK_END);
                fseek(fp2,0,SEEK_END);
                fseek(fp3,0,SEEK_END);
                char *buffer = (char*)calloc(1024,1);
                fwrite(buffer,1024,1,fp1);
                delete[] buffer;
                buffer = (char*)calloc(1024,1);
                fwrite(buffer,1024,1,fp2);
                delete[] buffer;
                buffer = (char*)calloc(1024,1);
                fwrite(buffer,1024,1,fp3);
                delete[] buffer;
                long long fSizeF=ftell(fp1)+ftell(fp2)+ftell(fp2);
                if(fSizeF==fSizeS)
                {
                    cout<<"There are some errors during eating your disk drive"<<endl;
                    break;
                }
           }
           fclose(fp1);
           fclose(fp2);
           fclose(fp3);
        }
        return 0;
}

int eMLR(char* limit, char* timeopt, char* rate, char* multSpace, char* multRate)
{
	long long limit_long = atoll(limit), memory_used = 0;
	
	if(!strcmp(multSpace,"b"))
                	limit_long*=1;
       	else if(!strcmp(multSpace,"k"))
                	limit_long*=1024;
	else if(!strcmp(multSpace,"m"))
	                limit_long*=1024*1024;
	else if(!strcmp(multSpace,"g"))
	                limit_long*=1024*1024*1024;
	else
		{
			cout<<"Wrong input data\n";
			return 0;
		}
		
	long long rate_long = atoll(rate);

	if(!strcmp(multRate,"b"))
		rate_long*=1;	
       	else if(!strcmp(multRate,"k"))
                rate_long*=1024;
	else if(!strcmp(multRate,"m"))
	        rate_long*=1024*1024;
	else if(!strcmp(multRate,"g"))
	        rate_long*=1024*1024*1024;
	else
		{
			cout<<"Wrong input data\n";
			return 0;
		}
///////////////////     COUNTING  OF EATED MEMORY PER SECOND     /////////////
	double start = clock ();
	
	void* m;
		while((m = malloc(1024))&&memory_used<1024*1024*1024)
		{
			memset(m,0,1024);
			memory_used+=1024;
		};
	
	double stop =clock();
	double time = (stop/ CLOCKS_PER_SEC) - (start/ CLOCKS_PER_SEC);

	double memoryPerSec = (double)memory_used / time;
	memoryPerSec = (long long)memoryPerSec;
	if (memoryPerSec == 0) 
		memoryPerSec = 1;
	for (int i = 0; i<1024*1024;++i)
		free(           (void*) ((int*)m-1024*i)        ); ////////////     FREEDOM!
///////////////////     END OF COUNTING     /////////////////////
	long long memoryPerTimeopt;
	
	if(!strcmp(timeopt,"s"))
		memoryPerTimeopt = rate_long / memoryPerSec;
       	else if(!strcmp(multRate,"m"))
                memoryPerTimeopt = rate_long / memoryPerSec / 60.0;
	else if(!strcmp(multRate,"h"))
	        memoryPerTimeopt = rate_long / memoryPerSec / 3600.0;
	else if(!strcmp(multRate,"d"))
		memoryPerTimeopt = rate_long / memoryPerSec / 3600.0 / 24.0;
	else
		{
			cout<<"Wrong input data\n";
			return 0;
		}
	
	if (memoryPerTimeopt == 0)
		memoryPerTimeopt = 1;
	
	while((m = malloc(memoryPerTimeopt))&&memory_used<limit_long)
	{
               	m = malloc(memoryPerTimeopt);
		memset(m,0,memoryPerTimeopt);
		memory_used+=memoryPerTimeopt;
	};
	
	return 0;
}

int main(volatile int argc,char** argv)
{
          if(argc<2)
       {
                man();
                return 0;
        }
        double start = clock ();
        char* mode=new char[20];
        strcpy(mode,argv[1]);
        if(strcmp(mode,"ed")&&strcmp(mode,"edl")&&strcmp(mode,"edl")&&strcmp(mode,"ver")&&strcmp(mode,"man")&&strcmp(mode,"eml")&&strcmp(mode,"emlr"))
        {
                cout<<"Not valid mode :"<<mode<<endl;
                return 1;
        }
        if(!strcmp(mode,"ed"))
        {
            if(argc<3)
            {
                cout<<"Error"<<endl;
                return 1;
            }
            cout<<argv[2];
            ed(argv[2]);
        }
	if(!strcmp(mode,"man"))
		man();
	if(!strcmp(mode,"ver"))
		cout<<"You are using "<<name<<" version "<<ver<<vermod<<endl;
	if(!strcmp(mode,"em"))
		em();
        if(!strcmp(mode,"em"))
		em();
	if(!strcmp(mode,"eml"))
	{
			if(!eMl(argv[2],argv[3])){
				while(true)
				return 0;
			}
				else {cout<<"There are some troubles in the system or program"<<endl; return 1;}
	}
        if(!strcmp(mode,"edl"))
        {
            edl(argv[2],argv[3],argv[4]);
	}
	double stop = clock();
	double total = (stop - start) / CLOCKS_PER_SEC;
        cout<<"Done for "<<total<<" sec"<<endl;
        delete[] mode;
        return 0;
}


