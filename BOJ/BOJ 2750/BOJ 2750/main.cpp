#include <iostream>
using namespace std;

void InsertionSort(int *arr, int n) {
	int key, i, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (key < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = key;//종료된 시점에 --가 넘어오기 때문
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	InsertionSort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}