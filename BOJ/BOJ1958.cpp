#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int DP[101][101][101];

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

	for (int i=1; i<=s1.size(); i++) {
		for (int j=1; j<=s2.size(); j++) {
            for(int k=1; k<=s3.size(); k++){
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                    DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
                else
                    DP[i][j][k] = max(max(DP[i - 1][j][k], DP[i][j - 1][k]), DP[i][j][k-1]);
            }
		}
	}


    cout << DP[s1.size()][s2.size()][s3.size()];
}