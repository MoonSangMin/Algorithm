#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, maxVal = -2e9, minVal = 2e9;
vector<int> nums;
int opers[4]; //덧셈, 뺄셈, 곱셈, 나눗셈 순서

void DFS(int sum, int idx){
    if(idx == n){ //모든 수를 다 거쳤으면 최솟값, 최댓값 갱신
        maxVal = max(sum, maxVal);
        minVal = min(sum, minVal);
        return;
    }
    
    for(int i=0; i<4; i++){
        if(opers[i] == 0) continue; //사용할 수 있는 연산자가 없다면 건너뛰기
        opers[i]--;

        if(i == 0){
            DFS(sum + nums[idx], idx+1);
        }
        else if(i == 1){
            DFS(sum - nums[idx], idx+1);
        }
        else if(i == 2){
            DFS(sum * nums[idx], idx+1);
        }
        else if(i == 3 && nums[idx] != 0){
            DFS(sum / nums[idx], idx+1);
        }

        opers[i]++; //다른 DFS 함수에서 사용할 수 있도록 다시 증가시켜줘야함
    }
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    } //숫자 입력받음

    for(int i=0; i<4; i++){
        int tmp;
        cin >> tmp;
        opers[i] = tmp;
    } //각 연산자의 개수 입력받음

    DFS(nums[0], 1); //sum에 nums[0]을 더한 상태로 idx 1부터 시작

    cout << maxVal << '\n' << minVal;
}