#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

int main(){
    int n, ans = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int m, sub;
    cin >> m >> sub;

    for(int i=0; i<v.size(); i++){
        ans++;
        v[i] -= m;
    }

    for(int i=0; i<v.size(); i++){
        if(v[i] > 0){
            ans += ceil(v[i] / (double)sub);
        }
    }

    cout << ans;
}