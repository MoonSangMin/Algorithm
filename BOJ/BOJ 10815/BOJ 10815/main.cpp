#include <iostream>
using namespace std;

bool cards[20000010] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		
		if (tmp < 0) {
			cards[tmp*(-1) + 10000000] = true;
		}
		else { cards[tmp] = true; }

		
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		
		if (tmp < 0) {
			if (cards[tmp * (-1) + 10000000] == true) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
		else {
			if (cards[tmp] == true) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
	}
}