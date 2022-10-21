#include <bits/stdc++.h>

using namespace std;

const int maxn = 3500;

int a[maxn];

signed main() {
	int n;
	cin >> n;

	cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j != i) {
				if (a[j] == 0) a[j] = 1;
				else if (a[j] == 1) a[j] = 0;
			}
		}
		for (int j = 1; j <= n; j++) {
			cout << a[j];
		}
		cout << '\n';
	}


	return 0;
}