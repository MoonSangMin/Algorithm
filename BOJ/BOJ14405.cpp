#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    string str;
    int sizeOfStr = 0;
    cin >> str;

    regex re1("pi");
    regex re2("ka");
    regex re3("chu");

    smatch match;

    string tmp = str;
    while(regex_search(tmp, match, re1)){
        sizeOfStr += 2;
        tmp = match.suffix();
    }

    tmp = str;
    while(regex_search(tmp, match, re2)){
        sizeOfStr += 2;
        tmp = match.suffix();
    }

    tmp = str;
    while(regex_search(tmp, match, re3)){
        sizeOfStr += 3;
        tmp = match.suffix();
    }

    sizeOfStr == str.size() ? cout << "YES" : cout << "NO";
}