# Tangent
菜鸟代码

/*最短路
在每年的校赛里，所有进入决赛的同学都会获得一件很漂亮的t-shirt。但是每当我们的工作人员把上百件的衣服从商店运回到赛场的时候，却是非常累的！所以现在他们想要寻找最短的从商店到赛场的路线，你可以帮助他们吗？ 
Input
输入包括多组数据。每组数据第一行是两个整数N、M（N<=100，M<=10000），N表示成都的大街上有几个路口，标号为1的路口是商店所在地，标号为N的路口是赛场所在地，M则表示在成都有几条路。N=M=0表示输入结束。接下来M行，每行包括3个整数A，B，C（1<=A,B<=N,1<=C<=1000）,表示在路口A与路口B之间有一条路，我们的工作人员需要C分钟的时间走过这条路。 
输入保证至少存在1条商店到赛场的路线。 
Output
对于每组输入，输出一行，表示工作人员从商店走到赛场的最短时间
Sample Input
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
Sample Output
3
2*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int INF =0x3f3f3f;
const int MAXN=200;
int map[MAXN][MAXN];
int dis[15000];
int vis[15000];
void MINROAD(int end,int start)
{
	int position;
	for(int i=1;i<=end;i++)
	{
		dis[i]=map[1][i];
		vis[i]=0;
	}
	vis[start]=1;
	for(int i=1;i<=end;i++)
	{
		int min=INF;
		for(int j=1;j<=end;j++)
		{
			if(vis[j]==0&&dis[j]<min)
			{
				position=j;
				min=dis[j];
			}
		}
		vis[position]=1;
		for(int j=1;j<=end;j++)
		{
			if(vis[j]==0&&dis[position]+map[position][j]<dis[j])
			{
				dis[j]=dis[position]+map[position][j];
			}
		}
	}

}
int main()
{
	int n,m;
	int a,b,t;
	while(scanf("%d %d",&n,&m),n||m)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				map[i][j]=INF;
			}
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&a,&b,&t);
			map[a][b]=map[b][a]=t;
		}
		MINROAD(n,1);
		printf("%d\n",dis[n]);
	}
	return 0;
}
