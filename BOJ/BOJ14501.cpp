#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int DP[16];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int> > v(n + 1);
    v[0].first = 0; v[0].second = 0;

    for(int i=1; i<=n; i++){
        int day, cost;
        cin >> day >> cost;
        v[i].first = day;
        v[i].second = cost;
    }

    DP[0] = 0;
    for(int i=1; i<=n+1; i++){
        for(int j=1; j<=i; j++){
            if(i - j >= v[j].first) {
                DP[i] = max(v[j].second + DP[j], DP[i]);
            }
        }
    }

    cout << DP[n+1];
}