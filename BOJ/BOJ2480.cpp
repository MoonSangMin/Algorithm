#include <iostream>
#include <map>
using namespace std;

int main(){
    int a, b, c;
    map<int, int> m;
    
    cin >> a >> b >> c;
    m[a]++;
    m[b]++;
    m[c]++;

    if(m.size() == 3){
        auto it = m.end(); --it;
        cout << it->first * 100;
    }
    else if(m.size() == 2){
        for(auto it : m){
            if(it.second == 2){
                cout << 1000 + it.first * 100;
            }
        }
    }
    else {
        auto it = m.begin();
        cout << 10000 + it->first * 1000;
    }
}