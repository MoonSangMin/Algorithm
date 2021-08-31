#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int arr[], int low, int high, int target){
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return 1;

        if(arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    return 0;
}

int main(){
    int n;
    int arr[100001];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr + 0, arr + n);

    int t;
    cin >> t;
    int testArr[100001];
    for(int i=0;i<t;i++){
        cin >> testArr[i];
        cout << BinarySearch(arr, 0, n - 1, testArr[i]) << '\n';
    }
}