#include <iostream>
using namespace std;

int n, tmp[10000001];

void Merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	if (i > mid) {//i가 mid보다 더 큰경우는 왼쪽이 다 정렬된 상태
		for (l = j; l <= right; l++)
			tmp[k++] = arr[l];
	}
	else {
		for (l = i; l <= mid; l++)
			tmp[k++] = arr[l];
	}

	for (l = left; l <= right; l++)
		arr[l] = tmp[l];
}

void Divide(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Divide(arr, left, mid);
		Divide(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Divide(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';//endl쓰면 출력이 매우매우 느려짐
	}
	delete[] arr;
}