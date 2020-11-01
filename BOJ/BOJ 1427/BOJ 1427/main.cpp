#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a, int b) { return a > b; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long int N;
	vector<int> arr;
	cin >> N;

	while (N != 0) {
		arr.push_back(N % 10);
		N /= 10;
	}
	sort(arr.begin(), arr.end(), desc);

	for (int j = 0; j < arr.size(); j++) {
		cout << arr[j];
	}
}