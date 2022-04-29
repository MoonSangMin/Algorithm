#include <iostream>
#include <string>
using namespace std;

string octToBin(char c){
    if(c == '0') return "000";
    else if(c == '1') return "001";
    else if(c == '2') return "010";
    else if(c == '3') return "011";
    else if(c == '4') return "100";
    else if(c == '5') return "101";
    else if(c == '6') return "110";
    else return "111";
}

int main(){
    string oct, ans = "";
    cin >> oct;

    if(oct == "0"){
        cout << oct;
        return 0;
    }

    for(int i=0; i<oct.size(); i++){
        ans += octToBin(oct[i]);
    }

    while(true){
        if(ans[0] == '1') break;
        else ans = ans.substr(1);
    }

    cout << ans;
}