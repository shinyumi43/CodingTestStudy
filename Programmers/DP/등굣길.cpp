#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define DIV 1000000007

using namespace std;

int map[101][101]; //그래프
bool visited[101][101]; //방문 여부

int dy[] = { 0, 1 }; //이동 방향, 오/아래
int dx[] = { 1, 0 };

long long dp[101][101]; //(최단경로의 수 %  DIV)를 누적

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 0; i < puddles.size(); ++i){
        int y = puddles[i][0];
        int x = puddles[i][1];
        map[y][x] = -1; //물 웅덩이
    }
    
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    visited[1][1] = true;
    dp[1][1] = 1;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y == m && x == n){ break; }
        
        for(int i = 0; i < 2; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 1 || ny > m || nx < 1 || nx > n || map[ny][nx] == -1){
                continue;
            }
            
            dp[ny][nx] += dp[y][x] % DIV; //더해주는 것은 위치마다 전부 누적
            
            if(!visited[ny][nx]){
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
    
    answer = dp[m][n] % DIV;
    return answer;
}

int main(){
    solution(4, 3, {{2,2}});

    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= 10; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}