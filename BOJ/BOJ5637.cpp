#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int maxLen = -1;
    string ans;
    
    while(true){
        string tmp;
        int len = 0;

        cin >> tmp;
        if(tmp == "E-N-D") break;

        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

        string word = "";
        for(int i=0; i<tmp.size(); i++){
            if((tmp[i] >= 'a' && tmp[i] <= 'z') || tmp[i] == '-'){
                word += tmp[i];
            }
            else {
                len = max(len, (int)word.size());
                if(len > maxLen){
                    ans = word;
                    maxLen = len;
                }
                word = "";
            }
        }

        len = max(len, (int)word.size());
        if(len > maxLen){
            ans = word;
            maxLen = len;
        }
    }

    cout << ans;
}