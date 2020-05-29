// (는 push, )는 pop
// empty인 상황에서 pop가 나오면 NO

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, i, j;
	cin >> n;

	for (i = 0; i < n; i++) {
		stack<char> s;
		string input;
		cin >> input;

		for (j = 0; j < input.size(); j++) {
			if (input[0] == ')') {
				cout << "NO" << '\n';
				break;
			}
			
			if(input[j]=='(')
				s.push(input[j]);
			else {
				if (s.empty()) {
					cout << "NO" << '\n';
					break;
				}
				else
					s.pop();
			}
		}
		if (s.empty() && j == input.size())
			cout << "YES" << '\n';
		else if (!s.empty())
			cout << "NO" << '\n';
	}
}