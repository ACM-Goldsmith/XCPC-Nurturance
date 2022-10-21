#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int a[N];

signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';

	return 0;
}