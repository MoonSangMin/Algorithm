#include <iostream>
using namespace std;

int main() {
	int T, n, k;
	int arr[15][15] = { 0 };

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> k >> n;

		for (int i = 0; i < 15; i++)
			arr[0][i] = i;

		for (int i = 1; i < 15; i++) {
			for (int j = 1; j < 15; j++) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		cout << arr[k][n] << endl;
	}
}