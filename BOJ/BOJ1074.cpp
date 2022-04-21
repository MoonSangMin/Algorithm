#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int ans = 0;

//행(row)는 y와 관련, 열(column)은 x와 관련
void solution(int y, int x, int size) {
    if(y == r && x == c){
        cout << ans;
        return;
    }

    if(r < y + size && r >= y && c < x + size && c >= x){
        solution(y, x, size / 2);
        solution(y, x + size / 2, size / 2);
        solution(y + size / 2, x, size / 2);
        solution(y + size / 2, x + size / 2, size / 2);
    }
    else ans += size*size;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> r >> c;
    solution(0, 0, pow(2, n));
}