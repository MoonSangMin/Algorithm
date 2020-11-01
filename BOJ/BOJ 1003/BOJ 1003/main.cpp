#include <iostream>
using namespace std;
int memo[50] = { 1,1, };

int fibonacci(int n) {
	if (n <= 1) return memo[n];
	else if (memo[n] > 0) return memo[n];
	else{
		return memo[n] = fibonacci(n - 2) + fibonacci(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int numFibo;
		cin >> numFibo;

		if (numFibo == 0)
			cout << "1 0" << '\n';
		else if(numFibo == 1)
			cout << "0 1" << '\n';
		else {
			fibonacci(numFibo);
			cout << memo[numFibo - 2] << ' ' << memo[numFibo - 1] << '\n';
		}
	}
}