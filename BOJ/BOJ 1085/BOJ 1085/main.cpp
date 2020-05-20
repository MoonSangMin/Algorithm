#include <iostream>
using namespace std;

int main() {
	int x, y;
	int w, z;
	int xClosest, yClosest, ans;

	cin >> x >> y >> w >> z;

	xClosest = ((w - x) > x) ? x : w - x;
	yClosest = ((z - y) > y) ? y : z - y;

	if (xClosest > yClosest)
		ans = yClosest;
	else
		ans = xClosest;

	cout << ans;
}