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

int house[10000],area[10000]; //���� ��� 

struct Node{
	int id,pt,ht,at; //��� ������ �������� ������� 
};

int num; //��ͥ���� 
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
		fa[i]=-1; //ע�⣬������Ǵ�0��ʼ��ţ�����fa[i]Ҫ��ʼ��Ϊ-1 
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
//	for(int i=0;i<10000;i++)  //���Դ��� ����fa[]����� 
//		cout << fa[i] << ' ';
	map<int,int> mp1,mp2,mp3,mp4; //��ͳ�� 
	for(int i=0;i<10000;i++)
	{
		if(fa[i]!=-1)
		{
			if(mp4[fa[i]]==0) 
				mp3[fa[i]]=i; //��һ��Ԫ��
			mp4[fa[i]]++; //���� 
			mp1[fa[i]]+=house[i]; //�������� 
			mp2[fa[i]]+=area[i]; //����� 
		}
	} 
	for(auto x:mp1) //ͳ���꣬ת�ŵ�node��������� 
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
