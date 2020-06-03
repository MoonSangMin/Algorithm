#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
		return a.first < b.first;
}

vector<pair<int, string>> info;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;

		info.push_back(make_pair(age, name));
	}

	stable_sort(info.begin(), info.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << info[i].first << ' ' << info[i].second << '\n';
	}
}