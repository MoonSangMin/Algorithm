#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;

    for(int i=0; i<str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = toupper(str[i]);
        }
        else {
            str[i] = tolower(str[i]);
        }
    }

    cout << str;
}