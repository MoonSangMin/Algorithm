#include <iostream>
using namespace std;

bool isTripleSix(int num){
    int cnt = 0;
    bool cont = false;

    while(num > 0){
        if(cnt == 3) return true;
        int tmp;
        tmp = num % 10;

        if(tmp == 6) cont = true;
        else cont = false;

        if(tmp == 6 && cont){
            cnt++;
        }
        else cnt = 0;
        num /= 10;
    }
    if(cnt == 3) return true;
    else return false;
}

int main(){
    int n, i=665;
    int cnt = 0;
    cin >> n;

    while(true){
        if(isTripleSix(i)) cnt++;

        if(cnt == n){
            cout << i;
            break;
        }
        i++;
    }
}