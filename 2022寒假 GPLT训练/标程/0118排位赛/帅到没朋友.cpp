#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int k, num;
	bool a[100000] = {false};//�±꿴��ID�� 
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
		else cin >> num;//����Ȧֻ�����Լ� 
	}	
	cin >> n;
	int x; 
	bool flag = false, first = true; 
	for(int i=0; i<n; i++)
	{
		cin >> x;
		if(!a[x])//û���� 
		{
			flag = true;
			a[x] = true;
			if(!first) cout << " ";//�����һ������� 
			first = false;
			printf("%05d", x);			
		}
	}	
	if(!flag) cout << "No one is handsome" << endl;	
	return 0;
}
