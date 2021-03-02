#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int cnt = 0;
		int a, b;
		cin >> a >> b;

		for (int i = 0; i < a + b; i++) {
			cnt += i;
		}
		cnt *= (a + b);
		cout << cnt << '\n';
	}
}