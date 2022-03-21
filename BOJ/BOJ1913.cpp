#include <iostream>
using namespace std;

int arr[1000][1000];

int main(){
    int n, m;
    cin >> n >> m;

    int y = 0, x = 0, r = 0;
    bool goDown = true, goRight = false, goUp = false, goLeft = false;
    
    for(int i=n*n; i>0; i--){
        arr[y][x] = i;

        if(goDown){
            y++;
            if(y >= n - r){
                y--;
                x++;
                goDown = false;
                goRight = true;
            }
        }
        else if(goRight){
            x++;
            if(x >= n - r){
                x--;
                y--;
                goRight = false;
                goUp = true;
            }
        }
        else if(goUp){
            y--;
            if(y < r){
                y++;
                x--;
                r++;
                goUp = false;
                goLeft = true;
            }
        }
        else if(goLeft) {
            x--;
            if(x < r){
                x++;
                y++;
                goLeft = false;
                goDown = true;
            }
        }
    }

    int ansY, ansX;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << ' ';
            if(arr[i][j] == m){
                ansY = i;
                ansX = j;
            }
        }
        cout << '\n';
    }

    cout << ansY + 1 << ' ' << ansX + 1;
}