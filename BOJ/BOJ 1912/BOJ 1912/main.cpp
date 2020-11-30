#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];
long long DP[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	DP[0] = arr[0];

	for (int i = 1; i < n; i++) {
		DP[i] = max(arr[i], DP[i - 1] + arr[i]);
	}
	cout << *max_element(DP + 0, DP + n);
}