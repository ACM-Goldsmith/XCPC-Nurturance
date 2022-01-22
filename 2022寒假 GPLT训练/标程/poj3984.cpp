#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define mem(a,x) memset(a,x,sizeof(a));
typedef long long ll;
const int N=1e5+10;
int g[5][5];
struct node
{
	int x,y,xx,yy;//现在的坐标 上一个的坐标 
}; 
/*
假如说我从0,0 ->0,1
那么结构体里：
0,1,0,0 
*/
int v[5][5];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int x[5][5];//x[i][j]表示ij这个坐标的上一个x 
int y[5][5];
void bfs()
{
	queue<node>q;
	q.push({0,0,-1,-1});
	v[0][0]=1;
	x[0][0]=-1,y[0][0]=-1;
	while(q.size())
	{
		node t=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int xx=t.x+dx[i];
			int yy=t.y+dy[i];
			
			if(xx>=0&&xx<=4&&yy>=0&&yy<=4)
			{
				if(v[xx][yy]==0&&g[xx][yy]==0)
				{
					v[xx][yy]=1;
					q.push({xx,yy,t.x,t.y});
					x[xx][yy]=t.x;
					y[xx][yy]=t.y;
					//cout<<t.x<<" "<<t.y<<" "<<xx<<" "<<yy<<endl;
				}
			}
		}
	}
}
struct temp
{
	int x,y;
};
vector<temp>ans;
int main()
{
	fir(i,0,4)
		fir(j,0,4)
			scanf("%d",&g[i][j]);
	
	bfs();
	int xx=4,yy=4;
		
	while(xx!=-1&&yy!=-1)
	{		
		ans.push_back({xx,yy});
		//cout<<xx<<" "<<yy<<endl;
		int xxx=x[xx][yy],yyy=y[xx][yy];
		xx=xxx,yy=yyy;
		//不能直接xx=x[xx][yy],yy=y[xx][yy] 
		//因为经过前面的赋值xx已经变了
		//则后面的yy就错了			
	}
	
	for(int i=ans.size()-1;i>=0;i--)
	{
		printf("(%d, %d)\n",ans[i].x,ans[i].y);
	}
	
	//看一下xy的表 
	fir(i,0,4)
	{
		fir(j,0,4)
		{
			cout<<x[i][j]<<","<<y[i][j]<<'\t';
		}
		cout<<endl;
	}
	
	return 0;
}
/*
4 4
x[4][4]=3
y[4][4]=4
*/
