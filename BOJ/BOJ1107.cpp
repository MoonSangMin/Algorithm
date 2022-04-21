#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool buttons[10] = { true, true, true, true, true, true, true, true, true, true };

bool check(int num){
    string strNum = to_string(num);

    for(int i=0; i<strNum.size(); i++){
        if(buttons[strNum[i] - '0'] == false) return false;
    }

    return true;
}

int main(){
    int target, n, ans = 0;

    cin >> target >> n;
    if(target == 100){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        buttons[tmp] = false;
    }

    ans = abs(target - 100);

    for(int i=0; i<=1000000; i++){
        if(check(i)){
            int tmp = abs(target - i) + to_string(i).size();
            ans = min(ans, tmp);
        }
    }

    cout << ans;
}