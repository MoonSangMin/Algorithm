#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;


int main(){
    unordered_map<string, pair<int, long long> > colors;
    colors["black"] = make_pair(0, 1);
    colors["brown"] = make_pair(1, 10);
    colors["red"] = make_pair(2, 100);
    colors["orange"] = make_pair(3, 1000);
    colors["yellow"] = make_pair(4, 10000);
    colors["green"] = make_pair(5, 100000);
    colors["blue"] = make_pair(6, 1000000);
    colors["violet"] = make_pair(7, 10000000);
    colors["grey"] = make_pair(8, 100000000);
    colors["white"] = make_pair(9, 1000000000);

    string a, b, c;
    cin >> a >> b >> c;

    long long ans = 10 * colors[a].first + colors[b].first;
    cout << ans * colors[c].second; 
}