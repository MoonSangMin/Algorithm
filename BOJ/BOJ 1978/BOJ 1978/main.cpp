#include <iostream>
using namespace std;

int cnt = 0;

bool find(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 1)
			continue;
		else {
			if (find(tmp))
				cnt++;
		}
		
	}

	cout << cnt;
}