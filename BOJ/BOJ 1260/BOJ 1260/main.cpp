#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1001;

int N, M, V;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int idx) {//idx부터 시작한다.
	cout << idx << ' ';

	for (int i = 1; i <= N; i++) {
		if (adjacent[idx][i] && !visited[i]) {//만약 노드 idx와 연결된 점이 있고, 방문하지 않았다면
			visited[i] = 1; //방문하고
			DFS(i); //그 곳부터 다시 DFS를 실시한다.
		}
	}
}

void BFS(int idx) {
	q.push(idx);
	visited[idx] = 1;//idx 부터 시작한다. 노드 idx는 방문한 상태로 시작한다.

	while (!q.empty()) {//큐가 빌 때까지
		idx = q.front();
		q.pop();//idx에 시작값을 넣고, 큐를 비운다.

		cout << idx << ' '; //idx(시작 노드) 출력

		for (int i = 1; i <= N; i++) {//idx에 연결되었고 미방문 노드를 모두 차례로 방문 & visited체크 & 큐에 push
			if (adjacent[idx][i] && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}//for문이 끝나면 큐에 차례대로 노드들이 있을 것. 제일 먼저 방문한노드(idx로 설정된)를 출력하고 pop.
	}//방금 pop된 노드와 연결된 미방문 노드들을 체크하고 큐에 넣는다. 차레대로 수행되면 BFS가 완료된다.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		adjacent[from][to] = 1;
		adjacent[to][from] = 1;
	}

	visited[V] = 1;//시작점은 방문한 상태로 DFS를 수행
	DFS(V);
	cout << '\n';

	memset(visited, false, sizeof(visited));//DFS에서 사용한 visited 배열을 모두 0으로 초기화
	BFS(V);
	cout << '\n';
}