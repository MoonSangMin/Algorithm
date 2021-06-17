#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int a, b, tmp = 1;
		cin >> a >> b;
		for (int i = 0; i < b; i++) {
			tmp *= a;
			tmp %= 10;
		}
		if (tmp == 0){
			cout << 10 << '\n';
		}
		else{
			cout << tmp << '\n';
		}
	}
}