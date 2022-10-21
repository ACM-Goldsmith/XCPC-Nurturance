#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char c;
	string a[100];
	cin >> c >> n;
	getchar();
	for(int i=0; i<n; i++) getline(cin, a[i]);			
	int flag = 1;
	for(int i=0; i<n && flag; i++)
		for(int j=0; j<n; j++)
			if(a[i][j]!=a[n-i-1][n-j-1]) flag = 0;
	if(flag) cout << "bu yong dao le\n";
	for(int i=n-1; i>=0; i--)
	{
		for(int j=n-1; j>=0; j--)
			if(a[i][j]!=' ') cout << c;
			else cout << " ";
		cout << endl;
	}		
 	return 0;
}

