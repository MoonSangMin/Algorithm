#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int money, qCount = 0, dCount = 0, nCount = 0, pCount = 0;
		//q�� 25��Ʈ, d�� 10��Ʈ, n�� 5��Ʈ, p�� 1��Ʈ
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