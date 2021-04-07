#include <iostream>
using namespace std;

int main() {
	string p, d;//patient and doctor
	cin >> p >> d;

	if (p.size() < d.size()) {
		cout << "no";
	}
	else {
		cout << "go";
	}
}