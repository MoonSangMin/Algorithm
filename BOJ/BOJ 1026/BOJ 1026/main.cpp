#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

bool desc(int a, int b) {
	if (a <= b)
		return false;

	return true;
}

int main() {
	int n, S = 0;
	int A[51], B[51];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	sort(A, A+n);
	sort(B, B+n, desc);

	for (int i = 0; i < n; i++) {
		S += (A[i] * B[i]);
	}

	cout << S;
}