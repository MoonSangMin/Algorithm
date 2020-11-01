#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<int, pair<int, int>> tree;//first is left child, second is r.c
int P, NS, T; //place, number of street(crossroad), treasure
bool ans[5001] = { 0, };
int cnt = 0;
bool flag = false;

void preorder(int node) {//전위순회
	if (node == T) {
		ans[node] = true;
		flag = true;
		return;
	}
	if (tree[node].first != 0) { //왼쪽 자식이 있다면
		ans[node] = true;
		if (flag == true)
			return;
		preorder(tree[node].first);
	}
	if (tree[node].second != 0) { //오른쪽 자식이 있다면
		ans[node] = true;
		if (flag == true)
			return;
		preorder(tree[node].second);
	}
	if (tree[node].first == 0 && tree[node].second == 0 && node != T) {
		ans[node] = false;
	}
	if (ans[tree[node].first] == false && ans[tree[node].second] == false
		&& ans[node] == true) {
		ans[node] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> P >> NS >> T;
	for (int i = 0; i < NS; i++) {
		int rootnode, tmp1, tmp2;
		cin >> rootnode >> tmp1 >> tmp2;
		tree.emplace(rootnode, make_pair(tmp1, tmp2));
	}

	preorder(1);
	
	for (int i = 0; i < 5001; i++) {
		if (ans[i] == true)cnt++;
	}
	cout << cnt << '\n';
	for (int i = 0; i < 5001; i++) {
		if (ans[i] == true) {
			cout << i << '\n';
		}
	}
}