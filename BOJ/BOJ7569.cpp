#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, h; //n 세로 m 가로 h 높이
int map[101][101][101];
int ans[101][101][101];
bool visited[101][101][101] = { false, };
queue<pair<pair<int, int>, int>  > q;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool isInside(int z, int x, int y){
    if(x < 0 || y < 0 || z < 0 || x >= n || y >= m || z >= h) return false;
    else return true;
}

int main(){
    cin >> m >> n >> h;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> map[i][j][k];

                if(map[i][j][k] == 1){
                    q.push(make_pair(make_pair(i, j), k));
                }
            }
        }
    }

    if(q.empty()){
        cout << -1;
        return 0;
    }

    while(!q.empty()){
        int x = q.front().first.second;
        int y = q.front().second;
        int z = q.front().first.first;
        q.pop();

        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(isInside(nz, nx, ny) && map[nz][nx][ny] == 0 && !visited[nz][nx][ny]){
                q.push(make_pair(make_pair(nz, nx), ny));
                ans[nz][nx][ny] = ans[z][x][y] + 1;
                visited[nz][nx][ny] = true;
            }
        }
    }

    int answer = -1;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(map[i][j][k] == 0 && ans[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }

                if(ans[i][j][k] > answer){
                    answer = ans[i][j][k];
                }
            }
        }
    }

    cout << answer;
}