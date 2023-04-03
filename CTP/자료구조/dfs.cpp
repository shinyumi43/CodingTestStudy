#include <bits/stdc++.h>
using namespace std;

//index 0은 사용하지 않기에 배열 하나 추가
bool visited[9];
//한 노드에 연결된 노드 표현 가능
vector<int> graph[9];

void dfs(int x){
    visited[x] = true; //방문 표시
    cout << x << " ";
    for(int i = 0; i < graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

int main(){
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);

    return 0;
}