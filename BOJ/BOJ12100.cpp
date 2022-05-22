#include <iostream>
#include <vector>
using namespace std;

int n, answer = -1;

vector<vector<int> > right(vector<vector<int> > tmp){
    vector<vector<bool> > alreadyCombined(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        for(int j=n-2; j>=0; j--){
            if(tmp[i][j] == 0) continue;
            
            for(int k=j; k<n-1; k++){
                if(tmp[i][k] == tmp[i][k+1] && !alreadyCombined[i][k+1]){
                    tmp[i][k+1] *= 2;
                    tmp[i][k] = 0;
                    alreadyCombined[i][k+1] = true;
                    break;
                }
                else if(tmp[i][k+1] == 0){
                    tmp[i][k+1] = tmp[i][k];
                    tmp[i][k] = 0;
                }
                else break;
            }
        }
    }

    return tmp;
}

vector<vector<int> > left(vector<vector<int> > tmp){
    vector<vector<bool> > alreadyCombined(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(tmp[i][j] == 0) continue;
            
            for(int k=j; k>0; k--){
                if(tmp[i][k] == tmp[i][k-1] && !alreadyCombined[i][k-1]){
                    tmp[i][k-1] *= 2;
                    tmp[i][k] = 0;
                    alreadyCombined[i][k-1] = true;
                    break;
                }
                else if(tmp[i][k-1] == 0){
                    tmp[i][k-1] = tmp[i][k];
                    tmp[i][k] = 0;
                }
                else break;
            }
        }
    }

    return tmp;
}

vector<vector<int> > up(vector<vector<int> > tmp){
    vector<vector<bool> > alreadyCombined(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(tmp[j][i] == 0) continue;
            
            for(int k=j; k>0; k--){
                if(tmp[k][i] == tmp[k-1][i] && !alreadyCombined[k-1][i]){
                    tmp[k-1][i] *= 2;
                    tmp[k][i] = 0;
                    alreadyCombined[k-1][i] = true;
                    break;
                }
                else if(tmp[k-1][i] == 0){
                    tmp[k-1][i] = tmp[k][i];
                    tmp[k][i] = 0;
                }
                else break;
            }
        }
    }

    return tmp;
}

vector<vector<int> > down(vector<vector<int> > tmp){
    vector<vector<bool> > alreadyCombined(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        for(int j=n-2; j>=0; j--){
            if(tmp[j][i] == 0) continue;
            
            for(int k=j; k<n-1; k++){
                if(tmp[k][i] == tmp[k+1][i] && !alreadyCombined[k+1][i]){
                    tmp[k+1][i] *= 2;
                    tmp[k][i] = 0;
                    alreadyCombined[k+1][i] = true;
                    break;
                }
                else if(tmp[k+1][i] == 0){
                    tmp[k+1][i] = tmp[k][i];
                    tmp[k][i] = 0;
                }
                else break;
            }
        }
    }

    return tmp;
}

void DFS(vector<vector<int> > tmp, int cnt){
    if(cnt == 5){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(answer < tmp[i][j]) answer = tmp[i][j];
            }
        }

        return;
    }

    DFS(up(tmp), cnt + 1);
    DFS(down(tmp), cnt + 1);
    DFS(right(tmp), cnt + 1);
    DFS(left(tmp), cnt + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    vector<vector<int> > arr;

    cin >> n;
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<n; j++){
            int input;
            cin >> input;
            v.push_back(input);
        }
        arr.push_back(v);
    }

    DFS(arr, 0);
    cout << answer;
}

//1. (y, x) == (ny, nx)면 합치고 (ny, nx) *= 2, (y, x) = 0
//2. 그림 14에서 위쪽으로 이동하면 (0, 0)이 4가 되고 나머지는 위로 밀린다
//2. 그림 14에서 아래쪽으로 이동하면 (3, 0)이 4가 되고 나머지는 아래로 밀린다