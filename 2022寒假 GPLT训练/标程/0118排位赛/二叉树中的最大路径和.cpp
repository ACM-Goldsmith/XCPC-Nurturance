#include<bits/stdc++.h>
using namespace std;

int n = 0;
int a[10001];
int Max = INT_MIN;

int maxSum(int root)
{//����rootΪ���������������·���ͣ�����������������+��������������+��
    if(root>n) return 0;
    int left = max(0, maxSum(root*2));//�������������·���ͣ���һ�Ǹ��������� 
    int right = max(0, maxSum(root*2+1));//������ 
    Max = max(Max, left+right+a[root]);//˳�㿴����������+���ܷ�ˢ��Max 
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

