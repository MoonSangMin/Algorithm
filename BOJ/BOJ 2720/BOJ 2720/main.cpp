#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int money, qCount = 0, dCount = 0, nCount = 0, pCount = 0;
		//q는 25센트, d는 10센트, n은 5센트, p는 1센트
		cin >> money;

		while (money >= 25) {
			money -= 25;
			qCount++;
		}
		while (money >= 10) {
			money -= 10;
			dCount++;
		}
		while (money >= 5) {
			money -= 5;
			nCount++;
		}
		while (money >= 1) {
			money -= 1;
			pCount++;
		}

		cout << qCount << ' ' << dCount << ' ' << nCount << ' ' << pCount << '\n';
	}
}