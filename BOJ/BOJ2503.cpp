#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> candidate;

pair<int, int> compareString(string a, string b){
    int strike = 0, ball = 0;

    for(int i=0; i<3; i++){
        if(a[i] == b[i]) strike++;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j) continue;

            if(a[i] == b[j]) ball++;
        }
    }

    return make_pair(strike, ball);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=123; i<1000; i++){
        string tmp = to_string(i);
        char a = tmp[0];
        char b = tmp[1];
        char c = tmp[2];
        
        if(a == b || b == c || a == c || b == '0' || c == '0') continue;

        candidate.push_back(tmp);
    }

    for(int i=0; i<n; i++){
        string num;
        int strike, ball;
        cin >> num >> strike >> ball;

        pair<int, int> tmp = make_pair(strike, ball);
        
        for(int j=0; j<candidate.size(); ){
            if(tmp == compareString(num, candidate[j])) j++;
            else {
                candidate.erase(candidate.begin() + j);
            }
        }
    }

    cout << candidate.size();
}