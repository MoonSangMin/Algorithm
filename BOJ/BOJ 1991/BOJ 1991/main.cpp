#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char, char> pcc;

int main() {
	vector<pcc> trees;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		char l, r;
		cin >> l >> r;
		trees.push_back(make_pair(l, r));
	}
}