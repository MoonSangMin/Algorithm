#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<long, long> a, pair<long, long> b){
    if(a.second < b.second) return true;
    else if(a.second == b.second){
        return a.first < b.first;
    }
    else {
        return false;
    }
}

int main(){
    vector<pair<long long, long long> > cons; //conferences
    vector<pair<long long, long long> > available;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        long long st, en;
        cin >> st >> en;
        cons.push_back(make_pair(st, en));
    }

    sort(cons.begin(), cons.end(), comp); //작업이 빨리 끝나는 순으로 정렬

    available.push_back(make_pair(cons[0].first, cons[0].second));
    long long minVal = cons[0].second;

    for(int i=1; i<n; i++){
        if(cons[i].first >= minVal){
            available.push_back(make_pair(cons[i].first, cons[i].second));
            minVal = cons[i].second;
        }
    }

    cout << available.size();
}