#include <iostream>
#include <queue>
using namespace std;

queue<int> Q;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int tmp = i + 1;
		Q.push(tmp);
	}

	cout << "<";
	while (!Q.empty()) {
		for (int i = 1; i < k; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		cout << Q.front();

		if (Q.size() != 1)cout << ", ";
		Q.pop();
	}
	cout << ">";
}