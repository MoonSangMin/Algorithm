#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		priority_queue<int, vector<int>, greater<int>> pq;
		int n, idx;
		cin >> n >> idx;
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			pq.push(tmp);
		}

	}


}