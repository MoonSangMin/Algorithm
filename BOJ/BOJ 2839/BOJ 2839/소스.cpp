#include <iostream>
using namespace std;

int main() {
	int five, three, rest;
	int N;

	cin >> N;
	if ((N % 5) == 0) {
		cout << N / 5;
		return 0;
	}

	five = N / 5;
	rest = N % 5;

	while (five >= 0) {
		if ((rest % 3) == 0) {
			three = rest / 3;
			cout << three + five;
			return 0;
		}
		else {
			rest += 5;
			five--;
		}
	}

	cout << -1;
}