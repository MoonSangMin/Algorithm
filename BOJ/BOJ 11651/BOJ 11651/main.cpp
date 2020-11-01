#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> p;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back(make_pair(y, x));
	}

	sort(p.begin(), p.end());
	
	for (int i = 0; i < n; i++) {
		cout << p[i].second << ' ' << p[i].first << '\n';
	}
}

/*
bool comp(pair<int, int> p1, pair<int, int> p2){
	if(p1.second!=p2.second)
		return p1.second<p2.second

	else
		return p1.first<p2.first
}
*/