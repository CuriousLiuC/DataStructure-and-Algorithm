//��ȫ�������� 
//01�����������ʣ�������ʱ������ȫ��������ʱ����!!!!!!!!!!!!!!!!!!!!!!!!!1
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct node
{
	int weight;
	int value;
};
int main(void)
{
	struct node s[105];
	int n,w;
	scanf("%d%d",&n,&w);
	int dp[100005];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&s[i].weight,&s[i].value);
	}
	
	for(int i=0;i<n;i++)
	{
		//ͨ��ÿ����Ʒ������һ��dp���������ֵ 
		for(int j=s[i].weight;j<=w;j++)//��Ҫ�����ܷŵ��µ�����  ��0-1�ȵ��𣬴���ῼ��ѡ����˵���� 
		{
			dp[j] = max(dp[j],dp[j-s[i].weight]+s[i].value);	
		}	
	}
	printf("%d\n",dp[w]);
}
