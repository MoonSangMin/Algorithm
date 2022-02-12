#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
bool visited[MAX] = { false, };
int ans[MAX] = {0, };
queue<int> q;
int n, k;

bool isPossible(int val){
    if(val >= 0 && val < MAX) return true;
    else return false;
}

void BFS(int st){
    q.push(st);
    visited[st] = true;
    ans[st] = 0;

    while (!q.empty()){
        int cur = q.front();
        if(cur == k) break;
        q.pop();

        if(isPossible(cur + 1) && !visited[cur + 1]){
            visited[cur + 1] = true;
            q.push(cur + 1);
            ans[cur + 1] = ans[cur] + 1;
        }
        if(isPossible(cur - 1) && !visited[cur - 1]){
            visited[cur - 1] = true;
            q.push(cur - 1);
            ans[cur - 1] = ans[cur] + 1;
        }
        if(isPossible(cur * 2) && !visited[cur * 2]){
            visited[cur * 2] = true;
            q.push(cur * 2);
            ans[cur * 2] = ans[cur] + 1;
        }
    }
}

int main(){
    cin >> n >> k;
    BFS(n);

    cout << ans[k];
}


//현재 위치 n, 도달해야할 위치 k
//가능한 경우 x-1, x+1, 2*x