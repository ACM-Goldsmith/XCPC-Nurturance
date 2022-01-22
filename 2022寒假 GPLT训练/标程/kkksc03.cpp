#include <iostream>
using namespace std;

int cost[70];//每道题目的时间 
int maxval = 0;//左脑不超过总时间一半的最大题目时间和 
int remain = 0;//剩下没有选过的题目的时间和 
int sum = 0;//总的时间和 
int n = 0;//当前科目总的题目数
int total = 0;//当前科目所有题目的时间总和 

int dfs(int t, int curval) {
	if (t == n) {//所有题目都选完了 
		maxval = max(curval, maxval);//与前面的最优值比较，决定是否需要更新 
		return total - maxval;//由于左边的数字和小于时间和的一半，所以返回右边需要的时间 
	}
	
	remain -= cost[t];
	
	//当前要做选择是否把第t道题目加入左边的集合 
	//1、将当前第t道题目加入左边的集合 
	//约束函数。规定左边所有选择题目的时间和不超过总时间的一半 
	if (curval + cost[t] <= total / 2) {
		dfs(t+1, curval + cost[t]);	
	}
	
	//2、不把当前第t道题目加入左边的集合 
	//限界函数，如果这个分支即使加上后面没选任务的所有的值
	//都不可能超过前面的最优值，则不需要搜索
	if (curval + remain > maxval)  
		dfs(t+1, curval);
		
	remain += cost[t]; 
	return total - maxval;
}

int main() {
	int s[4];//每个科目包含的题目数 
	for (int i = 0; i < 4; i++)
		cin >> s[i];
	sum = 0;
	for (int i = 0; i < 4; i++) {
		total = 0;
		for (int j = 0; j < s[i]; j++) {
			cin >> cost[j];
			total += cost[j];
		}

		n = s[i];
		remain = total;
		maxval = 0;
		sum += dfs(0, 0);
	}
	
	cout << sum << endl;
} 
