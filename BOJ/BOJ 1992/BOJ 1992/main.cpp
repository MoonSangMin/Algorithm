#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int map[65][65] = { 0, };

void divide_conquer(int xPos, int yPos, int size) {
	int check = 0;
	for (int i = xPos; i < xPos + size; i++) {
		for (int j = yPos; j < yPos + size; j++) {
			if (map[i][j])
				check++;
		}
	}

	if (!check) {
		cout << 0;
	}
	else if (check == (size * size)) {
		cout << 1;
	}
	else {
		cout << "(";
		divide_conquer(xPos, yPos, size / 2);
		divide_conquer(xPos, yPos + size / 2, size / 2);
		divide_conquer(xPos + size / 2, yPos, size / 2);
		divide_conquer(xPos + size / 2, yPos + size / 2, size / 2);
		cout << ")";
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	divide_conquer(1, 1, n);
}