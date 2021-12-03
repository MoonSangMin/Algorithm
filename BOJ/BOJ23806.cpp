#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n*5; i++){
        for(int j=0; j<n; j++){
            cout << "@";
        }

        if(i < n*1 || i >= n*4){
            for(int j=0; j<n*3; j++){
                cout << "@";
            }
        }
        else{
            for(int j=0; j<n*3; j++){
                cout << " ";
            }
        }

        for(int j=0; j<n; j++){
            cout << "@";
        }
        cout << '\n';
    }
}