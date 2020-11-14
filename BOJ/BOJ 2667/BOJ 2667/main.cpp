#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
int map[26][26];
int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,1,0,-1 }; //right, down, left, up
bool visited[26][26];
int groupCount[314] = { 0, };
int cnt = 0;

bool IsInside(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		groupCount[cnt]++;

		for (int i = 0; i < 4; i++) {
			int ny = y + diry[i];
			int nx = x + dirx[i];

			if (IsInside(nx, ny) && map[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	
	sort(groupCount, groupCount + 314);
	cout << cnt << '\n';
	for (int i = 0; i < 314; i++) {
		if (groupCount[i] != 0) {
			cout << groupCount[i] << '\n';
		}
	}
}