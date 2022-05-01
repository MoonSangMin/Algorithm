#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        string str;
        cin >> str;

        string a = "", b = "";
        for(int i=0; i<str.size(); i++){
            if(i % 2 == 0) a += str[i];
            else b += str[i];
        }
        
        if(str.size() % 2 != 0){
            string tmp = b;
            b += a;
            a += tmp;
        }

        cout << a << '\n' << b << '\n';
    }
}