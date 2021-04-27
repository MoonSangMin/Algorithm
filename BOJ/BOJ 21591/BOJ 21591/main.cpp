#include <iostream>
using namespace std;

int main() {
	int wC, hC, wS, hS;
	cin >> wC >> hC >> wS >> hS;

	if (wC-1 <= wS) {
		cout << 0;
		return 0;
	}
	if (hC-1 <= hS) {
		cout << 0;
		return 0;
	}

	cout << 1;
}