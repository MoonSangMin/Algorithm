#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<char> ans;
		vector<char> tmp;

		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '-') {
				if (ans.empty())continue;
				else ans.pop_back();
			}
			else if (str[j] == '<') {
				if (ans.empty())continue;
				else {
					tmp.push_back(ans.back());
					ans.pop_back();
				}
			}
			else if (str[j] == '>') {
				if (!ans.empty() && tmp.empty())continue;
				else if (ans.empty() && !tmp.empty()) {
					ans.push_back(tmp.back());
					tmp.pop_back();
				}
				else if (ans.empty() && tmp.empty()) continue;
				else {
					ans.push_back(tmp.back());
					tmp.pop_back();
				}
			}
			else {
				ans.push_back(str[j]);
			}
		}

		while (!tmp.empty()) {
			ans.push_back(tmp.back());
			tmp.pop_back();
		}
		for (int j = 0; j < ans.size(); j++) {
			cout << ans[j];
		}
		cout << '\n';
	}
}