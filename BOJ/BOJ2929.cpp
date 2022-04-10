#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;

int main(){
    string str;
    int ans = 0;
    cin >> str;

    regex re("[A-Z][a-z]*");
    smatch match;
    vector<string> v;

    while(regex_search(str, match, re)){
        v.push_back(match.str());
        str = match.suffix();
    }

    for(int i=0; i<v.size()-1; i++){
        if(v[i].size() % 4 != 0){
            ans = ans + 4 - (v[i].size() % 4);
        }
    }

    cout << ans;
}