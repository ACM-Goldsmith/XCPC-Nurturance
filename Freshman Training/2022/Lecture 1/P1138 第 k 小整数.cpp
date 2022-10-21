#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7, M = N * 2;
const int maxn = 3500;

int w[N];

signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		w[x] = 1;
	}

	int cnt = 0, ans = -1;
	for (int i = 0; i <= 30000; i++) {
		if (w[i]) {
			cnt++;
			if (cnt == k) {
				ans = i;
				break;
			}
		}
	}

	if(ans != -1)
		cout << ans << '\n';
	else 
		cout << "NO RESULT" << '\n';

	return 0;
}