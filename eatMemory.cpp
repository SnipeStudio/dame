#include "header.h"
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
                limit_long/=2;
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