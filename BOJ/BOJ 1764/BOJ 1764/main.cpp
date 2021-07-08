#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m, cnt = 0;
	cin >> n >> m;
	vector<string> names;
	vector<string> ans;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		names.push_back(tmp);
	}
	sort(names.begin(), names.end());

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		if (binary_search(names.begin(), names.end(), tmp)) {
			cnt++;
			ans.push_back(tmp);
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}