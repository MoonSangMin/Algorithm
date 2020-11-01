#include <iostream>
using namespace std;

long long int fibo[91];

int main() {
	fibo[0] = 1;
	fibo[1] = 1;

	for (int i = 2; i < 91; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int n;
	cin >> n;

	cout << fibo[n-1];
}