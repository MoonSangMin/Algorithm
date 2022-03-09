#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> v;
    int n;
    string pattern;

    cin >> n;

    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    pattern = v[0];
    for(int i=1; i<v.size(); i++){
        for(int j=0; j<pattern.size(); j++){
            if(pattern[j] != v[i][j]) pattern[j] = '?';
        }
    }

    cout << pattern;
}