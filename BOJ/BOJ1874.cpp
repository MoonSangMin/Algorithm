#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;
    vector<char> ans;
    vector<int> v;
    bool flag = false; //만들 수 없을 시 true

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int cur = 1, idx = 0;
    while(idx < n){
        if(cur > n + 1){
            flag = true;
            break;
        }

        while(v[idx] >= cur){
            st.push(cur++);
            ans.push_back('+');
        }

        if(!st.empty()){
            if(st.top() == v[idx]){
                st.pop();
                ans.push_back('-');
            }
            else {
                flag = true;
                break;
            }
        }
        else {
            flag = true;
            break;
        }

        idx++;
    }


    if(flag){
        cout << "NO";
    }
    else {
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << '\n';
        }
    }
}

//v에는 우리가 만들고자하는 숫자가 순서대로 있다.
//예를 들어 [4, 3, 6, 8, 7, 5, 2, 1]

//스택을 통해 순서대로 만들려면
//v의 idx를 0부터 늘려가며 v[idx]의 수를 만들어 스택에 push해야 한다.

//stack의 변화 상황
//[1, 2, 3, 4] -> 4 pop
//[1, 2, 3] -> 3 pop
//[1, 2, 5, 6] -> 6 pop
//[1, 2, 5, 7, 8] -> 8 pop
//[1, 2, 5, 7] -> 7, 5, 2, 1 순으로 pop

//[1] -> 1 pop
//[2] -> 2 pop
//[3, 4, 5] -> 5 pop
//[3, 4] -> 4, 3 pop
// 4 fail

//알고리즘
//1. 현재 인덱스의 숫자까지 값(cur)을 늘려준다.
//2. 늘렸다면, 스택의 top값은 현재 인덱스의 숫자와 같을 것이고, 이를 pop한다.
//3. 다음 인덱스로 넘어가서 같은 작업을 반복한다.
//4. 만약 이 과정에서 top값이 현재 인덱스의 숫자와 같지 않거나
//   스택이 비어있다면 불가능한 경우이므로 NO를 출력한다.


//테스트케이스
//n=1, v=[1] -> 출력 { '+', '-' }