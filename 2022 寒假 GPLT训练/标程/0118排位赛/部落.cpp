#include<bits/stdc++.h>
using namespace std;

int a[10001];

int find(int x)
{//找x的最祖先 
	int r = x;
	while(a[r]!=r) r = a[r];
	//int t = x;
	//while(t!=r) x = a[t], a[t] = r, t = x;
	return r;
}

void un(int x, int y)
{//合并x和y的最祖先，这样他俩就是一个圈子了 
	int px = find(x);//找x的最祖先  
	int py = find(y);//找y的最祖先  
	if(px<py) a[py] = px; //小的那个最祖先 编号，当合并后的最祖先  
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
		scanf("%d%d", &k, &x);//x:本圈第一个人 
		pe.insert(x);
		for(int j=0; j<k-1; j++)
		{
			scanf("%d", &y);
			pe.insert(y);
			un(x, y);//每一个人都跟前面那个人合并到相同的圈子，即他们有相同的最祖先  
			x = y;
		}		
	}
	bool vi[10001] = {0};
	int cnt = 0;
	for(int i=1; i<=pe.size(); i++)
	{
		int pi = find(i);//找i的最祖先 
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

