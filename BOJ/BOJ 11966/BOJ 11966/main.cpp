#include <iostream>
#include <cmath>
using namespace std;
unsigned long long arr[31];
int main() {
	int n;
	
	for (int i = 0; i <= 30; i++) {
		arr[i] = pow(2, i);
	}

	cin >> n;
	for (int i = 0; i <= 30; i++) {
		if (n == arr[i]) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}