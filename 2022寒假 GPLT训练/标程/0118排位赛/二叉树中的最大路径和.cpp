#include<bits/stdc++.h>
using namespace std;

int n = 0;
int a[10001];
int Max = INT_MIN;

int maxSum(int root)
{//求以root为根的所产生的最大路径和：根本身，左子树最大和+根，右子树最大和+根
    if(root>n) return 0;
    int left = max(0, maxSum(root*2));//求左子树的最大路径和，万一是负数，舍弃 
    int right = max(0, maxSum(root*2+1));//右子树 
    Max = max(Max, left+right+a[root]);//顺便看看左右最大和+根能否刷新Max 
    return max(left, right)+a[root];
}

int main()
{
	while(cin >> a[++n]);
	n--;
	maxSum(1);
	cout << Max;
 	return 0;
}

