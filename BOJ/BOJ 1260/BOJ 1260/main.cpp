#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1001;

int N, M, V;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int idx) {//idx���� �����Ѵ�.
	cout << idx << ' ';

	for (int i = 1; i <= N; i++) {
		if (adjacent[idx][i] && !visited[i]) {//���� ��� idx�� ����� ���� �ְ�, �湮���� �ʾҴٸ�
			visited[i] = 1; //�湮�ϰ�
			DFS(i); //�� ������ �ٽ� DFS�� �ǽ��Ѵ�.
		}
	}
}

void BFS(int idx) {
	q.push(idx);
	visited[idx] = 1;//idx ���� �����Ѵ�. ��� idx�� �湮�� ���·� �����Ѵ�.

	while (!q.empty()) {//ť�� �� ������
		idx = q.front();
		q.pop();//idx�� ���۰��� �ְ�, ť�� ����.

		cout << idx << ' '; //idx(���� ���) ���

		for (int i = 1; i <= N; i++) {//idx�� ����Ǿ��� �̹湮 ��带 ��� ���ʷ� �湮 & visitedüũ & ť�� push
			if (adjacent[idx][i] && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}//for���� ������ ť�� ���ʴ�� ������ ���� ��. ���� ���� �湮�ѳ��(idx�� ������)�� ����ϰ� pop.
	}//��� pop�� ���� ����� �̹湮 ������ üũ�ϰ� ť�� �ִ´�. ������� ����Ǹ� BFS�� �Ϸ�ȴ�.
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

	visited[V] = 1;//�������� �湮�� ���·� DFS�� ����
	DFS(V);
	cout << '\n';

	memset(visited, false, sizeof(visited));//DFS���� ����� visited �迭�� ��� 0���� �ʱ�ȭ
	BFS(V);
	cout << '\n';
}