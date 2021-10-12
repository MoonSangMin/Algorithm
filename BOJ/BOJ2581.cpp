#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;

    for(int i=2; i<n; i++){
        if(n%i == 0) return false;
    }

    return true;
}

int main(){
    int s, e; //start & end
    int total = 0, minVal = 10001;
    cin >> s >> e;

    for(int i=s; i<=e; i++){
        if(isPrime(i) == true){
            total += i;
            if(minVal > i){
                minVal = i;
            }
        }
    }

    if(minVal == 10001 && total == 0){
        cout << -1;
        return 0;
    }

    cout << total << '\n' << minVal;
}