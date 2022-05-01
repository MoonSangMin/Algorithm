#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a, b, c, d;
    while(true){
        cin >> a >> b >> c >> d;
        if(a == 0 && b == 0 && c == 0 && d == 0) break;

        int maxVal = a;
        if(maxVal < b) maxVal = b;
        if(maxVal < c) maxVal = c;
        if(maxVal < d) maxVal = d;

        int n;
        for(int i=0; i<32; i++){
            if(maxVal <= pow(2, i)){
                n = i;
                break;
            }
        }

        int ans = 0;
        for(int i=1; i<=3*n; i++){
            long long na = llabs(a-b);
            long long nb = llabs(b-c);
            long long nc = llabs(c-d);
            long long nd = llabs(d-a);

            if(na == 0 && nb == 0 && nc == 0 && nd == 0){
                ans = i - 1;
                break;
            }
            a = na; b = nb; c = nc; d = nd;
        }

        cout << ans << '\n';
    }
}