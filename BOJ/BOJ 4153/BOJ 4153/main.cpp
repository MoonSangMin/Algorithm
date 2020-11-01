#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> num;

	for (;;) {
		int tmp;
		for (int i = 0; i < 3; i++) {
			cin >> tmp;
			num.push_back(tmp);
		}
		sort(num.begin(), num.end());
		
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)
			break;
		
		if ((num[0] * num[0] + num[1] * num[1]) == num[2] * num[2]) {
			cout << "right" << '\n';
		}
		else
			cout << "wrong" << '\n';

		num.clear();
	}
}