#include <iostream>
using namespace std;

int main() {
	int V, A, B;
	int curHeight = 0;
	int count = 0;
	cin >> A >> B >> V;

	V -= B;//���� ������ ��츦 ���� �̸� B�� �����´�
	count = V / (A - B);
	if (V % (A - B) > 0)//�� ������ �������� �ʾ��� ��� �Ϸ縦 �� �߰�
		count++;
	cout << count;
}