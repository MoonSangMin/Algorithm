#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (1) {
		stack<char> st;

		string s1;
		bool flag = true;
		getline(cin, s1);

		if (s1.length() == 1 || s1[0] == '.')
			return 0;

		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == '(')
				st.push('(');
			else if (s1[i] == '[')
				st.push('[');
			else if (s1[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else {
					flag = false;
					break;
				}
			}
			else if (s1[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag && st.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';

		while (!st.empty())st.pop();
		flag = true;
	}
}