#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define mem(a,x) memset(a,x,sizeof(a));
typedef long long ll;
const int N=10;
int g[N][N];
int n,m;
int sx,sy;
int ex,ey;
struct node
{
	int x,y,hp,ans;
};
int v[N][N];
/*标记数组，标记这个地方是否来过，
来过了就不要重复入队，
这里用血量来标记，一直存最优的血量 
*/
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans;
void bfs()
{
	queue<node>q;
	q.push({sx,sy,6,0});
	v[sx][sy]=6;
	
	while(q.size())//while(!q.empty())
	{
		node t=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int xx=t.x+dx[i];
			int yy=t.y+dy[i];
			
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			{
				if(g[xx][yy]!=0)
				{				
					int hpp=t.hp-1;
					if(hpp==0) continue;//没血了 
					if(v[xx][yy]>=hpp) continue;//条件更好的走过了 
					if(g[xx][yy]==3)
					{
						ans=t.ans+1;
						return;
					}
					
					else if(g[xx][yy]==4)
					{
						hpp=6;
					}
					
					//就算到了某个有鼠标的格子才死去， 他也不能通过拾取鼠标补满 HP。
					if(hpp>1) 
					{
						q.push({xx,yy,hpp,t.ans+1});					
						v[xx][yy]=hpp;//要注意 v的标记要放在可以入队的情况之下
					}					
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>g[i][j];
			if(g[i][j]==2)
			{
				sx=i,sy=j;
			}			
		}		
	}
	
	ans=0x3f3f3f3f;//min(ans,dist) 
	bfs();
	
	if(ans==0x3f3f3f3f) cout<<-1;
	else cout<<ans;
	return 0;
}
