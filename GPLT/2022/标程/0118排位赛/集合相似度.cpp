#include<bits/stdc++.h>
using namespace std;

vector<set<int>> a;

int main()
{
	int n;
	cin >> n;
	int k, x, y;
 	while(n--)
	{		
		cin >> k;
		set<int> tmp;
		while(k--)
		{
			cin >> x;
			tmp.insert(x);//���뵽������ 
		}
		a.push_back(tmp);//���ϲ��뵽a��	
	}
	cin >> n;
	while(n--)
	{
		cin >> x >> y;
		vector<int> res(4000);
		auto itt = set_intersection(a[x-1].begin(), a[x-1].end(), a[y-1].begin(), a[y-1].end(), res.begin());
		int i = itt-res.begin();
		itt = set_union(a[x-1].begin(), a[x-1].end(), a[y-1].begin(), a[y-1].end(), res.begin());
		int j = itt-res.begin();
		printf("%.2f%\n", 100.0*i/j);
	}	
 	return 0;
}

