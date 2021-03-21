#include <iostream>
using namespace std;

int main() {
	int n, ans[3] = { 0, }; //0은 300초, 1은 60초, 2는 10초 
	cin >> n;

	while (n!=0) {
		if (n >= 300) {
			n -= 300;
			ans[0]++;
		}
		else if (n >= 60) {
			n -= 60;
			ans[1]++;
		}
		else if (n >= 10) {
			n -= 10;
			ans[2]++;
		}
		else if (n < 10) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << ' ';
	}
}