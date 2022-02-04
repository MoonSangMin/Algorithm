#include <iostream>
#include <string>
using namespace std;

int alphabetNum[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                  12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int solution(string name) {
    int answer = 0;
    int shift = name.size() - 1; //커서를 한 방향으로만 이동
    
    for(int i=0; i<name.size(); i++){
        //알파벳 변경 조작 횟수
        int tmp = int(name[i]-'A');
        answer += alphabetNum[tmp];
        
        //커서 변경 조작 횟수
        if(i==0) continue;
        if(name[i] == 'A') {
            tmp = i;
            while(tmp < name.size() && name[tmp] == 'A') tmp++;
            
            int left = i - 1;
            int right = name.size() - tmp;
            shift = min(shift, left + right + min(left, right));
        }
    }
    
    answer += shift;
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        cout << solution(tmp) << '\n';
    }
}