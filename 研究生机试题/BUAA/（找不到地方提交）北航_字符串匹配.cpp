//题目未给出
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    while(1)
    {
        if(!(cin>>n))//如果此时没有输入，break，是一个值得记录的点
        {
            break;
        }
        char s[1005][1005];
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        
        //通过匹配
        char pipei[1005];
        
        char qian[1005];
        memset(qian,0,sizeof(qian));
        char zhong[1005];
        memset(zhong,0,sizeof(zhong));
        char hou[1005];
        memset(hou,0,sizeof(hou));
        int flag = 0;
        int countqian = 0;
        int countzhong = 0;
        int counthou = 0;
        
        cin>>pipei;
        int flagl = 1;
        int lenp = strlen(pipei);
        int gad = 0;
        for(int i=0;i<lenp;i++)
        {
            if(pipei[i] == '[' && pipei[i+1] != ']')
            {
                flagl = 0;
                break;
            }
            if(pipei[i]=='['&&pipei[i+1]==']')
            {
                printf("hello world\n");
                gad = 2;
            }
        }
        if(flagl==1)//不包含[  题目里说的太不清楚没有说到类似有关情况
        {
        	int ctct = 0;
            for(int i=0;i<n;i++)
            {
                int lens = strlen(s[i]);
                if(lens+gad!=lenp)
                {
                    continue;
                }
                int flagok = 1;
                for(int j=0;j<lens;j++)
                {
                	if(pipei[ct]=='['||pipei[ct]==']')
                	{
                		ct++;
                		continue;
                	}
                    if(s[i][j] != pipei[ct] && s[i][j] != (pipei[ct] + 'a'-'A') && s[i][j] != (pipei[ct] + 'A' - 'a'))
                    {
                        flagok = 0;
                        break;
                    }
                    ct++;
                }
                if(flagok==1)
                {
                    printf("%d %s\n",i+1,s[i]);
                }
            }
            continue;
        }
        
        
        for(int i=0;i<lenp;i++)
        {
            if(pipei[i] == '[')
            {
                qian[countqian] = '\0';
                flag = 1;
                continue;
            }
            else if(pipei[i]==']')
            {
                zhong[countzhong] = '\0';
                flag = 2;
                continue;
            }
            if(flag==0)
            {
                qian[countqian++] = pipei[i];
            }
            else if(flag==1)
            {
                zhong[countzhong++] = pipei[i];
            }
            else if(flag==2)
            {
                hou[counthou++] = pipei[i];
            }
            
        }
        hou[counthou] = '\0';
        
        
        int lenqian = strlen(qian);
        int lenzhong = strlen(zhong);
        int lenhou = strlen(hou);
        
        for(int i=0;i<n;i++)
        {
            int leni = strlen(s[i]);
            int flagjudge = 1;
            int jiaobiao = 0;
            //printf("s[%d] = %s\n",i+1,s[i]);
            if(leni!=lenqian+1+lenhou)
            {
                //printf("%d break-1\n",i+1);
                continue;
            }
            
            for(int j=0;j<lenqian;j++)
            {
                if(s[i][j] != qian[jiaobiao] && s[i][j] != (qian[jiaobiao] + 'a'-'A') && s[i][j] != (qian[jiaobiao] + 'A' - 'a'))
                {
                    flagjudge = 0;
                    //printf("%d break0\n",i+1);
                    break;
                }
                jiaobiao ++;
            }
            if(flagjudge == 0)
            {
                continue;
            }
            jiaobiao = 0;
            flagjudge = 0;
            for(int j=0;j<lenzhong;j++)
            {
                if(s[i][lenqian] == zhong[j] || s[i][lenqian] == zhong[j]+'a'-'A' ||s[i][lenqian] == zhong[j]+'A'-'a' )
                {
                    flagjudge = 1;
                    // printf("%d break1\n",i+1);
                    break;
                }
            }
            if(flagjudge == 0)
            {
                continue;
            }
            flagjudge = 1;
            for(int j=lenqian+1;j<lenqian+1+lenhou;j++)
            {
                if(s[i][j] != hou[jiaobiao] && s[i][j] != (hou[jiaobiao] + 'a'-'A') && s[i][j] != (hou[jiaobiao] + 'A' - 'a'))
                {
                    flagjudge = 0;
                    //printf("%d break2\n",i+1);
                    break;
                }
                jiaobiao ++;
            }
            if(flagjudge == 1)
            {
                printf("%d %s\n",i+1,s[i]);
            }
            
        }
        
        
    }
}
