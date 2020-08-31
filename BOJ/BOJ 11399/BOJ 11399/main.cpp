#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, sum = 0;
	int ans = 0;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		sum += v[i];
		ans += sum;
	}

	cout << ans;
}