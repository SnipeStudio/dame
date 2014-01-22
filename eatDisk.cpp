#include "header.hpp"
int ed(char* path)//Eat all awailaible disk space
{
    /*
    Function returns:
    0 - if everything ok
    1 - file open error
    */     
        if(path[strlen(path)-1]=='/')
        {
			strcat(path,"eater");              
        }
        FILE *fp1 = fopen(path,"ab");
        FILE *fp2 = fopen(strcat(path,"2"),"ab");
        FILE *fp3 = fopen(strcat(path,"3"),"ab");
        bool error=false;
        long long debug=0;
        if(fp1&&fp2&&fp3)
       {
            while(true)
            {
                fseek(fp1,0,SEEK_END);
                fseek(fp2,0,SEEK_END);
                fseek(fp3,0,SEEK_END);
                char *buffer = (char*)calloc(1024,1);
                if(fwrite(buffer,1024,1,fp1)!=1)
                {
                    WriteLog("There are some errors during eating your disk drive. Failed to write first file");
                    error=true;
                    break;
                }
                debug+=1024;
				if(fwrite(buffer,1024,1,fp2)!=1)
                {
                    WriteLog("There are some errors during eating your disk drive. Failed to write second file");

                    error=true;
                    break;
                }
                debug+=1024;
 				if(fwrite(buffer,1024,1,fp3)!=1)
                {
                    WriteLog("There are some errors during eating your disk drive. Failed to write third file");
                    error=true;
                    break;
                }
                debug+=1024;
                cout<<debug<<"\r";
                delete[] buffer;
           }
           fclose(fp1);
           fclose(fp2);
           fclose(fp3);
        }
        else
        {
        	return 1;
        }
        return 0;
}

int edl(char* path,char* limit,char* mult)//Eat disk with limits
{       
    /*
    Function returns:
    0 - if everything ok
    1 - size multiplier error
    2 - file open error
    3 - error in file write
    */
	long long limit_long=atol(limit);
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
        WriteLog("Wrong input data");          
        return 1;
    }
  	        if(path[strlen(path)-1]=='/')
        {
			strcat(path,"eater");              
        }
    bool error=false;
    FILE *fp1 = fopen(path,"ab");
    FILE *fp2 = fopen(strcat(path,"_1"),"ab");
    FILE *fp3 = fopen(strcat(path,"_2"),"ab");
    long long debug=0;
    if(fp1&&fp2&&fp3)
    {
        long long fSizeS=0,fSizeF=0;
        while(true)
        {
                fseek(fp1,0,SEEK_END);
                fseek(fp2,0,SEEK_END);
                fseek(fp3,0,SEEK_END);
                char *buffer = (char*)calloc(1024,1);
                if(fwrite(buffer,1024,1,fp1)!=1)
                {
                    WriteLog("There are some errors during eating your disk drive. Failed to write first file");
                    error=true;
                    break;
                }
                debug+=1024;
				if(fwrite(buffer,1024,1,fp2)!=1)
             
                {
                    WriteLog("There are some errors during eating your disk drive. Failed to write second file");
                    error=true;
                    break;
                }
                debug+=1024;
 				if(fwrite(buffer,1024,1,fp3)!=1)
                {
                    WriteLog("There are some errors during eating your disk drive. Failed to write third file");
                    error=true;
                    break;
                }
                debug+=1024;
                delete[] buffer;
                if(debug>=limit_long)
                    break;    
                cout<<debug<<"/"<<limit_long<<"\r";
        }
			char* LogBuff= new char[100];
			sprintf(LogBuff,"Bytes written: %d/%l<<(%d%)",debug,limit_long,((debug/limit_long)*100));
            WriteLog(LogBuff);
			delete[] LogBuff;
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
        }
        else
        {
            cout<<"Could not open file from the set"<<endl;
        	return 2;
        }
        if(error)
        {
            return 3;
        }
        return 0;
}

int eDLR(char* path,char* limit, char* multSpace, char* timeopt, char* rate,  char* multRate)//Eat disk with limits and write rate
{
        if(path[strlen(path)-1]=='/')
        {
			strcat(path,"eater");              
        }
    long long limit_long = atol(limit), memory_used = 0;
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
		WriteLog("Wrong input data");
		return 1;
	}
    long long rate_long = atol(rate);
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
		WriteLog("Wrong input data\n");
		return 1;
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

	long double memoryPerSec = (double)memory_used / time;
	memoryPerSec = (long long)memoryPerSec;
	if (memoryPerSec == 0)
		memoryPerSec = 1024;
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
		WriteLog("Wrong input data\n");
		return 1;
	}
	
	if (memoryPerTimeopt == 0)
		memoryPerTimeopt = rate_long;
	start=0;
	FILE *fp1 = fopen(path,"wb");
    fp2 = fopen(strcat(path,"1"),"wb");
    FILE *fp3 = fopen(strcat(path,"2"),"wb");
    if(fp1||fp2||fp3)
    {
        WriteLog("Could not create filestream");
        return 2;
        
    }
    bool error=false;
	while(memory_used<limit_long)
	{
		start=clock();
		fseek(fp1,0,SEEK_END);
        fseek(fp2,0,SEEK_END);
        fseek(fp3,0,SEEK_END);
		char *buffer = (char*)calloc(memoryPerTimeopt,1);
		if(fwrite(buffer,memoryPerTimeopt,1,fp1)!=1)
        {
            WriteLog("There are some errors during eating your disk drive. Failed to write first file");
            error=true;
            break; 
        }
        if(fwrite(buffer,memoryPerTimeopt,1,fp2)!=1)
        {
            WriteLog("There are some errors during eating your disk drive. Failed to write second file");
            error=true;
            break; 
        }
        if(fwrite(buffer,memoryPerTimeopt,1,fp3)!=1)
        {
            WriteLog("There are some errors during eating your disk drive. Failed to write third file");
            error=true;
            break; 
        }
		delete[] buffer;
		memory_used+=memoryPerTimeopt*3;
		while((clock()/ CLOCKS_PER_SEC - start/ CLOCKS_PER_SEC)<timeopt_v);
	}
	fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    if(error)
    {
            return 3;
    }
    return 0;
}