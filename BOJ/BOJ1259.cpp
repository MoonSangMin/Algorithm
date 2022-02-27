#include <iostream>
#include <string>
using namespace std;

int main(){
    while(true) {
        int n;
        cin >> n;
        if(n == 0) return 0;

        char arr[10];
        int i = 0, sizeOfNum = 0, originN = n;

        while(n > 0) {
            arr[i] = char((n % 10) + '0');
            n /= 10;
            sizeOfNum++;
            i++;
        }

        string tmp = "";
        for(int i=0; i<sizeOfNum; i++){
            tmp += arr[i];
        }
        
        if(stoi(tmp) == originN){
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}