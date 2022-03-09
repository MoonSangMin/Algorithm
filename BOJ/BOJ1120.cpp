#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int diffCharCount(string a, string b) {
    int ret = 0;

    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) ret++;
    }

    return ret;
}


int main() {
    string a, b;
    cin >> a >> b;

    int diffSize = b.size() - a.size();

    if(diffSize == 0){
        cout << diffCharCount(a, b);
    }
    else {
        int ans = 100;

        for(int i=0; i<diffSize + 1; i++){

            ans = min(ans, diffCharCount(a, b.substr(i, a.size())));
        }

        cout << ans;
    }
}

//어짜피 추가하는 char는 영향 X
//a 문자열은 어느 위치로든 갈 수 있다.
//abc와 dzabqweab라면 a.size() == 3, b.size() == 9이다.
//따라서 xxxxxabc가 될 수도, xabcxxxxx가 될 수도, xxxxabcxx가 될 수도 있다.
//

// abc topabocder
// topabcoder
// should return 2