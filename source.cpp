#include "header.hpp"
using namespace std;
char ver[6]="2.3";
char name[35]="Disk Drive and Memory Eater(dame)";
char vermod[20]=".2.1";
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
cout<<"| dame edlr - start to eat ddspace with limits,time options and rate           |"<<endl;
cout<<"| USAGE: dame edlr path spacetoeat {b|k|m|g} timeopt ratepertime {b|k|m|g}     |"<<endl;
cout<<line<<endl;
return 0;
}

int main(volatile int argc,char** argv)
{
	openlog("dame",LOG_PID,LOG_USER);
	syslog(LOG_INFO,"%s %s%s",name,ver,vermod);
    char* mods[]={
        "ed",
        "edl",
        "em",
        "ver",
        "man",
        "eml",
        "edlr"
    };
          if(argc<2)
       {
                man();
                return 0;
        }
        double start = clock ();
        char* mode=new char[20];
        strcpy(mode,argv[1]);
        bool flag=false;
        for(char *s:mods)
        {
            if(!strcmp(mode,s))
                flag=true;
     
        }
        if(!flag)
        {
            cout<<"Not valid mode : "<<mode<<endl;
            return 1;
        }
        if(!strcmp(mode,"-v"))
        {
            if(argc<2)
            {
                man();
                return 0;
            }
            cout<<"Hehey-Off we go!"<<endl;
        }
        if(!strcmp(mode,"ed"))
        {
            if(argc<3)
            {
                man();
                return 0;
            }
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
            if(argc<4)
            {
                man();
                return 0;
            }
			if(!eMl(argv[2],argv[3])){
				while(true);
				return 0;
			}
				else {cout<<"There are some troubles in the system or program"<<endl; return 1;}
	}
        if(!strcmp(mode,"edl"))
        {
            if(argc<5)
            {
                man();
                return 0;
            }
            edl(argv[2],argv[3],argv[4]);
	}
	if(!strcmp(mode,"edlr"))
	{
	    if(argc<8)
            {
                man();
                return 0;
            }
            eDLR(argv[2],argv[3],argv[4],argv[5],argv[6],argv[7]);
	}
	
	double stop = clock();
	double total = (stop - start) / CLOCKS_PER_SEC;
        cout<<"Done for "<<total<<" sec"<<endl;
        delete[] mode;
        return 0;
}
