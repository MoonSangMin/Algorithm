#include <iostream>
using namespace std;

int main() {
    string a, b, ans = "";
    cin >> a >> b;

    if(a.size() < b.size()){
        while(a.size() != b.size()){
            a = "0" + a;
        }
    }
    else if(a.size() > b.size()){
        while(a.size() != b.size()){
            b = "0" + b;
        }
    }

    int overTen = 0;

    for(int i=a.size()-1; i>=0; i--){
        int tmp = (a[i] - '0') + (b[i] - '0') + overTen;
        if(tmp >= 10){
            tmp -= 10;
            ans = char(tmp + '0') + ans;
            overTen = 1;
        }
        else {
            ans = char(tmp + '0') + ans;
            overTen = 0;
        }
    }

    if(overTen == 1){
        ans = "1" + ans;
    }

    cout << ans;
}