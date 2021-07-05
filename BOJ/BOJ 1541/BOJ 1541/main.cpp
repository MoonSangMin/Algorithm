// '-'가 나온 시점부터 음수이므로
// '-'가 나올때까지 모두 더하고 '-'가 나오면 모두 뺀다.

#include <iostream>
#include <string>
using namespace std;

int main() {
	string equation;
	cin >> equation;

	string tmp = "";
	bool neg = false; //음수 시작
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