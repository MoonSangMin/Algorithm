#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int arr[10];
    int total = 0;
    int ans = 0;

    for(int i=0; i<10; i++){
        cin >> arr[i];
    }

    for(int i=0; i<10; i++){
        total += arr[i];
        if(abs(100 - total) <= abs(100 - ans)){
            ans = total;
        }
    }

    cout << ans;
}