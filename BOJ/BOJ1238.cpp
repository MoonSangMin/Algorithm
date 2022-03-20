#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 1001
#define INF 2147483647

int n, m, x; //n명의 학생(정점), m개의 도로(간선), x번 마을에 모여서 파티
vector<pair<int, int> > graph[MAX];
int dist[MAX];
int distForX[MAX];

void Dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    //우선순위 큐를 사용하기 위해 first는 가중치, second는 노드
    dist[start] = 0;

    while(!pq.empty()){
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].first;
            int nextDist = graph[curNode][i].second;
            
            if(dist[nextNode] > curDist + nextDist){
                dist[nextNode] = curDist + nextDist;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> x;

    for(int i=0; i<m; i++){
        int a, b, c; //시작점, 끝점, 가중치
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }

    Dijkstra(x);
    for(int i=1; i<=n; i++){
        distForX[i] = dist[i];
        dist[i] = INF;
    }


    vector<int> candidates;
    
    for(int i=1; i<=n; i++){
        int tmp = 0;
        Dijkstra(i);

        tmp += dist[x];
        tmp += distForX[i];

        for(int j=1; j<=n; j++){
            dist[j] = INF;
        }

        candidates.push_back(tmp);
    }

    cout << *max_element(candidates.begin(), candidates.end());
}