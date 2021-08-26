//9개의 수가 있다. 합이 100이 되도록 7개를 뽑아라. 중복 답 X
//9C7은 9C2이므로 2명을 빼는게 빠를 거라 판단.

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[9];
    int i, j;
    int total = 0;
    bool flag = false;

    for(i=0; i<9; i++){
        cin >> arr[i];
        total += arr[i];
    }

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            int tmp = total;
            if(i==j) continue;
            else{
                tmp = tmp - arr[i] - arr[j];
                if(tmp == 100){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;
    }

    for(int k=0; k<9; k++){
        if(k == i || k == j) continue;
        cout << arr[k] << '\n';
    }
}