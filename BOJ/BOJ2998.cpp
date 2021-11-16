#include <iostream>
using namespace std;

char bin_to_oct(string oct){
    if(oct == "000") return '0';
    else if(oct == "001") return '1';
    else if(oct == "010") return '2';
    else if(oct == "011") return '3';
    else if(oct == "100") return '4';
    else if(oct == "101") return '5';
    else if(oct == "110") return '6';
    else return '7';
}

int main(){
    string bin, ans = "";
    cin >> bin;

    if(bin.size() % 3 != 0){
        int tmp = 3 - bin.size() % 3;
        for(int i=0; i<tmp; i++){
            bin = "0" + bin;
        }
    }

    for(int i=0; i<bin.size() / 3; i++){
        string tmp = "";
        tmp += bin[i*3];
        tmp += bin[i*3 + 1];
        tmp += bin[i*3 + 2];
        
        ans += bin_to_oct(tmp);
    }
    
    cout << ans;
}