#include <iostream>
using namespace std;

int main() {
	int T;
	int H, W; //H�� ����, W�� �� �� ���� ����
	int visitorNum;
	int count = 1;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> visitorNum;

		for (int j = 1; j <= W; j++) {
			for (int k = 1; k <= H; k++) {
				if (visitorNum == count) {
					if (j < 10)
						cout << k << 0 << j << endl;
					else
						cout << k << j << endl;
				}
				count++;
			}//���� ��
		}//���� ��
		
		count = 1;
	}
}