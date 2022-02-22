#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int cnt = 0;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        s[i] = toupper(s[i]);
        if(i % 3 == 0){
            if(s[i] != 'P') cnt++;
        }
        else if(i % 3 == 1){
            if(s[i] != 'E') cnt++;
        }
        else{
            if(s[i] != 'R') cnt++;
        }
    }

    cout << cnt;
}