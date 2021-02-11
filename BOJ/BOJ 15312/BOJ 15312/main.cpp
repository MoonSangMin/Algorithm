#include <iostream>
#include <string>
using namespace std;

int alphabetNum[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2,
1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
char alphabetChar[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int ans[4010] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string nameA;
	string nameB;

	cin >> nameA >> nameB;

	for (int i = 0; i < nameA.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (nameA[i] == alphabetChar[j]) {
				ans[i * 2] = alphabetNum[j];
			}
			if (nameB[i] == alphabetChar[j]) {
				ans[2 * i + 1] = alphabetNum[j];
			}
		}
	}

	int loopCount = nameA.length() * 2;
	while (loopCount > 2) {
		for (int i = 0; i < loopCount - 1; i++) {
			ans[i] += ans[i + 1];
			ans[i] %= 10;
		}
		loopCount--;
	}
	
	cout << ans[0] << ans[1];
}