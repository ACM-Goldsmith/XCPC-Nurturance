#include<bits/stdc++.h>
using namespace std;

int a[10001];

int find(int x)
{//��x�������� 
	int r = x;
	while(a[r]!=r) r = a[r];
	//int t = x;
	//while(t!=r) x = a[t], a[t] = r, t = x;
	return r;
}

void un(int x, int y)
{//�ϲ�x��y�������ȣ�������������һ��Ȧ���� 
	int px = find(x);//��x��������  
	int py = find(y);//��y��������  
	if(px<py) a[py] = px; //С���Ǹ������� ��ţ����ϲ����������  
    else a[px] = py;
}

int main()
{
	for(int i=0; i<10001; i++) a[i] = i;
	int n;
	cin >> n;	
	set<int> pe;
	int k, x, y;
	for(int i=0; i<n; i++)
	{
		scanf("%d%d", &k, &x);//x:��Ȧ��һ���� 
		pe.insert(x);
		for(int j=0; j<k-1; j++)
		{
			scanf("%d", &y);
			pe.insert(y);
			un(x, y);//ÿһ���˶���ǰ���Ǹ��˺ϲ�����ͬ��Ȧ�ӣ�����������ͬ��������  
			x = y;
		}		
	}
	bool vi[10001] = {0};
	int cnt = 0;
	for(int i=1; i<=pe.size(); i++)
	{
		int pi = find(i);//��i�������� 
		if(vi[pi]==0) cnt++, vi[pi]=1;
	}
	cout << pe.size() << " " << cnt << endl;
	cin >> k;
	for(int i=0; i<k; i++)
	{ 
		scanf("%d%d", &x, &y);
		if(find(x)==find(y)) printf("Y\n");
		else printf("N\n");
	}
 	return 0;
}

