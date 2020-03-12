#include <iostream>
using namespace std;

int main() {
	int T;
	int H, W; //H朝 類熱, W朝 類 滌 寞曖 偃熱
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
			}//類熱 部
		}//棻擠 翮
		
		count = 1;
	}
}