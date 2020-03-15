#include <iostream>
using namespace std;

int main() {
	int V, A, B;
	int curHeight = 0;
	int count = 0;
	cin >> A >> B >> V;

	V -= B;//정상에 도달할 경우를 위해 미리 B를 빼놓는다
	count = V / (A - B);
	if (V % (A - B) > 0)//딱 나누어 떨어지지 않았을 경우 하루를 더 추가
		count++;
	cout << count;
}