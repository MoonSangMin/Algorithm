#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k;
    vector<int> v;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int sum = 0;

    for(int i=0; i<k; i++){
        sum += v[i];
    }
    
    int ans = sum;

    for(int i=0; i<n-k; i++){
        sum -= v[i];
        sum += v[i + k];

        ans = max(ans, sum);
    }

    cout << ans;
}