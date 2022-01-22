#include <iostream> 
using namespace std;

int n;
int c;
int w[110];
int v[110];
int maxv = 0;

void dfs(int t, int cr, int cv) {
	if (t > n) {
		maxv = max(maxv, cv);
		return;
	}
	
	//选第t个物品
	if (w[t] <= cr) {
		dfs(t+1, cr-w[t], cv+v[t]);
	}
	
	//不选第t个物品 
	dfs(t+1, cr, cv);	
}


int main()  {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
		
	dfs(1, c, 0);
	cout << maxv << endl;
}
