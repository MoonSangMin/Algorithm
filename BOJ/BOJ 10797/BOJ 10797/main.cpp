#include <iostream>
using namespace std;

int main() {
	int n;
	int car[5];
	int cnt = 0;

	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> car[i];
	}

	for (int i = 0; i < 5; i++) {
		if (n == car[i])cnt++;
	}
	cout << cnt;
}