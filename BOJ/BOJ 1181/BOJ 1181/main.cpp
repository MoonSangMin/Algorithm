#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
vector<string>::iterator it;
vector<string>::iterator end_it;

bool comp(string s1, string s2) {
	if (s1.size() != s2.size())
		return s1.size() < s2.size();
	else
		return s1 < s2;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), comp);
	end_it = unique(v.begin(), v.end());
	//unique함수는 중복된 원소들을 뒤로 보내버린다

	for (it = v.begin(); it != end_it; it++) {
		cout << *it << '\n';
	}
}