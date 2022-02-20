#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        string s;
        getline(cin, s);

        int st = 0, en = s.size() - 1;
        while(st < en) {
            char tmp = s[st];
            s[st] = s[en];
            s[en] = tmp;

            st++;
            en--;
        }

        cout << s << '\n';
    }
}