#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n, m;
int map[101][101];
int ans[101][101];
bool visited[101][101];
int dirx[4] = { 1, 0, -1, 0 };
int diry[4] = { 0, 1, 0, -1 }; // [y][x]���̹Ƿ� (0, 1)�� �� (1, 0)�� �� (0, -1)�� �� (-1,0) �� ��

bool IsInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < m && ny < n);
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	ans[y][x] = 1;

	q.push(make_pair(y, x));
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + diry[i];
			int nx = x + dirx[i];

			if (IsInside(ny, nx) && map[ny][nx] && !visited[ny][nx]) {//map�� ����� �ʰ�, �� �� �ְ�(1�̰�), �湮���� �ʾ�����
				visited[ny][nx] = true;
				ans[ny][nx] = ans[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs(0, 0);
	cout << ans[n - 1][m - 1];
}