#include <iostream>
#include <algorithm>
using namespace std;
int DP[501][501];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> DP[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			DP[i][j] = max(DP[i][j] + DP[i - 1][j], DP[i][j] + DP[i - 1][j - 1]);
		}
	}

	int ans = DP[n][1];
	for (int i = 2; i <= n; i++) {
		if (ans < DP[n][i])
			ans = DP[n][i];
	}

	cout << ans << '\n';
}