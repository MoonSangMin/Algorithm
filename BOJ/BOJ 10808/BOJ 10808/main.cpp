#include <iostream>
#include <string>
using namespace std;
int alphabet[26] = { 0, };

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		for (int j = 97; j < 123; j++) {
			if (str[i] == j)
				alphabet[j - 97]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << ' ';
	}
}