#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector <pair<int, int>> v;

void Hanoi(int n, int from, int by, int to) {
	if (n == 1) v.push_back(make_pair(from, to));
	else{
		Hanoi(n - 1, from, to, by);//재귀 방식으로 마지막엔 결국 2개의 원판으로 생각.
		v.push_back(make_pair(from, to));//제일 큰 원판을 첫 번째에서 3번째로
		Hanoi(n - 1, by, from, to);//나머지를 3번째로
	}
}

int main() {
	int n, count;
	scanf_s("%d", &n);

	count = (int)pow(2, n) - 1;
	printf("%d\n", count);
	Hanoi(n, 1, 2, 3);//1에서 2를 거쳐 3으로 간다.

	for (int i = 0; i < count; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
}