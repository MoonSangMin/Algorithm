#include <iostream>
#include <algorithm>
using namespace std;

int d[101][101] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int num;
	int* tmp;

	cin >> num;
	tmp = new int[num];

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin>>tmp[j];
			d[i][j] = tmp[j];
		}
	}
	delete[] tmp;

	for (int k = 0; k < num; k++) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
					d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
				}
			}
		}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
}