#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, b;
    int maxHeight = -1, minHeight = 300;
    int ansHeight = -1, ansTime = 1e9;
    cin >> n >> m >> b;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(maxHeight < arr[i][j]) maxHeight = arr[i][j];
            if(minHeight > arr[i][j]) minHeight = arr[i][j];
        }
    }

    for(int k=maxHeight; k>=minHeight; k--){
        int numOfBlock = b;
        int tmpTime = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] != k){
                    int dif = abs(arr[i][j] - k);
                    if(arr[i][j] < k){
                        numOfBlock -= dif;
                        tmpTime += dif;
                    } 
                    else {
                        tmpTime += (2 * dif);
                        numOfBlock += dif;
                    }
                }
            }
        }

        if(numOfBlock < 0) continue;

        if(ansTime > tmpTime){
            ansTime = tmpTime;
            ansHeight = k;
        }
        else if(ansTime == tmpTime){
            ansHeight = max(ansHeight, k);
        }
    }

    cout << ansTime << ' ' << ansHeight;
}