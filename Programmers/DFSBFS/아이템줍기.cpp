#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

char map[101][101];
bool visited[101][101];

void draw(int y1, int x1, int y2, int x2){
    for(int i = y1; i <= y2; ++i){
        for(int j = x1; j <= x2; ++j){
            if(map[i][j] == '1'){ continue; }
            map[i][j] = '1';
            
            if(i == y1 || i == y2 || j == x1 || j == x2){ map[i][j] = '2'; }
        }
    }
}

int bfs(int charY, int charX, int findY, int findX){
    queue<pair<pair<int, int>, int>> q;
    q.push({{charY, charX}, 0});
    visited[charY][charX] = true;
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        
        if(y == findY && x == findX) { return dis / 2; }
        
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny > 101 || nx < 0 || nx > 101 || map[ny][nx] != '2') { continue; }
            
            if(!visited[ny][nx]){
                q.push({{ ny, nx }, dis + 1});
                visited[ny][nx] = true;
            }
        }
    }
    
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    memset(map, '0', sizeof(map));
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i < rectangle.size(); ++i){
        int y1 = rectangle[i][1]; //좌측 하단 y
        int x1 = rectangle[i][0]; //좌측 하단 x
        int y2 = rectangle[i][3]; //우측 상단 y
        int x2 = rectangle[i][2]; //우측 상단 x
        draw(y1 * 2, x1 * 2, y2 * 2, x2 * 2); //그리기
    }
    
    return bfs(characterY * 2, characterX * 2, itemY * 2, itemX * 2);
}

int main(){
    cout << solution({{1,1,5,7}}, 1, 1, 4, 7) << "\n";
    return 0;
}