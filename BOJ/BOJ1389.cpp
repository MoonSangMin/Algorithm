#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int arr[101][101] = { 0, };
bool visited[101] = { false, };
int sum[101] = { 0, };
int ans[101] = { 1, };

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i=1; i<=n; i++){
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int j=1; j<=n; j++){
                if(arr[cur][j] == 1 && !visited[j]){
                    q.push(j);
                    visited[j] = true;
                    sum[j] = sum[cur] + 1;
                }
            }
        }


        for(int j=1; j<=n; j++){
            ans[i] += sum[j];
        }
        memset(visited, false, sizeof(visited));
        memset(sum, 0, sizeof(sum));
    }

    int minVal = 2e9, answer;
    for(int i=1; i<=n; i++){
        if(minVal > ans[i]){
            minVal = ans[i];
            answer = i;
        }
    }

    cout << answer;
}