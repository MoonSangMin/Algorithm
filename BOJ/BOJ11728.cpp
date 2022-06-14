#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    vector<int> v1, v2;

    cin >> n >> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }

    int p1 = 0, p2 = 0;
    
    while(p1 < v1.size() && p2 < v2.size()){
        if(v1[p1] <= v2[p2]) {
            cout << v1[p1++] << ' ';
        }
        else {
            cout << v2[p2++] << ' ';
        }
    }

    while(p1 < v1.size()){
        cout << v1[p1++] << ' ';
    }
    while(p2 < v2.size()){
        cout << v2[p2++] << ' ';
    }
}