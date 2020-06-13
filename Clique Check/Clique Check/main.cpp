#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[11][11];
int sum[11] = { 0, };
vector<int> keyVal;
vector<int>::iterator it;
bool endLoop = false;

int main() {
	int n;
	int cliqueSize;
	int keyNode;

	for (int i = 1; i <= 10; i++)
		map[i][0] = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	scanf("%d", &cliqueSize);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i] += map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sum[i] == (cliqueSize - 1)) {
			keyNode = i;
			break;
		}
	}

	keyVal.push_back(keyNode);
	for (int i = 1; i <= n; i++) {
		if (map[keyNode][i] == 1)
			keyVal.push_back(i);
	}
	sort(keyVal.begin(), keyVal.end());

	for (int a : keyVal) {
		for (int b : keyVal) {
			if (a == b) {
				if (map[a][b] != 0) {
					cout << 0;
					endLoop = true;
					break;
				}
			}
			else {
				if (map[a][b] != 1) {
					cout << 0;
					endLoop = true;
					break;
				}
			}
		}
		if (endLoop == true) {
			break;
		}
	}

	if(endLoop==false)
		cout << 1;
}