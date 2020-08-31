#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
int cnt = 0;

deque<int> dq;

void MoveLeft() {
	dq.push_back(dq.front());
	dq.pop_front();
	cnt++;
}

void MoveRight() {
	dq.push_front(dq.back());
	dq.pop_back();
	cnt++;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int tmp;
		int cur = 1;
		cin >> tmp;

		if (tmp == dq.front()) {
			dq.pop_front();
		}
		else {
			for (deque<int>::iterator it = dq.begin(); it < dq.end(); it++) {
				if (*it == tmp)break;
				cur++;
			}

			int left = cur - 1;
			int right = dq.size() - cur + 1;

			if (left <= right) {
				for (int j = 0; j < left; j++) {
					MoveLeft();
				}
				dq.pop_front();
			}
			else {
				for (int j = 0; j < right; j++) {
					MoveRight();
				}
				dq.pop_front();
			}
		}

	}
	cout << cnt;
}