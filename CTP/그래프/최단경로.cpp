#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 3000001

vector<pair<int, int>> edge[20001];
int dist[20001];
priority_queue<pair<int, int>> pq; //-를 넣어서 넣고 빼는 것이 좋음

void dijkstra(){
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        int weight = -top.first;
        int vertex = top.second;
        pq.pop();
        if(dist[vertex] > weight){
            dist[vertex] = weight;
            for(auto x : edge[vertex]){
                pq.push({-weight-x.first, x.second});
            }
        }
    }
}

int main(){
    for(int i = 0; i < 20001; ++i){ dist[i] = INF; }
    
    int V, E, K;
    cin >> V >> E;
    cin >> K;

    int u, v, w;
    for(int i = 0; i < E; ++i){
        cin >> u >> v >> w;
        edge[u].push_back({w, v}); //반대 정점과 함께 가중치 값을 저장
    }

    pq.push({0, K});
    dijkstra();

    for(int i = 1; i <= V; ++i){
        if(dist[i] == INF){ cout << "INF" << "\n"; }
        else {  cout << dist[i] << "\n"; }
    }

    return 0;
}