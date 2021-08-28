#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int i = 1, cnt = 0;

    while(n >= 0){
        n -= i;
        i++;
        cnt++;
    }

    cout << cnt - 1;
}

//55라면 1+2+3+4+5+6+7+8+9+10
//10이라면 1+2+3+4