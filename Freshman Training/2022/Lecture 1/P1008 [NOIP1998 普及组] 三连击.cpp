#include <bits/stdc++.h>

using namespace std;

int vis[20];

signed main() {

	for (int i = 100; i <= 999; i++) {
		for (int j = 1; j <= 9; j++) vis[j] = 0;
		int a, b, c;
		a = i, b = i * 2, c = i * 3;

		if (b > 999 || c > 999) continue;

		string sa = to_string(a), sb = to_string(b), sc = to_string(c);

		for (int j = 0; j < 3; j++) {
			vis[sa[j] - '0']++;
			vis[sb[j] - '0']++;
			vis[sc[j] - '0']++;
		}

		bool ok = true;
		for (int j = 1; j <= 9; j++) {
			if (vis[j] > 1 || !vis[j]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << a << ' ' << b << ' ' << c << '\n';
		}

	}


	return 0;
}