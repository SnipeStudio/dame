#include "header.h"
int edl(char* path,char* limit,char* mult)
{        long long limit_long=atol(limit);
        if(!strcmp(mult,"b"))
            limit_long*=1;
        else
        if(!strcmp(mult,"k"))
            limit_long*=1024;
        else
        if(!strcmp(mult,"m"))
            limit_long*=1024*1024;
        else
        if(!strcmp(mult,"g"))
            limit_long*=1024*1024*1024;
        else
        {
            cout<<"Wrong input data"<<endl;
            return -1;
        }
        FILE *fp1 = fopen(path,"ab");
        FILE *fp2 = fopen(strcat(path,"_1"),"ab");
        FILE *fp3 = fopen(strcat(path,"_2"),"ab");
        long long debug=0;
        if(fp1&&fp2&&fp3)
        {
            long long fSizeS=0,fSizeF=0;
            while(true)
            {
                fSizeS=ftell(fp1)+ftell(fp2)+ftell(fp3);
                char *buffer = (char*)calloc(1024,1);
                fwrite(buffer,1024,1,fp1);
                fwrite(buffer,1024,1,fp2);
                fwrite(buffer,1024,1,fp3);
                debug+=1024+1024+1024;
                delete[] buffer;
               cout<<debug<<"/"<<limit_long<<"\r";
                long long fSizeF=ftell(fp1)+ftell(fp2)+ftell(fp3);
                if(fSizeF>=limit_long)
                    break;
                if(fSizeF==fSizeS&&fSizeF<limit_long)
                {
                    cout<<"There are some errors during writing file"<<endl;
                    fclose(fp1);
                    fclose(fp2);
                    fclose(fp3);
                    return -1;
                }
            }
            cout<<"Bytes written: "<<debug<<"/"<<limit_long<<"("<<debug/limit_long*100<<"%)"<<endl;
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
        }
        else
        {
            cout<<"Could not create filestream"<<endl;
        }
        return 0;
}

int eDLR(char* path,char* limit, char* multSpace, char* timeopt, char* rate,  char* multRate)
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
		return -1;
	}
    long long rate_long = atoll(rate);
	if(!strcmp(multRate,"b"))
		rate_long*=1;	
    else if(!strcmp(multRate,"k"))
                rate_long*=1024;
	else if(!strcmp(multRate,"m"))
	        rate_long*=1024*1024;
    else if(!strcmp(multRate,"g"))
	        rate_long*=1024*1024;
	else
	{
		cout<<"Wrong input data\n";
		return -1;
	}
//Counter of disk drive consume
	double start = clock ();
	FILE *fp2 = fopen(path,"ab");
	while(memory_used<1024*1024)
	{
		fseek(fp2,0,SEEK_END);
		char *buffer = (char*)calloc(1024,1);
		fwrite(buffer,1024,1,fp2);
		delete[] buffer;
		memory_used+=1024;
	}
	fclose(fp2);
	
	double stop =clock();
	double time = (stop/ CLOCKS_PER_SEC) - (start/ CLOCKS_PER_SEC);

	double memoryPerSec = (double)memory_used / time;
	memoryPerSec = (long long)memoryPerSec;
	if (memoryPerSec == 0)
		memoryPerSec = 1;
//end of counter
	long long memoryPerTimeopt=0;
	long long timeopt_v=1;
	if(!strcmp(timeopt,"s"))
		memoryPerTimeopt = rate_long / memoryPerSec;
    else if(!strcmp(multRate,"m"))
    {
        memoryPerTimeopt = rate_long / memoryPerSec;
        timeopt_v*=60;
    }
	else if(!strcmp(multRate,"h"))
	{
	    memoryPerTimeopt = rate_long / memoryPerSec;
        timeopt_v*=3600;
	}
	else
	{
		cout<<"Wrong input data\n";
		return -1;
	}
	
	if (memoryPerTimeopt == 0)
		memoryPerTimeopt = rate_long;
	start=0;
	FILE *fp1 = fopen(path,"wb");
    fp2 = fopen(strcat(path,"1"),"wb");
    FILE *fp3 = fopen(strcat(path,"2"),"wb");
	while(memory_used<limit_long)
	{
		start=clock();
		fseek(fp1,0,SEEK_END);
        fseek(fp2,0,SEEK_END);
        fseek(fp3,0,SEEK_END);
		char *buffer = (char*)calloc(memoryPerTimeopt,1);
		fwrite(buffer,memoryPerTimeopt,1,fp1);
        fwrite(buffer,memoryPerTimeopt,1,fp2);
        fwrite(buffer,memoryPerTimeopt,1,fp3);
		delete[] buffer;
		memory_used+=memoryPerTimeopt*3;
		while((clock()/ CLOCKS_PER_SEC - start/ CLOCKS_PER_SEC)<timeopt_v);
	}
	fclose(fp1);
    fclose(fp2);
    fclose(fp3);
	return 0;	
}