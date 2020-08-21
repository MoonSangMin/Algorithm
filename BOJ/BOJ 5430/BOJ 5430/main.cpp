#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();
	int T;
	cin >> T;

	for (int test = 0; test < T; test++) {
		deque<int> dq;
		string str;
		int n;
		bool flag = true;
		bool rev = true;//true면 원 상태, false면 뒤집어진 상태
		cin >> str >> n;
		char trash;

		if (n == 0)
			cin >> trash;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> trash;
			cin >> tmp;
			dq.push_back(tmp);
		}
		cin >> trash;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R') {
				if (rev == true)
					rev = false;
				else
					rev = true;
			}
			else {
				if (dq.empty()) {
					cout << "error" << '\n';
					flag = false;
					break;
				}
				else
					if (rev == true)
						dq.pop_front();
					else
						dq.pop_back();
			}
		}

		if (flag == false)
			continue;
		else {
			if (rev == true) {
				cout << '[';
				for (int i = 0; i < dq.size(); i++) {
					if (i == (dq.size() - 1))
						cout << dq[i];
					else
						cout << dq[i] << ',';
				}
				cout << ']' << '\n';
			}
			else {
				cout << '[';
				for (int i = dq.size() - 1; i >= 0; i--) {
					if (i == 0)
						cout << dq[i];
					else
						cout << dq[i] << ',';
				}
				cout << ']' << '\n';
			}
		}
	}
}