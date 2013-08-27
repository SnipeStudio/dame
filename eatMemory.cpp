#include "header.hpp"
int eMl(char* limit,char* mult)//Eat memory with certain limit
{
	syslog(LOG_INFO,"Selected eMl mode");
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
		cout<<"Invalid multiplier"<<endl;
		syslog(LOG_INFO,"Invalid multiplier");
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
		cout<<"Couldn\'t allocate more memory"<<endl;
		syslog(LOG_INFO,"Couldn\'t allocate more memory");	
	}
	else
	{
		cout<<"Memory allocated. Waiting for interuption"<<endl;
		syslog(LOG_INFO,"Memory allocated. Waiting for interuption");	
	}
	while(true){};
	return 0;
}

int em()//Eat Memory without limits
{
	syslog(LOG_INFO,"Selected em mode");
	void *m;
	while(m = malloc(1024))
	{
		memset(m,0,1025);
	}
	if(m==0)
	{
		cout<<"Couldn\'t allocate more memory"<<endl;
		syslog(LOG_INFO,"Couldn\'t allocate more memory");	
	}
	while(true){};
	return 0;
}