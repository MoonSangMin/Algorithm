#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;

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