#include <iostream>
#include <algorithm>
using namespace std;

int DP[50001] = { 0, };

int main(){
    int n;
    cin >> n;
    DP[1] = 1;

    for(int i=2; i<=n; i++){
        int tmp = 1e9;
        for(int j=1; j*j <= i; j++){
            tmp = min(tmp, DP[i - j*j]);
        }
        DP[i] = tmp + 1;
    }

    cout << DP[n];
}