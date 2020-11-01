#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<int> st;
	stack<int> comp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		st.push(tmp);
	}
	
	while (!st.empty()) {
		cout << st.top()<<' ';
		st.pop();
	}
}