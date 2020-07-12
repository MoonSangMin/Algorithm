#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int DP[11] = { 0,1,2,4,0, };
		int n;
		cin >> n;

		for (int i = 4; i <= n; i++) {
			DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
		}
		cout << DP[n] << '\n';
	}
}