#include <iostream>
using namespace std;

long long DP[91] = { 0,1,1,2, };

int main() {
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[n];
}