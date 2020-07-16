#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001];
int DP[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	DP[0] = 0; DP[1] = wine[1]; DP[2] = max(wine[1] + wine[2], wine[1]);
	DP[3] = max({DP[2], wine[2] + wine[3], wine[1] + wine[3]});

	for (int i = 4; i <= n; i++) {
		DP[i] = max({ DP[i - 1], DP[i - 2] + wine[i], DP[i - 3] + wine[i] + wine[i - 1] });
	}

	cout << DP[n];
}