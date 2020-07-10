#include <iostream>
using namespace std;

int map[129][129] = { 0, };
int white = 0, blue = 0;

void divide_conquer(int xPos, int yPos, int size) {
	int check = 0;
	for (int i = xPos; i < xPos + size; i++) {
		for (int j = yPos; j < yPos + size; j++) {
			if (map[i][j])
				check++;
		}
	}

	if (!check)white++;
	else if (check == (size * size))blue++;
	else {
		divide_conquer(xPos, yPos, size / 2);
		divide_conquer(xPos, yPos + size / 2, size / 2);
		divide_conquer(xPos + size / 2, yPos, size / 2);
		divide_conquer(xPos + size / 2, yPos + size / 2, size / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	divide_conquer(1, 1, n);
	cout << white << '\n' << blue;
}