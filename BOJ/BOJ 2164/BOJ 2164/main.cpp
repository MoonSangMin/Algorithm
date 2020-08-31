#include <iostream>
#include <queue>
using namespace std;

queue<int> Q;
int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int tmp = i + 1;
		Q.push(tmp);
	}

	for (int i = 0; i < n; i++) {
		Q.pop();
		if (Q.size() == 1)
			break;
		Q.push(Q.front());
		Q.pop();
	}

	cout << Q.front() << '\n';
}