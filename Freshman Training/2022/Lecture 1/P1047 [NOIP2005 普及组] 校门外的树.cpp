#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 7;

int a[N];

signed main() {
	int len, n;
	cin >> len >> n;

	for (int cas = 1; cas <= n; cas++) {
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r; i++) {
			a[i] = 1;
		}
	}

	int tree = 0;
	for (int i = 0; i <= len; i++) {
		if (!a[i]) tree++;
	}

	cout << tree << '\n';

	return 0;
}