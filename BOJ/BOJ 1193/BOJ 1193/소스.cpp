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
	int denominator = 0;//�и�
	int numerator = 0;//����

	cin >> n;
	tmp = n;
	if (n == 1) cout << 1 << "/" << 1 << endl;
	else {
		for (int i = 1; tmp > 0; i++) {
			tmp = tmp - i;
			crossNum++;
		}//crossNum�� ���° �밢������ ��Ÿ���� �ִ�
		n = n - TotalSum(crossNum - 1);

		if (crossNum % 2 == 1) {//�밢���� Ȧ���̸�
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
		else {//�밢���� ¦���̸�
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