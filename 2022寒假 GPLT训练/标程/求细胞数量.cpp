#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define mem(a,x) memset(a,x,sizeof(a));
typedef long long ll;
const int N=1e2+10;
int n,m;
char mp[N][N]; 
int ans;
int v[N][N];
struct node
{
	int x,y;
};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs(int x,int y)
{
	queue<node>q;
	q.push({x,y});
	v[x][y]=1;
	while(q.size())
	{
		node t=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int xx=t.x+dx[i];
			int yy=t.y+dy[i];
			
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			{
				if(!v[xx][yy]&&mp[xx][yy]!='0')
				{
					v[xx][yy]=1;
					q.push({xx,yy});
				}
			}			
		}
	}
}

int main()
{
	cin>>n>>m;
	fir(i,1,n)
		fir(j,1,m)
			cin>>mp[i][j];
	
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]!='0'&&v[i][j]==0)
			{
				v[i][j]=1;
				bfs(i,j);
				ans++;
			}
		}
	}	
	cout<<ans;
	return 0;
}
