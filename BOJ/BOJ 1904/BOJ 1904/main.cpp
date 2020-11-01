#include <iostream>
using namespace std;
int arr[1000001];

int main() {
	int n;

	cin >> n;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	for (int i = 3; i < n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}

	cout << arr[n - 1] % 15746;
}