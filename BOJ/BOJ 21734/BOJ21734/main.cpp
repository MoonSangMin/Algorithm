#include <iostream>
#include <string>
using namespace std;

int digitSum(int s) {
	int r = 0;
	while (s > 0) {
		r += (s % 10);
		s /= 10;
	}
	return r;
}

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		int loop = digitSum(int(s[i]));

		for (int j = 0; j < loop; j++) {
			cout << s[i];
		}
		cout << '\n';
	}
}