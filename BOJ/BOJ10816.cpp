#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    vector<int> v;

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        
        int cnt = upper_bound(v.begin(), v.end(), tmp) - lower_bound(v.begin(), v.end(), tmp);
        cout << cnt << ' ';
    }
}