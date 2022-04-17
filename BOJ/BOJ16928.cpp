#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, ans = 0;
int shortcut[101] = { 0, };
bool visited[101] = { false, };

int main(){
    cin >> n >> m;

    for(int i=0; i<n + m; i++){
        int a, b;
        cin >> a >> b;
        shortcut[a] = b;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();
        visited[cur] = true;
        if(cur == 100) ans = cnt;

        for(int i=1; i<=6; i++){
            int next = cur + i;
            if(next > 100) continue;
            next = shortcut[next] == 0 ? next : shortcut[next];

            if(!visited[next]){
                visited[next] = true;
                q.push(make_pair(next, cnt + 1));
            }
        }
    }
    
    cout << ans;
}