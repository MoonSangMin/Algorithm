#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][3];

int main(){
	int n, i;
	cin >> n;

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;

	for (i = 1; i <= n; i++) {
		int R, G, B;
		cin >> R >> G >> B;

		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + R;
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + G;
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + B;
	}

	cout << min(min(house[n][0], house[n][1]), house[n][2]) << '\n';
}