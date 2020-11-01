#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> p;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmpX, tmpY;
		cin >> tmpX >> tmpY;
		p.push_back(make_pair(tmpX, tmpY));
	}

	sort(p.begin(), p.end());

	for (int i = 0; i < N; i++) {
		cout << p[i].first << ' ' << p[i].second << '\n';
	}
}