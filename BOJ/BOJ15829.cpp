#include <iostream>
#include <string>
using namespace std;

#define ull unsigned long long

ull pow(int a, int b) {
    ull ret = 1;
    for(int i=0; i<b; i++){
        ret *= a;
        ret %= 1234567891;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    string str;
    cin >> n >> str;

    ull ans = 0;

    for(int i=0; i<n; i++){
        ans += (int(str[i]-'a' + 1) * pow(31, i));
        ans %= 1234567891;
    }

    cout << ans;
}