#include <bits/stdc++.h>

using namespace std;

int a[50];

signed main() {

	for (int i = 1; i <= 10; i++) cin >> a[i];

	int height;
	cin >> height;

	int ans = 0;
	for (int i = 1; i <= 10; i++) {
		if (30 + height >= a[i]) {
			ans++;
		}
	}

	cout << ans << '\n';


	return 0;
}