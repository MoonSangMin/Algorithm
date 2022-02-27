#include <iostream>
#include <string>
using namespace std;

int cnt = 0;

char map[8][8] = {
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
    'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
    'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'    
};

char input[8][8];

int main() {
    for(int i=0; i<8; i++){
        string tmp;
        cin >> tmp;

        for(int j=0; j<8; j++){
            input[i][j] = tmp[j];
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(map[i][j] == 'W' && input[i][j] == 'F') cnt++;
        }
    }

    cout << cnt;
}