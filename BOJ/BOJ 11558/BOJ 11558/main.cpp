#include <iostream>
using namespace std;
int cnt = 0;
int ans;
int participants[10001] = { 0, };
bool visited[10001] = { false, };

int DFS(int n) {
	if (n != ans && visited[n] == false) {
		cnt++;
		visited[n] = true;
		return DFS(participants[n]);
	}
	else {
		if (visited[n] == true && n != ans) {
			cnt = 0;
			return 0;
		}
		else {
			cnt++;
			return 0;
		}
	}
}


int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> ans;
		for (int j = 1; j <= ans; j++) {
			cin >> participants[j];
		}

		if (ans == 1 && participants[1] != 1) {
			cout << 0 << '\n';
			continue;
		}
		visited[1] = true;

		DFS(participants[1]);
		cout << cnt << '\n';

		cnt = 0;
		for (int j = 1; j <= ans; j++) {
			participants[j] = 0;
		}
		for (int j = 1; j <= ans; j++) {
			visited[j] = false;
		}
	}
}