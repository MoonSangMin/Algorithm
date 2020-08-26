#include <iostream>
using namespace std;

int M[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
	int month, day;
	cin >> month >> day;
	
	int sum = 0;
	for (int i = 1; i < month; i++) {
		sum += M[i - 1];
	}
	sum += day;
	sum %= 7;

	if (sum == 0)
		cout << "SUN";
	else if (sum == 1)
		cout << "MON";
	else if (sum == 2)
		cout << "TUE";
	else if (sum == 3)
		cout << "WED";
	else if (sum == 4)
		cout << "THU";
	else if (sum == 5)
		cout << "FRI";
	else if (sum == 6)
		cout << "SAT";
}