#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coin;
int cnt;
int ans = 0;

int main() {
	int n, val;
	cin >> n >> val;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
	}

	sort(coin.begin(), coin.end());

	for (auto it = coin.end() - 1; it != coin.begin() - 1; --it) {
		if (*it > val)
			continue;
		else {
			cnt = val / (*it);
			ans += cnt;
			val = val % (*it);
		}

		if (val == 0)break;
	}

	cout << ans;
}