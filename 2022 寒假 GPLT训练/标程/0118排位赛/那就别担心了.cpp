#include<bits/stdc++.h>
using namespace std;

vector<int> a[501];//a[i]: i���Ƴ������� 
int cnt[501];//cnt[i]: i���յ��·����
int flag = 1;//�Ƿ� �߼���Ǣ 

int dfs(int x, int y)
{//��x��y(�յ�)��·������ 
	if(cnt[x]==0)//cnt[x]!=0: ˵��֮ǰ������������ 
        for(int t:a[x]) cnt[x] += dfs(t, y);//�������ƽ�����x����һ����㵽�յ��·������֮�� 
	if(cnt[x]==0) flag = 0; //����������cnt[x]Ϊ0��˵������Ǣ 
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
	cnt[y] = 1;//�յ㵽�յ��·������Ϊ1 
	int res = dfs(x, y);
	if(flag) cout << res << " Yes"; 
	else cout << res << " No"; 
 	return 0;
}

