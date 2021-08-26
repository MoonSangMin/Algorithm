#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[51];

string whiteFirst[8] = 
{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string blackFirst[8] = 
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int WhiteCount(int x, int y){
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[x+i][y+j] != whiteFirst[i][j]) cnt++;
        }
    }

    return cnt;
}

int BlackCount(int x, int y){
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[x+i][y+j] != blackFirst[i][j]) cnt++;
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    int ans = 9999;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i+8 <= n; i++){
        for(int j=0; j+8 <= m; j++){
            int cnt;

            cnt = min(WhiteCount(i, j), BlackCount(i, j));
            if(cnt <= ans){
                ans = cnt;
            }
        }
    }

    cout << ans;
}