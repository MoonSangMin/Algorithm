#include <iostream>
#include <string>
using namespace std;
int i;
bool carry = false;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string a, b;
	string sum = "";
	cin >> a >> b;

	if (a.length() != b.length()) {
		if (a.length() > b.length()) {
			for (i = 0; i = a.length() - b.length(); i++) {
				b = "0" + b;
			}
		}
		else {
			for (i = 0; i = b.length() - a.length(); i++) {
				a = "0" + a;
			}
		}
	}

	for (i = 0; i < a.length(); i++) {
		int tmp = (a[i] - 48) + (b[i] - 48);

		if (tmp < 10) {
			if (carry) {
				sum.push_back(tmp + 49);
				carry = false;
			}
			else {
				sum.push_back(tmp + 48);
			}
		}
		else {
			if (carry) {
				sum.push_back(tmp + 39);
			}
			else {
				carry = true;
				sum.push_back(tmp + 38);
			}
		}

		if ((i == a.length() - 1) && carry) {
			sum.push_back(49);
		}
	}
	reverse(sum.begin(), sum.end());

	cout << sum;
}