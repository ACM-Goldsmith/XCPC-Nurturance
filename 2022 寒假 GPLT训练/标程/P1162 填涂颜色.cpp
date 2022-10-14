#include<bits/stdc++.h>
using namespace std;
#define fir(i,a,n) for(int i=a;i<=n;i++)
#define mem(a,x) memset(a,x,sizeof(a));
typedef long long ll;
const int N=30+10;
int n;
int g[N][N]; 
struct node
{
	int x,y;
};
int v[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs(int x,int y)
{
	queue<node>q;
	q.push({x,y});
	v[x][y]=1;
	g[x][y]=2;
	while(q.size())
	{
		node t=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int xx=t.x+dx[i];
			int yy=t.y+dy[i];
			
			if(!v[xx][yy]&&g[xx][yy]==0)
			{
				g[xx][yy]=2;
				q.push({xx,yy});
			}
		}
	}
}

void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
}
int judge(int x,int y)//�ж�������ڲ������� 
{
	int flag=0;
	for(int i=x;i>=1;i--)//�����Ƿ���1 
	{		
		if(g[i][y])
		{
			flag++;
			break;
		}	
	}
	
	for(int i=x;i<=n;i++)//�� 
	{
		if(g[i][y])
		{
			flag++;
			break;
		}
	}
	
	for(int j=y;j>=1;j--)//�� 
	{
		if(g[x][j])
		{
			flag++;
			break;
		}
	}
	
	for(int j=y;j<=n;j++)//�� 
	{
		if(g[x][j])
		{
			flag++;
			break;
		}
	}
	
	if(flag==4) return 1;
	else return 0;
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];			
		}
	//print();	
	
	//��bfs������Χ��0���2
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{			
			if(g[i][j]==0&&judge(i,j))
			{
				bfs(i,j);//��������ͨ�� ����ֻ��bfsһ�μ��� 
				goto endd;//Ҳ����break���� 
			}
		}
	}
	
	endd:
		print();
	return 0;
}
