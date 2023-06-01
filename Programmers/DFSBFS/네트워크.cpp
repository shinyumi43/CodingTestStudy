#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[200];
vector<int> adj[200];

void dfs(int x){
    visited[x] = true;
    
    for(int i = 0; i < adj[x].size(); ++i){
        int y = adj[x][i];
        if(!visited[y]){
            dfs(y);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < computers.size(); ++i){
        for(int j = 0; j < computers[i].size(); ++j){
            if(i == j){ continue; }
            
            if(computers[i][j] == 1){ adj[i].push_back(j); }
        }
    }
    
    for(int i = 0; i < 200; ++i){ visited[i] = false; }
    
    for(int i = 0; i < n; ++i){
        if(!visited[i]){ dfs(i); answer++; } //방문하지 않은 곳만 탐색
    }
    
    return answer;
}

int main(){
    cout << solution(3, {{1,1,0}, {1,1,0}, {0,0,1}});
    return 0;
}