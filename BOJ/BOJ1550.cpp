#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int hexToDec(char a){
    if(a >= '0' && a <= '9') return a - '0';
    else if(a == 'A') return 10;
    else if(a == 'B') return 11;
    else if(a == 'C') return 12;
    else if(a == 'D') return 13;
    else if(a == 'E') return 14;
    else return 15;
}

int main(){
    string input;
    cin >> input;

    int ans = 0;
    int p = input.size() - 1;

    for(int i=0; i<input.size(); i++){
        int tmp = hexToDec(input[i]) * pow(16.0, p);
        ans += tmp;
        p--;
    }

    cout << ans;
}