
int getSum(int x) {
	sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum += i * j;
	return sum;
}



int getSum(int x) {
	sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			sum += i * j;
	return sum;
}

int getSum(int x) {
	sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = n; j <= n + 5; j++)
			sum += i * j;
	return sum;
}