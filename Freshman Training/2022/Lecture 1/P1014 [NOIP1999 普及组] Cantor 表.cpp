#include <bits/stdc++.h>

using namespace std;

signed main() {
	int n;
	int i = 0, j = 0;

	cin >> n;

	while (n > j) {
		i ++;
		j += i;
	}

	if (i & 1) cout << j - n + 1 << '/' << i + n - j;
	else cout << i + n - j << '/' << j - n + 1;

	return 0;
}