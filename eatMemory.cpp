#include "header.hpp"
int dame::eMl(char* limit,char* mult)//Eat memory with certain limit
{
	unsigned long long limit_long=atol(limit),memory_used=0;
	if(!strcmp(mult,"b"))
		limit_long*=1;
	else if(!strcmp(mult,"k"))
		limit_long*=1024;
	else if(!strcmp(mult,"m"))
		limit_long*=1024*1024;
	else if(!strcmp(mult,"g"))
		limit_long*=1024*1024*1024;
	else
	{
		dame::WriteLog("Invalid multiplier");
		 return 1;
	}
	void* m;
	while((m = malloc(1024))&&memory_used<limit_long)
	{
		memset(m,0,1025);
		memory_used+=1024;
	};
	if(m==0)
	{
		dame::WriteLog("Couldn\'t allocate more memory");
	}
	else
	{
		dame::WriteLog("Memory allocated. Waiting for interuption");
	}
	while(true){};//using to prevent free memory
	return 0;
}

int dame::em()//Eat Memory without limits
{
	void *m;
	while(m = malloc(1024))
	{
		memset(m,0,1024);
	}
	if(m==0)
	{
		dame::WriteLog("Couldn\'t allocate more memory");
	}
	while(true){};//using to prevent free memory
	return 0;
}