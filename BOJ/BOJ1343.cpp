#include <iostream>
#include <string>
#include <regex>
using namespace std;

string convert(string str){
    string ret = "";

    if(str.size() == 0) return "";
    else if(str.size() % 4 == 0){
        int n = str.size() / 4;
        while(n > 0){
            ret += "AAAA";
            n--;
        }
        return ret;
    }
    else if(str.size() > 4){
        int n = str.size() / 4;
        while(n > 0){
            ret += "AAAA";
            n--;
        }
        ret += "BB";
        return ret;
    }
    else return "BB";
}

int main(){
    string str;
    cin >> str;

    string tmp = "", ans = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'X') tmp += "X";
        else {
            if(tmp.size() % 2 != 0){
                cout << -1;
                return 0;
            }
            else if(tmp.size() == 0) ans += ".";
            else{
                ans += convert(tmp);
                ans += ".";
                tmp = "";
            }
        }
    }

    if(tmp.size() != 0){
        if(tmp.size() % 2 != 0){
            cout << -1;
            return 0;
        }
        else ans += convert(tmp);
    }

    cout << ans;
}