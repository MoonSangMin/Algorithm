#include <iostream>
#include <string>
using namespace std;

int main() {
	bool end = true;

	while (end) {
		string str;
		getline(cin, str);

		if (str == "END") {
			end = false;
			break;
		}

		for (auto it = str.rbegin(); it < str.rend(); it++) {
			cout << *it;
		}

		cout << '\n';
	}
}