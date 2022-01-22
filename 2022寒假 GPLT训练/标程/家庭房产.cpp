#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int fa[N];

int get(int x)
{
	if(fa[x]==-1) return fa[x]=x;
	return fa[x]==x?x:fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
	fa[get(y)]=get(x);
}

int house[10000],area[10000]; //房子 面积 

struct Node{
	int id,pt,ht,at; //编号 人总数 房子总数 面积总数 
};

int num; //家庭个数 
Node node[N];

bool cmp(Node x,Node y)
{
	if((x.at*1.0/x.pt)==(y.at*1.0/y.pt))
		return x.id<y.id;
	return (x.at*1.0/x.pt)>(y.at*1.0/y.pt);
}

int n;

int main()
{
	for(int i=0;i<10000;i++)
		fa[i]=-1; //注意，这道题是从0开始编号，所以fa[i]要初始化为-1 
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int id,f,m,c,k;
		cin >> id >> f >> m >> k;
		get(id);
		if(f!=-1) merge(id,f);
		if(m!=-1) merge(id,m);	
		for(int j=1;j<=k;j++)
		{
			cin >> c;
			merge(id,c);
		}	
		cin >> house[id] >> area[id];
	}
	for(int i=0;i<10000;i++)
		if(fa[i]!=-1)
			get(i);
//	for(int i=0;i<10000;i++)  //调试代码 看看fa[]的情况 
//		cout << fa[i] << ' ';
	map<int,int> mp1,mp2,mp3,mp4; //做统计 
	for(int i=0;i<10000;i++)
	{
		if(fa[i]!=-1)
		{
			if(mp4[fa[i]]==0) 
				mp3[fa[i]]=i; //第一个元素
			mp4[fa[i]]++; //个数 
			mp1[fa[i]]+=house[i]; //房产套数 
			mp2[fa[i]]+=area[i]; //总面积 
		}
	} 
	for(auto x:mp1) //统计完，转放到node里，便于排序 
	{
		int tem=x.first;
		node[++num].id=mp3[tem];
		node[num].pt=mp4[tem];
		node[num].ht=mp1[tem];
		node[num].at=mp2[tem];
	}
	sort(node+1,node+1+num,cmp);
	cout << num << endl;
	for(int i=1;i<=num;i++)
		cout << setw(4) << setfill('0') << node[i].id << ' ' << node[i].pt << ' '  << fixed << setprecision(3) << node[i].ht*1.0/node[i].pt << ' ' << fixed << setprecision(3) << node[i].at*1.0/node[i].pt << endl;
	return 0;
}
