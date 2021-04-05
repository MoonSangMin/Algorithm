#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 3; i++) {
		cout << v[i] << ' ';
	}
}