#include<bits/stdc++.h>
using namespace std;

int n = 0;
int a[10001];
int Max = INT_MIN;

int maxSum(int root)
{
    if(root>n) return 0;
    int left = max(0, maxSum(root*2));
    int right = max(0, maxSum(root*2+1));
    Max = max(Max, left+right+a[root]);
    return max(left, right)+a[root];
}

int main()
{
    int x;
	while(cin >> x)
    {
        if(x==0) x = INT_MIN;
        a[++n] = x;
    }
	maxSum(1);
	cout << Max;
 	return 0;
}

