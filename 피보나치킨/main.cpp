#include <iostream>
using namespace std;

int Fibo(int n) {
	int f[1000] = { 0,1 };
	if (n <= 1)
		return n;
	else {
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
		}
	}
	return f[n];
}

int SmallFibo(int n) {
	int f1 = 0, f2 = 1, f3 = 1;
	if (n <= 1)
		return n;
	while(f3<=n){
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}
	return f2;
}

int NotFibo(int n) {
	int sf = 0;
	int sum = 0;
	while (n > 0) {
		sf = SmallFibo(n);
		for (int i = 0; i<10; i++) {
			if (Fibo(i) == sf) {
				sum += Fibo(i - 1);
			}
		}
		n -= sf;
	}
	return sum;
}

int main() {
	int n = 0;
	
	cin >> n;

	if (n <= 1) {
		cout << n;
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		if (Fibo(i) == n) {
			cout << Fibo(i - 1);
			return 0;
		}
	}

	cout<<NotFibo(n);
}