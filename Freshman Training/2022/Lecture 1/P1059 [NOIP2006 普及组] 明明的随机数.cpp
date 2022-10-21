#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " " << a << endl;

const int N = 1e4 + 7;

int seen[N], a[N];
int idx;

signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (!seen[x]) {
			a[idx++] = x;
			seen[x] = 1;
		}
	}
	sort(a, a + idx);
	cout << idx << '\n';
	for (int i = 0; i < idx; i++) {
		cout << a[i] << ' ';
	}


	return 0;
}