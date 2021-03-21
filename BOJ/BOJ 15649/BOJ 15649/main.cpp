/*#include <iostream>
using namespace std;

int n, m;
bool visited[9] = { false, };
int arr[9] = { 0, };

void perm(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = i;
			perm(depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	perm(0);
}*/