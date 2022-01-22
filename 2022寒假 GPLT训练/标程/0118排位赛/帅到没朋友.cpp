#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int k, num;
	bool a[100000] = {false};//下标看作ID号 
	for(int i=0; i<n; i++)
	{
		cin >> k;
		if(k>1)
		{
			while(k--)
			{
				cin >> num;
				a[num] = true; 
			}
		}
		else cin >> num;//朋友圈只有他自己 
	}	
	cin >> n;
	int x; 
	bool flag = false, first = true; 
	for(int i=0; i<n; i++)
	{
		cin >> x;
		if(!a[x])//没朋友 
		{
			flag = true;
			a[x] = true;
			if(!first) cout << " ";//输出第一个后面的 
			first = false;
			printf("%05d", x);			
		}
	}	
	if(!flag) cout << "No one is handsome" << endl;	
	return 0;
}
