#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const long long INF = 0xFFFFFFFFFF;

signed main() {
	int len, n;
	cin >> len >> n;
	int minans = 0, maxans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		minans = max(minans, min(x, len - x + 1));
		maxans = max(maxans, max(x, len - x + 1));
	}

	cout << minans << ' ' << maxans << '\n';

	return 0;
}