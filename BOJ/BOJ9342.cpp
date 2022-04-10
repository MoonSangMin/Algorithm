#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    regex re("^[A-F]?A+F+C+[A-F]?");

    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        if(regex_match(str, re)){
            cout << "Infected!\n";
        }
        else {
            cout << "Good\n";
        }
    }
}