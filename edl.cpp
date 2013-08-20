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
