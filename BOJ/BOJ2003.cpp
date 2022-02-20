#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m;
    vector<int> v;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int st = 0, en = 0, sum = v[0], cnt = 0;

    while(st <= en && en < n){
        if(sum < m){
            sum += v[++en];
        }
        else if(sum == m){
            cnt++;
            sum += v[++en];
        }
        else { //sum이 m보다 클 때
            sum -= v[st++];

            if(st > en){
                en = st;
                sum = v[st];
            }
        }
    }

    cout << cnt;
}