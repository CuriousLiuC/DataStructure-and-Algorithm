//B-MͶƱ�㷨�������г��ִ���>n/2�� 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	int jishu = 0;
  	int zhongshu = 0;
  	int n;
  	cin>>n;
  	int temp;
	for(int i=0;i<n;i++)
  	{
  		cin>>temp;
		if (jishu == 0) {
            zhongshu = temp;
        }
        jishu += (temp == zhongshu) ? 1 : -1;
	}
  	printf("%d\n",zhongshu); 
} 
