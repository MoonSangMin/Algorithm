#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A')
			cout << 'X';
		else if (str[i] == 'B')
			cout << 'Y';
		else if (str[i] == 'C')
			cout << 'Z';
		else
			cout << (char)(str[i] - 3);
	}
}