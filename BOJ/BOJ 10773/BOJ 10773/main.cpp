#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> st;
	int n;
	int val, ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		if (val == 0) {
			st.pop();
		}
		else {
			st.push(val);
		}
	}

	while (st.size() > 0) {
		ans = ans + st.top();
		st.pop();
	}

	cout << ans;
}