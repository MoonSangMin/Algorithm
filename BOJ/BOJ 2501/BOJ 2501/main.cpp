#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) nums.push_back(i);
	}

	if (nums.size() >= k) {
		cout << nums[k - 1];
	}
	else
		cout << 0;
}