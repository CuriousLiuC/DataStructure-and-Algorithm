//完全背包问题 
//01背包矩阵遍历剩余承重量时倒序，完全背包遍历时正序。!!!!!!!!!!!!!!!!!!!!!!!!!1
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
		//通过每件物品，更新一下dp数组各处的值 
		for(int j=s[i].weight;j<=w;j++)//总要考虑能放得下的区间  和0-1比倒叙，代表会考虑选择过了的情况 
		{
			dp[j] = max(dp[j],dp[j-s[i].weight]+s[i].value);	
		}	
	}
	printf("%d\n",dp[w]);
}
