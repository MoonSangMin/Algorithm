#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
	int x, y, r;
	int cnt = 0;
}circles;

circles c[501];

double len(circles a, circles b) {
	return sqrt((abs(a.x - b.x) * abs(a.x - b.x)) + (abs(a.y - b.y) * (abs(a.y - b.y))));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c[i].x >> c[i].y >> c[i].r;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			else {
				double cmp;
				cmp = len(c[i], c[j]);
				if (c[i].r + c[j].r >= cmp) {
					c[i].cnt++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << c[i].cnt << '\n';
	}
}