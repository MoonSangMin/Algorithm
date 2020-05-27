#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001] = { 0, };//���� ���� �ϱ� ���� DP[0]�� �Ⱦ���

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0)DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0)DP[i] = min(DP[i], DP[i / 2] + 1);
	}

	cout << DP[n];
}