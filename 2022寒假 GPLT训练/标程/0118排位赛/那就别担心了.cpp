#include<bits/stdc++.h>
using namespace std;

vector<int> a[501];//a[i]: i能推出的命题 
int cnt[501];//cnt[i]: i到终点的路径数
int flag = 1;//是否 逻辑自洽 

int dfs(int x, int y)
{//求x到y(终点)的路径数量 
	if(cnt[x]==0)//cnt[x]!=0: 说明之前已求过这个问题 
        for(int t:a[x]) cnt[x] += dfs(t, y);//把问题推进到求x的下一个结点到终点的路径数量之和 
	if(cnt[x]==0) flag = 0; //如果求出来的cnt[x]为0，说明不自洽 
	return cnt[x];		
} 

int main()
{
	int n, m;
	cin >> n >> m;
	int x, y;
	for(int i=0; i<m; i++) 
	{
		cin >> x >> y;
		a[x].push_back(y);
	}
	cin >> x >> y;
	cnt[y] = 1;//终点到终点的路径数量为1 
	int res = dfs(x, y);
	if(flag) cout << res << " Yes"; 
	else cout << res << " No"; 
 	return 0;
}

