#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visiteddfs[1001];
bool visitedbfs[1001];

vector<int> adj[1001];

void dfs(int start){
    visiteddfs[start] = true;
    cout << start << ' ';

    sort(adj[start].begin(), adj[start].end());
    for(int i = 0; i < adj[start].size(); ++i){
        int next = adj[start][i];
        if(!visiteddfs[next]){ dfs(next); }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visitedbfs[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << ' ';
        
        sort(adj[node].begin(), adj[node].end());
        for(int i = 0; i < adj[node].size(); ++i){
            int next = adj[node][i];
            if(!visitedbfs[next]){
                q.push(next);
                visitedbfs[next] = true;
            }
        }
    }
}

int main(){
    int N, M, V;
    cin >> N >> M >> V;
    
    int a, b;
    for(int i = 0; i < M; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(V);
    cout << "\n";
    bfs(V);

    return 0;
}