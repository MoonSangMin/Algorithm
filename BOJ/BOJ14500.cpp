#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
bool visited[501][501];
int dy[4] = { 1, 0, -1, 0};
int dx[4] = { 0, 1, 0, -1};
int n, m, answer = 0;

bool isInside(int y, int x){
    if(y >= 0 && x >= 0 && x < m && y < n) return true;
    else return false;
}

void DFS(int y, int x, int sum, int depth){
    if(depth == 3){
        answer = max(sum, answer);
        return;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(!visited[ny][nx] && isInside(ny, nx)){
            visited[ny][nx] = true;
            DFS(ny, nx, sum + arr[ny][nx], depth + 1);
            visited[ny][nx] = false;
        }
    }
}

void block1(int y, int x){
    int sum = arr[y][x];
    sum += arr[y+1][x];
    sum += arr[y+2][x];
    sum += arr[y+1][x+1];

    answer = max(sum, answer);
}

void block2(int y, int x){
    int sum = arr[y][x];
    sum += arr[y+1][x];
    sum += arr[y+2][x];
    sum += arr[y+1][x-1];

    answer = max(sum, answer);
}

void block3(int y, int x){
    int sum = arr[y][x];
    sum += arr[y][x+1];
    sum += arr[y][x+2];
    sum += arr[y+1][x+1];

    answer = max(sum, answer);
}

void block4(int y, int x){
    int sum = arr[y][x];
    sum += arr[y][x+1];
    sum += arr[y][x+2];
    sum += arr[y-1][x+1];

    answer = max(sum, answer);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                DFS(i, j, arr[i][j], 0);
                visited[i][j] = false;
            }

            if(i + 2 < n && j + 1 < m) block1(i, j);
            if(i + 2 < n && j - 1 >= 0) block2(i, j);
            if(i + 1 < n && j + 2 < m) block3(i, j);
            if(i - 1 >= 0 && j + 2 < m) block4(i, j);
        }
    }

    cout << answer;
}