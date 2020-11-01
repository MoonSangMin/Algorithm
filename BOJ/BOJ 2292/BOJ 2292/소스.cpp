#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int count = 0;

	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	else
		n -= 1;
	for (int i = 1; n > 0; i++) {
		n = n - 6 * i;
		count++;
	}

	cout << count + 1 << endl;
}