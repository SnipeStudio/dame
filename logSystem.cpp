#include "header.hpp"

std::ofstream LogFile;
int dame::WriteLog(char* message)
{
	time_t t;
	struct tm *t_m;
	t=time(NULL);
	t_m=localtime(&t);
	LogFile<<t_m->tm_hour<<":"<<t_m->tm_min<<":"<<t_m->tm_sec<<")"<<message<<std::endl;
	std::cout<<message<<std::endl;
	return 0;
}
bool dame::openLog()
{
	LogFile.open("dame_log.log",std::ios::app);
	if(LogFile)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int dame::closeLog()
{
	LogFile.close();
	return 0;
}