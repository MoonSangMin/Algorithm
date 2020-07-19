#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int DP[1001][1001];
int main() {
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++) {
		DP[i][0] = 0;
	}
	for (int i = 0; i < s2.size(); i++) {
		DP[0][i] = 0;
	}

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[s1.size()][s2.size()];
}