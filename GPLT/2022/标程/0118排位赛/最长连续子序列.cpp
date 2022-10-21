#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100000];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
    int Max = 0;
    int cnt = 1;
    for(int i=1; i<n; i++)
    {
        if(a[i]==a[i-1]+1) cnt++;
        else (a[i]==a[i-1]) continue;
        else 
        {
            if(cnt>Max) Max = cnt;
            cnt = 1;
        }
    }
	cout << max(Max, cnt);
 	return 0;
}

