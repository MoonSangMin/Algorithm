#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "아래에 한 줄을 입력하세요.(exit을 입력하면 종료합니다)" << endl;

	while (1) {
		int index = 0;
		cout << ">>";
		getline(cin, s, '\n');
		index = s.length() - 1;
		if (s.compare("exit") == 0)
			return 0;
		for (int i = 0; i < s.length(); i++) {
			cout << s[index--];
		}
		cout << endl;
	}
}