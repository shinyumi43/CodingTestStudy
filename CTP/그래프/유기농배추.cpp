#include <iostream>
#include <vector>
using namespace std;

int farm[50][50];
bool visited[50][50];
vector<int> adj[50];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main(){
    int T, M, N, K;
    cin >> T;
    cin >> M >> N >> K;

    int y, x;
    while(K--){
        cin >> y >> x;
        farm[y][x] = 1;
        visited[y][x] = true;

        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(farm[ny][nx] == 1 && !visited[ny][nx]){
                adj[ny].push_back(nx);
                adj[nx].push_back(ny);
                visited[ny][nx] = true;
            }   
        }
    }

    for(int y = 0; y < 50; ++y){
        for(int x = 0; x < 50; ++x){
            visited[y][x] = false;
        }
    }

    return 0;
}