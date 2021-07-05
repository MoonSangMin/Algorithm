// '-'�� ���� �������� �����̹Ƿ�
// '-'�� ���ö����� ��� ���ϰ� '-'�� ������ ��� ����.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string equation;
	cin >> equation;

	string tmp = "";
	bool neg = false; //���� ����
	int answer = 0;

	for (int i = 0; i < equation.size(); i++) {
		if (equation[i] == '+' || equation[i] == '-') {
			if (neg) answer -= stoi(tmp);
			else answer += stoi(tmp);
			tmp = "";

			if (equation[i] == '-') neg = true;
		}
		else {
			tmp += equation[i];
		}
	}

	if (neg) answer -= stoi(tmp);
	else answer += stoi(tmp);

	cout << answer;
}