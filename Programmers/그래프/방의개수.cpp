#include <string>
#include <vector>
#include <map>

using namespace std;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int solution(vector<int> arrows) {
    map<pair<int, int>, bool> visit_nodes; //방문한 노드
    map<pair<pair<int, int>, pair<int, int>>, bool> visit_edges; //방문한 간선
    
    int answer = 0;
    int y = 0, x = 0;
    visit_nodes[{y, x}] = true;
    for(int i = 0; i < arrows.size(); ++i){
        int dir = arrows[i];
        for(int j = 0; j < 2; ++j){ //2번씩 반복해서 확대
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            //방문한 정점을 다시 방문하지만, 새로운 간선을 지나서 방문한 경우
            if(visit_nodes[{ny, nx}] && !visit_edges[{{ y, x }, { ny, nx }}]){
                visit_edges[{{ y, x }, { ny, nx }}] = true;
                visit_edges[{{ ny, nx }, { y, x }}] = true;
                answer++; //방이 하나 생김
                y = ny; x = nx; //위치를 변경
            }
            else{
                visit_nodes[{ ny, nx }] = true;
                visit_edges[{{ y, x }, { ny, nx }}] = true;
                visit_edges[{{ ny, nx }, { y, x }}] = true;
                y = ny; x = nx; //위치를 변경
            }   
        }
    }
    return answer;
}