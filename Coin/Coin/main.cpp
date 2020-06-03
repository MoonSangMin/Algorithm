#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int DP[100001];

vector<int> Split(string str, char delimiter) {
	int i = 0;
	vector<int> nums;
	stringstream ss(str);
	string tmp;

	while (getline(ss, tmp, delimiter)) {
		nums.push_back(stoi(tmp));
	}

	return nums;
}

int main() {
	int money = 0, i, j;//거슬러 주어야 하는 액수
	DP[0] = 0;
	string coins;
	vector<int> coin;//각 동전들의 액면
	
	getline(cin, coins);
	coin = Split(coins, ',');
	cin >> money;
	for (i = 1; i <= money; i++) {
		DP[i] = 10000;
	}

	sort(coin.begin(), coin.end());

	for (j = 1; j <= money; j++) {
		for (i = 0; i < coin.size(); i++) {
			if (coin[i] <= j && ((DP[j - coin[i]] + 1) < DP[j]))
				DP[j] = DP[j - coin[i]] + 1;
		}
	}

	cout << DP[money];
}