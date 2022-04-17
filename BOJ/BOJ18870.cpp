#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    map<int, int> m;
    vector<int> v;
    vector<int> ans;
    int n;
    
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    ans = v;
    sort(v.begin(), v.end());

    m.insert(make_pair(v[0], 0));
    int cnt = 1, prior = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i] == prior) continue;
        else {
            m.insert(make_pair(v[i], cnt++));
            prior = v[i];
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout << m[ans[i]] << ' ';
    }
}