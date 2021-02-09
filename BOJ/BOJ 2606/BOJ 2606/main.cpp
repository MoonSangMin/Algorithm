#include <iostream>
using namespace std;

int map[101][101] = { 0, };
bool visited[101] = { 0, };
int ans = 0;
int V, E;

void DFS(int v) {
	visited[v] = true;
	ans++;

	for (int i = 1; i <= V; i++) {
		if (visited[i] == 0 && map[v][i] == 1) {
			DFS(i);
		}
	}
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	DFS(1);

	cout << ans - 1;
}