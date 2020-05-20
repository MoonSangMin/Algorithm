#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, h, w;
	vector <pair<int, int>> p;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w >> h;
		p.push_back(make_pair(w, h));
	}

	for (int i = 0; i < n; i++) {
		int rank = 0;
		for (int j = 0; j < n; j++) {
			if (p[i].first < p[j].first && p[i].second < p[j].second) {
				rank++;
			}
		}
		cout << rank + 1 << ' ';
	}
}