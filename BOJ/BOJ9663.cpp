#include <iostream>
#include <cmath>
using namespace std;

int n, ans = 0;
int col[16];

bool check(int level){
    for(int i=0; i<level; i++){
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i) return false;
    }

    return true;
}

void DFS(int x){
    if(x == n){
        ans++;
        return;
    }

    for(int i=0; i<n; i++){
        col[x] = i;
        if(check(x)) DFS(x+1);
    }
}

int main(){
    cin >> n;
    DFS(0);
    cout << ans;
}

//어짜피 같은 행에는 퀸을 둘 수 없으므로 열들만 확인하면 된다.
//col 배열을 선언하고 각 col의 값에는 몇 번째 행에 퀸이 있는지 저장한다.
//즉, col[0] = 3은 0번째 열, 3번째 행에 퀸을 놓는다는 의미이다.

//같은 열에 존재하거나, 기울기가 같다면(대각선에 있다면) 퀸을 둘 수 없다.
//이를 check 함수로 선언해두고
//모든 열을 체크하며 둘 수 있다면 해당 위치에서 DFS를 수행해나간다.
//만약 마지막 열에 도달했다면 퀸을 배치할 수 있으므로 정답 카운트를 늘려준다.