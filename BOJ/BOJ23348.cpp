#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n;
    int scores[3];

    for(int i=0; i<3; i++){
        cin >> scores[i];
    }

    cin >> n;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<3; j++){
            int a, b, c;
            cin >> a >> b >> c;
            sum = sum + a * scores[0] + b * scores[1] + c * scores[2];
        }
        v.push_back(sum);
    }

    cout << *max_element(v.begin(), v.end());
}