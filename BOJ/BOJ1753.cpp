#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 20001
#define INF 2147483647

int V, E, start;
int dist[MAX];
vector<pair<int, int> > graph[MAX];
//{ {(b1, c1), (b2, c2)}, {(b3, c3)}, ... }


void Dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    //우선순위 큐를 사용하기 위해 first는 가중치, second는 노드
    dist[start] = 0;

    while(!pq.empty()){
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(dist[curNode] < curDist) continue;

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
    
    cin >> V >> E >> start;

    for(int i=0; i<E; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }

    Dijkstra();

    for(int i=1; i<=V; i++){
        if(dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}