#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
bool ans[101] = { 0, };
vector<int> part;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int width, partitions;
	cin >> width >> partitions;

	for (int i = 0; i < partitions; i++) {
		int tmp;
		cin >> tmp;
		part.push_back(tmp);
	}

	part.push_back(0);
	part.push_back(width);
	sort(part.begin(), part.end());

	for (auto it = part.rbegin(); it != part.rend(); it++) { //10, 8, 4, 2, 1
		for (auto it2 = part.rbegin() + 1; it2 != part.rend(); it2++) {//8, 4, 2, 1
			if (*it > *it2) {
				ans[*it - *it2] = true;
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		if (ans[i] == true)
			cout << i << ' ';
	}
}