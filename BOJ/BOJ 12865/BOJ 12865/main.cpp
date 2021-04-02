#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> thing;
int DP[102][100002];

int main() {
	int n, w;
	cin >> n >> w;//������ ����, ���� ����

	thing.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		int tmpV, tmpW;
		cin >> tmpV >> tmpW;
		thing.push_back(make_pair(tmpV, tmpW));//first�� V, second�� W
	}

	for (int i = 1; i <= n; i++) {//������ ������ŭ
		for (int j = 1; j <= w; j++) {//j�� �ӽ� ������ ����
			if (thing[i].first > j) DP[i][j] = DP[i - 1][j];
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - thing[i].first] + thing[i].second);
			}
		}
	}

	cout << DP[n][w];
}