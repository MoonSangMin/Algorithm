#include <iostream>
using namespace std;

int main(){
    int n, cnt = 1;
    char arr[51];
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; ){
        if(arr[i] == 'S'){
            cnt++;
            i++;
        }
        else{
            cnt++;
            i+=2;
        }
    }
    if(n < cnt){
        cout << n;
    }else{
        cout << cnt;
    }
}

// *S*S*S*
// *S*LL*S*
// *S*LL*LL*S*
// *LL*LL*LL*S*