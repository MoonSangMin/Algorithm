#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        unordered_map<string, int> m;

        for(int i=0; i<n; i++){
            string trash, str;
            cin >> trash >> str;

            m[str] += 1;
        }

        int ans = 1;
        for(auto i : m){
            ans *= (i.second + 1);
        }
        cout << ans - 1 << '\n';
    }
}