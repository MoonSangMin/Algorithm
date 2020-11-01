#include <iostream>
using namespace std;

int main() {
	int n, T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		long long int arr[101];
		cin >> n;

		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 1;
		arr[3] = 1;
		arr[4] = 2;
		arr[5] = 2;

		for (int i = 6; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 5];
		}

		cout << arr[n] << '\n';
	}
}