#include <iostream>
using namespace std;
bool map[1002][1002] = { false, };
bool visited[1002] = { false, };
int u, v;

void dfs(int sp) {//starting point
	visited[sp] = true;

	for (int i = 1; i <= u; i++) {
		if (map[sp][i] == true && !visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	int ans = 0;
	cin >> u >> v;

	for (int i = 0; i < v; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		map[tmp1][tmp2] = true;
		map[tmp2][tmp1] = true;
	}

	for (int i = 1; i <= u; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}