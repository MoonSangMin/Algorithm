#include <deque>
#include <string>
#include <iostream>
using namespace std;

deque<int> dq;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_back") {
			int tmp;
			cin >> tmp;
			dq.push_back(tmp);
		}
		else if (cmd == "push_front") {
			int tmp;
			cin >> tmp;
			dq.push_front(tmp);
		}
		else if (cmd == "pop_back") {
			if (dq.empty())cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "pop_front") {
			if (dq.empty())cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty")
			cout << dq.empty() << '\n';
		else if (cmd == "front") {
			if (dq.empty())cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (dq.empty())cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}