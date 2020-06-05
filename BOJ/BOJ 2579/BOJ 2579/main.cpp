#include <iostream>
#include <algorithm>
using namespace std;

int DP[301] = { 0, }, sum[301];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> DP[i];

	sum[1] = DP[1];
	sum[2] = DP[1] + DP[2];

	for (int i = 3; i <= n; i++) {
		sum[i] = max(sum[i - 3] + DP[i - 1] + DP[i], sum[i - 2] + DP[i]);
	}

	cout << sum[n];
}