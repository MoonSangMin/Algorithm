#include <iostream>
using namespace std;

int arr[101][101];
bool visited[101][101];
int n, ans, tmp = 0, h = -2147483648;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1}; //오, 아, 왼, 위 순서

bool isInside(int y, int x){
    if(x < 0 || y < 0 || x >= n || y >= n) return false;
    else return true;
}

void DFS(int y, int x, int k) {
    visited[y][x] = true;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(isInside(ny, nx) && arr[ny][nx] > k && !visited[ny][nx]){
            visited[ny][nx] = true;
            DFS(ny, nx, k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(h < arr[i][j]) h = arr[i][j];
        }
    }

    for(int k=0; k<=h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] > k && !visited[i][j]){
                    tmp++;
                    DFS(i, j, k);
                }
            }
        }

        for(int i=0; i<n; i++){
            memset(visited[i], false, sizeof(bool) * n);
        }
        ans = max(ans, tmp);
        tmp = 0;
    }

    cout << ans;
}