#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    string fullname, ans = "";
    cin >> fullname;

    string tmp;
    istringstream iss(fullname);
    vector<string> v;

    while(getline(iss, tmp, '-')){
        v.push_back(tmp);
    }

    for(int i=0; i<v.size(); i++){
        ans += v[i][0];
    }

    cout << ans;
}