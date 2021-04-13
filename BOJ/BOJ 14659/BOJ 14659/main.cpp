#include <iostream>
#include <algorithm>
using namespace std;

int arr[30001];
int cnt[30001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])
				cnt[i]++;
			else
				break;
		}
	}

	cout << *max_element(cnt + 0, cnt + n);
}