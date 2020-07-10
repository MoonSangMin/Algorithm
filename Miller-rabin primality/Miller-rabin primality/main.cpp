#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;
int cnt = 0;
vector<ull> tester = { 2, 7, 61 };

ull powmod(ull x, ull y, ull n) {
	x %= n;
	ull r = 1;
	while (y > 0) {
		if (y % 2 == 1)
			r = (r * x) % n;
		x = (x * x) % n;
		y /= 2;
	}
	return r;
}

inline bool miller_rabin(ull n, ull a) {
	ull d = n - 1;
	while (d % 2 == 0) {
		if (powmod(a, d, n) == n - 1)
			return true;
		d /= 2;
	}
	ull tmp = powmod(a, d, n);
	return tmp == n - 1 || tmp == 1;
}

bool judge(ull n) {
	if (n <= 1)
		return false;
	if (n <= 10000ULL) {
		for (ull i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	for (ull a : tester)
		if (!miller_rabin(n, a))
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ull n;
	int T;
	bool ans;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		ans = judge(2 * n + 1);
		if (ans == true)
			cnt++;
	}

	cout << cnt;
}