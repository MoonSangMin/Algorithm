#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    map<string, string> sites;
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string site, password;
        cin >> site >> password;

        sites[site] = password;
    }

    for(int i=0; i<m; i++){
        string site;
        cin >> site;
        cout << sites[site] << '\n';
    }
}