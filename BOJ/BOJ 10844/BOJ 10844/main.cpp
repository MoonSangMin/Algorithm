#include <iostream>
using namespace std;
long long DP[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++)
		DP[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				DP[i][j] = DP[i - 1][j + 1]%1000000000;
			}
			else if (j == 9) {
				DP[i][j] = DP[i - 1][j - 1] % 1000000000;
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	long long res = 0;
	for (int i = 0; i <= 9; i++) {
		res += DP[n][i];
	}
	res %= 1000000000;
	cout << res;
}