#include <bits/stdc++.h>

using namespace std;

signed main() {

	int balance = 0;
	int save = 0;
	for (int i = 1; i <= 12; i++) {
		int money;
		cin >> money;
		balance += 300;
		balance -= money;
		if (balance < 0) {
			cout << '-' << i << '\n';
			return 0;
		}
		else if (balance > 100) {
			save += (balance / 100) * 100;
			balance -= (balance / 100) * 100;
		}
	}


	balance += save * 1.2;
	cout << balance << endl;

	return 0;
}