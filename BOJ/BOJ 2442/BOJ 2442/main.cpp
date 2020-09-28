#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string star = "*";
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			cout << ' ';
		}
		cout << star << '\n';
		star += "**";
	}
}