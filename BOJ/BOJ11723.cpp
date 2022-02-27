#include <iostream>
#include <string>
using namespace std;
int arr[21] = { 0, };

void add(int x) {
    arr[x] = 1;
}

void remove(int x){
    arr[x] = 0;
}

void check(int x){
    if(arr[x] == 1){
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

void toggle(int x){
    if(arr[x] == 1) {
        arr[x] = 0;
    }
    else {
        arr[x] = 1;
    }
}

void clear(){
    for(int i=1; i<=20; i++){
        arr[i] = 0;
    }
}

void all(){
    for(int i=1; i<=20; i++){
        arr[i] = 1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;

        if(str == "all" || str == "empty"){
            if(str == "all"){
                all();
            }
            else{
                clear();
            }
        }
        else {
            int x;
            cin >> x;
            if(str == "add") add(x);
            else if(str == "check") check(x);
            else if(str == "remove") remove(x);
            else if(str == "toggle") toggle(x);
        }
    }
}