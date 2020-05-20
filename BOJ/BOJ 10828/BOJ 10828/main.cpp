#include <iostream>
#include <string>
using namespace std;

int top = -1;
int arr[10001] = { 0, };

int main() {
	int n, cnt = 0;
	string cmd;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "push") {
			int tmp;
			cin >> tmp;

			arr[cnt++] = tmp;
			top = tmp;
		}
		else if (cmd == "top") {
			if (cnt != 0)
				cout << top <<'\n';
			else
				cout << -1 << '\n';
		}
		else if (cmd == "size") {
			if (cnt != 0)
				cout << cnt << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "pop") {
			if (cnt != 0) {
				cout << arr[cnt - 1] << '\n';
				arr[cnt-1] = 0;
				cnt--;
				top = arr[cnt - 1];
			}
			else
				cout << -1 <<'\n';
		}
		else if (cmd == "empty") {
			if (cnt != 0)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
	}
}