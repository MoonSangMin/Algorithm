#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num[10] = { 0, };

int main() {
	int n;
	cin >> n;
	while (1) {
		int tmp = n % 10;
		for (int i = 0; i < 10; i++) {
			if (tmp == i) {
				num[i]++;
				break;
			}
		}
		if (n / 10 == 0)break;
		n/= 10;
	}

	if (num[6] != 0 && num[9] == 0) {
		num[6] = num[6] + num[6] % 2;
		num[6] /= 2;
	}
	else if (num[9] != 0 && num[6] == 0) {
		num[9] = num[9] + num[9] % 2;
		num[9] /= 2;
	}
	else {
		num[6] += num[9];
		num[6] = num[6] + num[6] % 2;
		num[6] /= 2;
	}

	cout << *max_element(num + 0, num + 10);
}