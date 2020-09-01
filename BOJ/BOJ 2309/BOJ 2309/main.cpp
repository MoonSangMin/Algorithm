#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i, j;
	int dwarfs[9];
	bool flag = true;
	for (i = 0; i < 9; i++) {
		cin >> dwarfs[i];
	}

	int sum = 0;
	vector<int> ans;
	for (i = 0; i < 9; i++)
		sum += dwarfs[i];

	for (i = 0; i < 9; i++)
		ans.push_back(dwarfs[i]);

	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (sum - dwarfs[i] - dwarfs[j] == 100) {
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}

	for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		if (*it == dwarfs[i]) {
			ans.erase(it);
			break;
		}
	}
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		if (*it == dwarfs[j]) {
			ans.erase(it);
			break;
		}
	}

	sort(ans.begin(), ans.end());
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << '\n';
	}
}