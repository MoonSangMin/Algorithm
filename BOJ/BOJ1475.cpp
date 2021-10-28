#include <iostream>
#include <cmath>
using namespace std;

double arr[10] = {0,};

int main(){
    int n;
    cin >> n;

    while(n > 0){
        int tmp = n%10;
        arr[tmp]++;
        n/=10;
    }

    arr[6] = ceil((arr[6] + arr[9]) / 2);
    arr[9] = arr[6];

    cout << *max_element(arr+0, arr+10);
}


// 11699923 -> 2