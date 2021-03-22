#include <iostream>
#include <queue>
using namespace std;
char map[101][101];
bool visited[101][101] = { false, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c; //row, column
int ans = 0;

bool IsInside(int x, int y) {
	if (x >= 0 && x < c && y >= 0 && y < r) return true;
	else return false;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = true;

	q.push(make_pair(y, x));
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (IsInside(nx, ny) && map[ny][nx]=='#' && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '#' && !visited[i][j]) {
				ans++;
				bfs(i, j);
			}
		}
	}
	cout << ans;
}