#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; //포켓몬의 개수 n, 맞춰야할 문제 수 m
    cin >> n >> m;

    unordered_map<int, string> numberFirst;
    unordered_map<string, int> nameFirst;

    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;

        numberFirst[i+1] = tmp;
        nameFirst[tmp] = i+1;
    }

    for(int i=0; i<m; i++){
        string tmp;
        cin >> tmp;
        if(atoi(tmp.c_str()) == 0){ //문자열일 경우
            cout << nameFirst[tmp] << '\n';
        }
        else { //숫자일 경우
            cout << numberFirst[stoi(tmp)] << '\n';
        }
    }
}