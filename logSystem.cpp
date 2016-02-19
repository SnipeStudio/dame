#include "header.hpp"

ofstream LogFile;
int WriteLog(char* message)
{
	time_t t;
	struct tm *t_m;
	t=time(NULL);
	t_m=localtime(&t);
	LogFile<<t_m->tm_hour<<":"<<t_m->tm_min<<":"<<t_m->tm_sec<<")"<<message<<std::endl;
	std::cout<<message<<std::endl;
	return 0;
}
int openLog()
{
	LogFile.open("dame_log.log",ios::app);
	if(LogFile)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int closeLog()
{
	LogFile.close();
	return 0;
}