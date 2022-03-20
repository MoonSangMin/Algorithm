#include <iostream>
#include <queue>
using namespace std;

#define INF 2147483647

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};//우 하 상 좌 순서

int arr[126][126];
int dist[126][126];
int cnt = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true){
        int n;
        cin >> n;
        if(n == 0) return 0;
        else {
           for(int i=0; i<n; i++){
               for(int j=0; j<n; j++){
                   int tmp;
                   cin >> tmp;
                   arr[i][j] = tmp;
                   dist[i][j] = INF;
               }
           }

            queue<pair<int, int> > q; //first는 y좌표(행), second는 x좌표(열)
            q.push(make_pair(0, 0));
            dist[0][0] = arr[0][0];
            
            while(!q.empty()){
                pair<int, int> cur = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int ny = cur.first + dy[i];
                    int nx = cur.second + dx[i];

                    if(ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
                    
                    if(dist[ny][nx] > dist[cur.first][cur.second] + arr[ny][nx]){
                        dist[ny][nx] = dist[cur.first][cur.second] + arr[ny][nx];
                        q.push(make_pair(ny, nx));
                    }
                }
            }

            cout << "Problem " << cnt++ << ": " << dist[n-1][n-1] << '\n';
            for(int i=0; i<n; i++){
                memset(arr[i], 0, sizeof(int) * n);
                memset(dist[i], 0, sizeof(int) * n);
            }
        }
    }
}