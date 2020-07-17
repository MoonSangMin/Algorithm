#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string origin, key;
	string cipher;
	getline(cin, origin);
	cin >> key;

	while (origin.size() != cipher.size()) {
		for (int i = 0; i < key.size(); i++) {
			cipher.push_back(key[i]);
			if (origin.size() == cipher.size())
				break;
		}
	}

	for (int i = 0; i < origin.size(); i++) {
		if (origin[i] == 32) {
			cipher[i] = 32;
			continue;
		}
		cipher[i] = (origin[i] - cipher[i]) + 96;

		if (cipher[i] < 96)
			cipher[i] = 122 - abs(cipher[i] - 96);
		else if (cipher[i] == 96)
			cipher[i] = 'z';

	}

	cout << cipher << '\n';
}