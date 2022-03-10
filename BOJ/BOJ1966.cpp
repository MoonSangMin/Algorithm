#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int> pq;
    
    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
    }
    
    int i = 0;
    while(true) {
        if(i == location) {
            if(pq.top() == priorities[i]) return answer;
            else location = priorities.size();
        }
        
        if(pq.top() == priorities[i]) {
            pq.pop();
            answer++;
        }
        else {
            priorities.push_back(priorities[i]);
        }
        
        i++;
    }
}

int main() {
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int n, location; //문서의 개수 n, 본인이 프린트 요청한 위치 location
        vector<int> v;
        cin >> n >> location;

        for(int j=0; j<n; j++){
            int tmp;

            cin >> tmp;
            v.push_back(tmp);
        }

       cout << solution(v, location) << '\n';
    }
}