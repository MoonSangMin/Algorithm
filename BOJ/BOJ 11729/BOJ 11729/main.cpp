#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector <pair<int, int>> v;

void Hanoi(int n, int from, int by, int to) {
	if (n == 1) v.push_back(make_pair(from, to));
	else{
		Hanoi(n - 1, from, to, by);//��� ������� �������� �ᱹ 2���� �������� ����.
		v.push_back(make_pair(from, to));//���� ū ������ ù ��°���� 3��°��
		Hanoi(n - 1, by, from, to);//�������� 3��°��
	}
}

int main() {
	int n, count;
	scanf_s("%d", &n);

	count = (int)pow(2, n) - 1;
	printf("%d\n", count);
	Hanoi(n, 1, 2, 3);//1���� 2�� ���� 3���� ����.

	for (int i = 0; i < count; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
}