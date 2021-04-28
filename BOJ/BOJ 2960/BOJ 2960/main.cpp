#include <iostream>
using namespace std;

int main() {
	int n, k, cnt = 0;
	bool nums[1001] = { false, };
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		if (nums[i] == false) {
			nums[i] = true;
			cnt++;
			if (cnt == k) {
				cout << i;
				return 0;
			}
			for (int j = i; j <= n; j++) {
				if (j % i == 0) {
					if (nums[j] == false) {
						nums[j] = true;
						cnt++;
						if (cnt == k) {
							cout << j;
							return 0;
						}
					}
				}
			}
		}
	}
}