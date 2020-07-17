#include <iostream>
using namespace std;

int arr[1001];
int DP[1001];

int main() {
	int n;
	cin >> n;
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		DP[i] = 1;
		for (int j = 1; j < i; j++) {
			if ((arr[i] > arr[j]) && (DP[i] <= DP[j]))
				DP[i] = DP[j] + 1;
		}
	}
	
	int ans = DP[0];

	for (int i = 1; i <= n; i++) {
		if (ans < DP[i])
			ans = DP[i];
	}

	cout << ans;
}