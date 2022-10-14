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
/*������飬�������ط��Ƿ�������
�����˾Ͳ�Ҫ�ظ���ӣ�
������Ѫ������ǣ�һֱ�����ŵ�Ѫ�� 
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
					if(hpp==0) continue;//ûѪ�� 
					if(v[xx][yy]>=hpp) continue;//�������õ��߹��� 
					if(g[xx][yy]==3)
					{
						ans=t.ans+1;
						return;
					}
					
					else if(g[xx][yy]==4)
					{
						hpp=6;
					}
					
					//���㵽��ĳ�������ĸ��Ӳ���ȥ�� ��Ҳ����ͨ��ʰȡ��겹�� HP��
					if(hpp>1) 
					{
						q.push({xx,yy,hpp,t.ans+1});					
						v[xx][yy]=hpp;//Ҫע�� v�ı��Ҫ���ڿ�����ӵ����֮��
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
