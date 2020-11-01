#include <iostream>
using namespace std;

int TotalSum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int main() {
	int n, tmp=0;
	int crossNum=0;
	int denominator = 0;//분모
	int numerator = 0;//분자

	cin >> n;
	tmp = n;
	if (n == 1) cout << 1 << "/" << 1 << endl;
	else {
		for (int i = 1; tmp > 0; i++) {
			tmp = tmp - i;
			crossNum++;
		}//crossNum은 몇번째 대각선인지 나타내고 있다
		n = n - TotalSum(crossNum - 1);

		if (crossNum % 2 == 1) {//대각선이 홀수이면
			numerator = crossNum;
			denominator = 1;
			if (n == 1) {
				cout << numerator << "/" << denominator << endl;
				return 0;
			}
			else {
				for (int i = 1; i < n; i++) {
					numerator--;
					denominator++;
				}
			}
		}
		else {//대각선이 짝수이면
			numerator = 1;
			denominator = crossNum;
			if (n == 1) {
				cout << numerator << "/" << denominator << endl;
				return 0;
			}
			for (int i = 1; i < n; i++) {
				numerator++;
				denominator--;
			}
		}

		cout << numerator << "/" << denominator << endl;
	}
}