#include <iostream>
#include <queue>
using namespace std;

int n, m; //n 세로 m 가로
int map[1001][1001];
int ans[1001][1001];
bool visited[1001][1001] = { false, };
queue<pair<int, int> > q;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool isInside(int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n) return false;
    else return true;
}

int main(){
    cin >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];

            if(map[i][j] == 1){
                q.push(make_pair(i, j));
            }
        }
    }

    if(q.empty()){
        cout << -1;
        return 0;
    }

    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isInside(nx, ny) && map[ny][nx] == 0 && !visited[ny][nx]){
                q.push(make_pair(ny, nx));
                ans[ny][nx] = ans[y][x] + 1;
                visited[ny][nx] = true;
            }
        }
    }

    int answer = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && ans[i][j] == 0){
                cout << -1;
                return 0;
            }

            if(ans[i][j] > answer){
                answer = ans[i][j];
            }
        }
    }

    cout << answer;
}