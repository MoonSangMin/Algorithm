#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		long long x, y;
		long long d, count, max = 0, remain;
		cin >> x >> y;
		d = y - x;

		while(max * max <= d)
			max++;
		
		if(max>1)
			max--;

		remain = d - max * max;


		count = max * 2 - 1;

		while (remain) {
			if (remain > max) {
				remain -= max;
				count++;
			}
			else {
				remain = 0;
				count++;
			}
		}

		cout << count << endl;
	}
}