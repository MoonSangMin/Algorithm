#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int arr[5];

    for(int i=0; i<5; i++){
        cin >> arr[i];
    }

    sort(arr, arr + 5);

    for(int i=arr[2]; ;i++){
        int cnt = 0;
        
        if(i % arr[0] == 0) cnt++;
        if(i % arr[1] == 0) cnt++;
        if(i % arr[2] == 0) cnt++;
        if(i % arr[3] == 0) cnt++;
        if(i % arr[4] == 0) cnt++;

        if(cnt >= 3){
            cout << i;
            return 0;
        }
    }
}