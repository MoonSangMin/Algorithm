#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}

		for (int j = n - 1; j > i; j--) {
			cout << " ";
		}
		
		for (int j = n - 1; j > i; j--) {
			cout << " ";
		}

		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			cout << "*";
		}

		for (int j = 0; j <= i; j++) {
			if (i == n - 1)
				return 0;
			else
				cout << " ";
		}

		for (int j = 0; j <= i; j++) {
			if (i == n - 1)
				return 0;
			else
				cout << " ";
		}

		for (int j = n - 1; j > i; j--) {
			cout << "*";
		}
		cout << '\n';
	}
}