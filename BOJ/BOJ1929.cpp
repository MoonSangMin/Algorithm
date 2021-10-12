#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int s, e;
    int nums[1000001];
    cin >> s >> e;

    for(int i=2; i<=MAX; i++){
        nums[i] = i;
    }

    for(int i=2; i<=sqrt(MAX); i++){//j for문에서 i의 제곱부터 배수를 지우므로
    //범위의 제곱근까지만 구하면 된다.
        if(nums[i] == 0) continue;

        for(int j = i * i; j<=MAX; j+=i){
            if(nums[i] == 0) continue;

            nums[j] = 0;
        }//소수인 i는 냅두고 i의 배수를 모두 지운다.
        //2라면 4부터 6, 8 .. 을 지우고 3이라면 9부터 12, 15, ..
    }

    for(int i=s; i<=e; i++){
        if(nums[i] != 0){
            cout << nums[i] << '\n';
        }
    }
}