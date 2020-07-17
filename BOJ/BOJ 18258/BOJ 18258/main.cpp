#include <iostream>
#include <string>
#include <queue>
using namespace std;
queue<int> Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int tmp;
			cin >> tmp;
			Q.push(tmp);
		}
		else if (cmd == "front") {
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.front() << '\n';
		}
		else if (cmd == "back") {
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.back() << '\n';
		}
		else if (cmd == "size") {
			cout << Q.size() << '\n';
		}
		else if (cmd == "empty") {
			if (Q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "pop") {
			if (Q.empty())
				cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
	}
}