#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7, M = N * 2;
const int maxn = 3500;

struct Node {
	int a, b, x, y;
} node[N];

signed main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		node[i] = {a, b, x, y};
	}

	int qx, qy;
	cin >> qx >> qy;

	int ans = -1;
	for (int i = n; i >= 1; i--) {
		auto[a, b, x, y] = node[i];
		if (qx >= a && qx <= a + x && qy >= b && qy <= b + y) {
			ans = i;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}