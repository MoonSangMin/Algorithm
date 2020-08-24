#include <iostream>
using namespace std;

int main() {
	int height, count = 0, ideal, inc;
	cin >> height >> ideal >> inc;

	int current;
	current = ideal - height;

	while (current > 0) {
		current -= inc;
		count++;
	}

	cout << count;
}