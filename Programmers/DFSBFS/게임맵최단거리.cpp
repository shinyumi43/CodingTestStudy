#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int answer = 0;
bool visited[100][100];

void bfs(int i, int j, vector<vector<int>> maps, int n, int m){
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 1});
    visited[i][j] = true;
    
    int y, x, depth;
    while(!q.empty()){
        y = q.front().first.first;
        x = q.front().first.second;
        depth = q.front().second;
        q.pop();
        
        if(y == n - 1 && x == m - 1){ //상대 던전에 도착했을 때
            answer = depth;
            return;
        }
        
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1 || maps[ny][nx] == 0) continue;
            
            if(!visited[ny][nx]){
                q.push({{ ny, nx }, depth + 1}); visited[ny][nx] = true;
            }
        }
    }    
    
    if(y != n - 1 || x != m - 1){ answer = -1; }
}

int solution(vector<vector<int>> maps)
{
    bfs(0, 0, maps, maps.size(), maps[0].size());
    return answer;
}

int main(){
    vector<vector<int>> maps = {{1,0,1,1,1},
                                {1,0,1,0,1},
                                {1,0,1,1,1},
                                {1,1,1,0,1},
                                {0,0,0,0,1}
                                };
    cout << solution(maps) << "\n";
    return 0;
}