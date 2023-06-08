#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int roads[51][51];
int dp[51]; //해당 vertex에 도착하는 최소 시간 저장 - K 이하의 vertex만을 print

void dijkstra(int start, int N){
    dp[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int cur = pq.top().second;
        int t = pq.top().first;

        pq.pop();
        if(dp[cur] < t){ continue; }

        for(int i = 0; i <= N; ++i){
            if(roads[cur][i] != 0){
                int next = i;
                int nt = t + roads[cur][i];
                if(dp[next] > nt){
                    dp[next] = nt;
                    pq.push({nt, next});
                }
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 0; i < road.size(); ++i){
        int a = road[i][0], b = road[i][1], c = road[i][2];
        if(roads[a][b] == 0){
            roads[a][b] = c;
            roads[b][a] = c;
        }
        else{
            roads[a][b] = min(roads[a][b], c);
            roads[b][a] = min(roads[b][a], c);
        }
    }

    for(int i = 0; i < 51; ++i){
        dp[i] = 987654321;
    }
    dijkstra(1, N);

    for(int i = 1; i <= N; ++i){
        if(dp[i] <= K){ answer++; }
    }

    return answer;
}













// #include <iostream>
// #include <vector>
// using namespace std;

// const int INF = 100000000;
// bool visited[51] = { false };
// vector<int> adj[51];
// int dist[51][51];

// void dfs(int x, int K, int prev){
//     for(int i = 0; i < adj[x].size(); ++i){
//         int y = adj[x][i], dis = dist[x][y];
    
//         if(dis + prev > K) continue;
//         if(visited[y] && dist[x][y] <= dis + prev) continue;
//         visited[y] = true;
//         dfs(y, K, dis + prev); 
//     }
// }

// int solution(int N, vector<vector<int>> road, int K) {
//     int answer = 0;

//     //initialize
//     for(int i = 1; i <= N; ++i){
//         for(int j = 1; j <= N; ++j){
//             dist[i][j] = INF;
//         }
//     }

//     for(int i = 0; i < road.size(); ++i){
//         vector<int> v = road[i];
//         int a = v[0], b = v[1], w = v[2];
//         if(dist[a][b] == INF && dist[b][a] == INF){
//             adj[a].push_back(b); adj[b].push_back(a); //delete duplicate
//         }
//         dist[a][b] = min(dist[a][b], w); //save minimum
//         dist[b][a] = min(dist[b][a], w);
//     }
    
//     visited[1] = true;
//     dfs(1, K, 0);
//     for(int i = 1; i <= N; ++i){
//         if(visited[i]) answer++;
//     }

//     // 그래프가 연결되어 있지 않은 경우
//     if(answer == 0) return 0;
    
//     // 1번 노드만 방문 가능한 경우
//     if(answer == 1) return 1;

//     return answer;
// }

// int main(){
//     cout << solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3) << endl;
// 	cout << solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} }, 4);
//     return 0;
// }