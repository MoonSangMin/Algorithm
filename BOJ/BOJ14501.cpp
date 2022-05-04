#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int DP[16] = { 0, };
pair<int, int> v[16] = { {0, 0}, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int day, cost;
        cin >> day >> cost;
        v[i].first = day;
        v[i].second = cost;
    }

    for(int i=n; i>0; i--){
        if(i + v[i].first > n+1) DP[i] = DP[i+1];
        else DP[i] = max(DP[i+1], DP[i + v[i].first] + v[i].second);

        cout << DP[i] << '\n';
    }

    cout << DP[1];
}