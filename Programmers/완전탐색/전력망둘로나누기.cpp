#include <string>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 101

using namespace std;

int cnt;
vector<int> adj[MAX];

void bfs(int a, int b){
    queue<int> q;
    bool visited[MAX];
    
    q.push(a);
    visited[a] = true; //미리 방문 전환
    visited[b] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < adj[x].size(); ++i){
            int y = adj[x][i];
            if(visited[y]){ continue; }
            
            cnt++; //개수를 count
            q.push(y);
            visited[y] = true;
        }    
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    //그래프 생성
    for(int i = 0; i < wires.size(); ++i){ 
        vector<int> wire = wires[i];
        int a = wire[0], b = wire[1];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //BFS 진행
    for(int i = 0; i < wires.size(); ++i){
        vector<int> wire = wires[i];
        int a = wire[0], b = wire[1];
        
        cnt = 1;
        bfs(a, b);
        answer = min(answer, abs(2 * cnt - n));
    }

    return answer;
}