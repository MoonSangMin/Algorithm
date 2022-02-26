#include <iostream>
using namespace std;

int factorial(int n){
    int tmp = 1;
    for(int i=1; i<=n; i++){
        tmp *= i;
    }

    return tmp;
}

int main(){
    int n, k;
    cin >> n >> k;

    int ans = factorial(n) / factorial(n-k);
    ans /= factorial(k);

    cout << ans;
}